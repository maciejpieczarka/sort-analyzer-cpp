#include "../headers/AlgorithmComparison.h"

#include <iostream> //Wyjscie / wejscie
#include <iomanip> //Manipulatory strumienia
#include <chrono> // Mierzenie czasu wykonywania algorytmow
#include <random> // Generacja liczb pseudolosowych
#include <filesystem>

void AlgorithmComparison::addAlgorithm(std::unique_ptr<SortAlgorithm> algorithm) {
	algorithms.push_back(std::move(algorithm));
};

void AlgorithmComparison::compareData(const std::vector<int>& data) {
	std::cout << std::setw(20) << "Algorithm" << std::setw(15) << "Time (ms)\n";
	std::cout << std::string(35, '-') << std::endl;

	for (const std::unique_ptr<SortAlgorithm>& algorithm : algorithms) {
		std::vector<int> kopiaTablicy = data;

		auto start = std::chrono::high_resolution_clock::now();
		algorithm->sort(kopiaTablicy);//Lub (*algorithm).sort(...)
		auto end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double, std::milli> duration = end - start;

		std::cout << std::setw(20) << algorithm->getName()
			<< std::setw(15) << duration.count() << "\n";
	}
};

std::vector<int> AlgorithmComparison::generateDataset(size_t dataSize, int min, int max) {
	std::vector<int> data(dataSize);


	/*
		Do generowania liczb pseudolosowych wykorzystuje biblioteke <random>,
		ktora jest nowsza bardziej precyzyjna i bezpieczniejsza niz funkcje z biblioteki <cstdlib>.
		Generatory liczb pseudolosowych z biblioteki <random> sa bardziej wydajne i maja lepsze wlasciwosci statystyczne.
		Jednak daloby sie rowniez uzyskac podobny efekt z wykorzystaniem funkcji rand() z biblioteki <cstdlib>.
	*/


	std::random_device rd; //Wygenerowanie "ziarna" do generatora liczb pseudolosowych
	std::mt19937 gen(rd()); //Utworzenie generatora liczb pseudolosowych z wykorzystaniem algorytmu Mersenne Twister
	std::uniform_int_distribution<int> rozklad(min, max); //Utworzenie rozkladu jednostajnego liczb calkowitych w zakreesie min - max

	//Petla, ktora wypelnia tablice liczbami pseudolosowymi
	for (size_t i = 0; i < dataSize; ++i) {
		data[i] = rozklad(gen);
	}

	return data;
};

std::vector<int> AlgorithmComparison::uploadFileDataset(std::string fileName) {
	std::ifstream file(fileName); //Otworzenie pliku do odczytu danych

	std::vector<int> data; //Utworzenie tablicy dynamicznej, ktora bedzie przechowywac dane z pliku

	if (file.good() == true) { //Sprawdzenie czy plik zostal otworzony poprawnie
		int number{}; //Zmienna pomocnicza do przechowywania liczb z pliku
		while (file >> number) { //Petla, ktora wczytuje liczby z pliku
			data.push_back(number); //Dodanie liczby do tablicy
		}
		file.close(); //Zamkniecie pliku
	}
	else {
		std::cout << "Blad otwarcia pliku: " << fileName << ". Sprawdz czy podana sciezka jest wlasciwa." << std::endl;
	}
	return data;
};

void AlgorithmComparison::generateFileDataset(std::string fileName, size_t dataSize, int min, int max) {
	std::ofstream file("./data/" + fileName); //Otworzenie pliku do zapisu danych
	if (file.good() == true) { //Sprawdzenie czy plik zostal otworzony poprawnie
		std::vector<int> data = generateDataset(dataSize, min, max); //Wygenerowanie danych
		for (const int& number : data) { //Petla, ktora zapisuje dane do pliku
			file << number << " ";
		}
		file.close(); //Zamkniecie pliku
	}
	else {
		std::cout << "Blad otwarcia pliku: " << fileName << ". Sprawdz czy podana sciezka jest wlasciwa." << std::endl;
	}
}

