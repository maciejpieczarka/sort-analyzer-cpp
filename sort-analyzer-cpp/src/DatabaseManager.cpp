#include "../headers/DatabaseManager.h"
#include <iostream>
#include <sstream>

sqlite3* DatabaseManager::m_db = nullptr;
const char* DatabaseManager::m_dbPath = "";

DatabaseManager::DatabaseManager(const char* dbPath){
	m_dbPath = dbPath;
	checkConn();
	createTableSQL();
}

// Destruktor - zamyka polaczenie z baza
DatabaseManager::~DatabaseManager() {
	if (m_db) {
		sqlite3_close(m_db);
		m_db = nullptr;
	}
}

//Polaczenie z baza
void DatabaseManager::checkConn() {
	if (sqlite3_open(m_dbPath, &m_db) != SQLITE_OK) {
		std::cerr << "Blad otwarcia bazy: " << sqlite3_errmsg(m_db) << "\n";
		m_db = nullptr;
	}
}

//Tworzenie tabeli Wyniki
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
	)";
	executeQuery(query);
}

//Wykonywanie zapytan
void DatabaseManager::executeQuery(const std::string& query) {
	char* errorMsg;
	int rc = sqlite3_exec(m_db, query.c_str(), nullptr, nullptr, &errorMsg);

	if (rc != SQLITE_OK) {
		std::cerr << "Blad SQL: " << errorMsg << "\n";
		sqlite3_free(errorMsg);
	}
}

void DatabaseManager::saveResult(const std::string& algorithmName, int dataCount, double time, const std::string& timeComplexity, const std::string& spaceComplexity) {
	std::stringstream ss;
	ss << "INSERT INTO Wyniki (AlgorithmName, DataCount, TimeMS, TimeComplexity, SpaceComplexity) VALUES ("
		<< "'" << algorithmName << "',"
		<< dataCount << ", "
		<< time << ", "
		<< "'" << timeComplexity << "', "
		<< "'" << spaceComplexity << "');";

	executeQuery(ss.str());
}
