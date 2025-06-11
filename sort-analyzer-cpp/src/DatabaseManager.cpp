#include "../headers/DatabaseManager.h"
#include <iostream>
#include <sstream>

// Inicjalizacja statycznych zmiennych klasy DatabaseManager
sqlite3* DatabaseManager::m_db = nullptr; // Wskaznik do bazy danych, domyslnie nullptr (reprezentuje polaczenie z baza danych)
const char* DatabaseManager::m_dbPath = ""; // Sciezka do bazy danych, domyslnie pusta

// Konstruktor - inicjalizuje sciezke do bazy i tworzy tabele
DatabaseManager::DatabaseManager(const char* dbPath){
	m_dbPath = dbPath;
	checkConn();
	createTableSQL();
}

// Destruktor - zamyka polaczenie z baza danych
DatabaseManager::~DatabaseManager() {
	if (m_db) {
		sqlite3_close(m_db);
		m_db = nullptr;
	}
}

// Otwiera polaczenie z baza danych; w przypadku bledu ustawia m_db na nullptr
void DatabaseManager::checkConn() {
	if (sqlite3_open(m_dbPath, &m_db) != SQLITE_OK) {
		std::cerr << "Blad otwarcia bazy: " << sqlite3_errmsg(m_db) << "\n";
		m_db = nullptr;
	} 
}

// Tworzy tabele w bazie danych, jesli nie istnieje
void DatabaseManager::createTableSQL() {
	const std::string query = R"( 
		CREATE TABLE IF NOT EXISTS Wyniki (
		ID INTEGER PRIMARY KEY AUTOINCREMENT,
		AlgorithmName TEXT,
		DataCount INTEGER,
		TimeMS REAL,
		TimeComplexity TEXT,
		SpaceComplexity TEXT,
		CreatedAt DATETIME DEFAULT CURRENT_TIMESTAMP
		)
	)"; // Zapytanie SQL do tworzenia tabeli Wyniki

	executeQuery(query); // Wykonuje zapytanie tworzenia tabeli
}

// Wykonuje zapytanie SQL na bazie danych
void DatabaseManager::executeQuery(const std::string& query) {
	char* errorMsg;
	int rc = sqlite3_exec(m_db, query.c_str(), nullptr, nullptr, &errorMsg); // Wykonuje zapytanie SQL na bazie danych i ustawia komunikat bledu, jesli wyst¹pi problem

	if (rc != SQLITE_OK) { // Sprawdza, czy zapytanie zostalo wykonane poprawnie
		std::cerr << "Blad SQL: " << errorMsg << "\n";
		sqlite3_free(errorMsg); // Zwolnienie pamieci zajmowanej przez komunikat bledu
	}
}

void DatabaseManager::saveResult(const std::string& algorithmName, int dataCount, double time, const std::string& timeComplexity, const std::string& spaceComplexity) {
	std::stringstream ss;
	// Tworzy zapytanie SQL do wstawienia wynikow algorytmu do tabeli Wyniki
	ss << "INSERT INTO Wyniki (AlgorithmName, DataCount, TimeMS, TimeComplexity, SpaceComplexity) VALUES ("
		<< "'" << algorithmName << "',"
		<< dataCount << ", "
		<< time << ", "
		<< "'" << timeComplexity << "', "
		<< "'" << spaceComplexity << "');";

	executeQuery(ss.str()); // Wykonuje zapytanie wstawiajace wyniki do tabeli Wyniki
}
