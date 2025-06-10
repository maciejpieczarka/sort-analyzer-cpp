#pragma once
#include <string>
#include "../external/sqlite/sqlite3.h"

class DatabaseManager {
protected:
	static const char* m_dbPath;
	static sqlite3* m_db;

	//Wykonuje zapytanie - zapis do bazy danych
	void executeQuery(const std::string& query);
	//Otwiera polaczenie z baza
	static void checkConn();
	//Tworzy tabele (jesli nie istnieje)
	void createTableSQL();

public:
	static bool addToDB;
	//Deklaracja konstruktora
	DatabaseManager(const char* dbPath);

	//Deklaracja destruktora
	~DatabaseManager();

	//Zapisuje dane do przeslania przez zapytanie
	void saveResult(const std::string& algorithmName, int dataCount, double time, const std::string& timeComplexity, const std::string& spaceComplexity);


};