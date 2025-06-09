#pragma once
#include <string>
#include "../external/sqlite/sqlite3.h"

class DatabaseManager {
public:
	bool addToDB = false;
	//Deklaracja konstruktora
	DatabaseManager(const std::string& dbPath);

	//Deklaracja dekonstruktora
	~DatabaseManager();

	//Zapisuje dane do przeslania przez zapytanie
	void saveResult(const std::string& algorithmName, int dataCount, double time, const std::string& timeComplexity, const std::string& spaceComplexity);

private:
	//Wykonuje zapytanie - zapis do bazy danych
	void executeQuery(const std::string& query);
	//Otwiera polaczenie z baza
	void checkConn();
	//Tworzy tabele (jesli nie istnieje)
	void createTableSQL();

	std::string dbPath;
	sqlite3* db = nullptr;

};