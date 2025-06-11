#pragma once
#include <string>
#include "../external/sqlite/sqlite3.h"

class DatabaseManager {
protected:
	// Sciezka do bazy danych
	static const char* m_dbPath;
	// Wskaznik do bazy danych SQLite
	static sqlite3* m_db;

	// Wykonuje zapytanie SQL i zwraca wynik
	void executeQuery(const std::string& query);

	// Sprawdza i nawiazuje polaczenie z baza danych
	static void checkConn();

	// Tworzy tabele w bazie danych, jesli nie istnieje
	void createTableSQL(); 

public:
	// Flaga okreslajaca, czy zapisywac wyniki do bazy danych
	static bool addToDB;

	// Konstruktor - inicjalizuje polaczenie i tworzy tabele
	DatabaseManager(const char* dbPath);

	// Deklaracja - zamyka polaczenie z baza danych
	~DatabaseManager();

	// Zapisuje wynik dzialania algorytmu do tabeli Wyniki
	void saveResult(const std::string& algorithmName, int dataCount, double time, const std::string& timeComplexity, const std::string& spaceComplexity);
};