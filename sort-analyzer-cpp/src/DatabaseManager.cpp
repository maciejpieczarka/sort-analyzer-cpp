#include "../headers/DatabaseManager.h"
#include <iostream>
#include <sstream>

DatabaseManager::DatabaseManager(const std::string& dbPath) : dbPath(dbPath) {
	checkConn();
	createTableSQL();
}

// Destruktor - zamyka polaczenie z baza
DatabaseManager::~DatabaseManager() {
	if (db) {
		sqlite3_close(db);
		db = nullptr;
	}
}

//Polaczenie z baza
void DatabaseManager::checkConn() {
	if (sqlite3_open(dbPath.c_str(), &db) != SQLITE_OK) {
		std::cerr << "Blad otwarcia bazy: " << sqlite3_errmsg(db) << "\n";
		db = nullptr;
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
		);"
	)";
	executeQuery(query);
}

//Wykonywanie zapytan
void DatabaseManager::executeQuery(const std::string& query) {
	char* errorMsg = nullptr;
	int rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errorMsg);

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
