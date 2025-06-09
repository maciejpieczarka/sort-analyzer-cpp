#pragma once

#include "SortAlgorithm.h"
#include "DatabaseManager.h"
#include <vector>
#include <memory> //Biblioteka do inteligentnych wskaznikow
#include <fstream>

class AlgorithmComparison {
private:
	// Dynamiczna tablica przechowujaca algorytmy, ktore beda porownywane
	//
	// Tablica przyjmuje inteligentny wskaznik "unique_ptr" do obiektu klasy,
	// gdyz obiekt nie bedzie kopiowany, a inteligentny wskaznik ulatwia zarzadzanie pamiecia.
	std::vector<std::unique_ptr<SortAlgorithm>> algorithms;
	
	//wskaznik do DatabaseManager
	DatabaseManager* dbManager = nullptr;

public:
	// Metoda, ktora odpowiada za dodawanie algorytmu do 
	// tablicy "algorithms".
	// 
	// Metoda przyjmuje inteligentny wskaznik "unique_ptr" do obiektu klasy,
	// gdyz obiekt nie bedzie kopiowany, a inteligentny wskaznik ulatwia zarzadzanie pamiecia.
	void addAlgorithm(std::unique_ptr<SortAlgorithm> algorithm);

	// Metoda odpowiadajaca za porównywanie algorytmów na tym samym
	// zestawie danych.
	// W tym wypadku porównanie zachodzi na liczbach
	void compareData(const std::vector<double>& data);

	// TODO: Metoda do porywnywania nie na liczbach

	static std::vector<double> generateDataset(int dataSize, double min = -1e6, double max = 1e6);

	static std::vector<double> uploadFileDataset(std::string fileName);

	static void generateFileDataset(std::string fileName, int dataSize, double min = -1e6, double max = 1e6);

	void setDatabaseManager(DatabaseManager* db) { dbManager = db; }
};