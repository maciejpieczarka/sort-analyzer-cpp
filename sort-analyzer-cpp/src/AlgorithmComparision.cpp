#include "../headers/AlgorithmComparison.h"

#include <iostream> //Wyjscie / wejscie
#include <iomanip> //Manipulatory strumienia
#include <chrono> // Mierzenie czasu wykonywania algorytmow
#include <random> // Generacja liczb pseudolosowych
#include <filesystem>

#include "../headers/ConsoleUtils.h"

void AlgorithmComparison::addAlgorithm(std::unique_ptr<SortAlgorithm> algorithm) {
	algorithms.push_back(std::move(algorithm));
};

//Implementacja metody porownujacej algorytmy na tych samych danych
void AlgorithmComparison::compareData(const std::vector<double>& data) {
	std::ofstream wyniki("../data/wyniki.txt", std::ios::out);
	double bestTime{};
	std::string bestAlgorithm;
	std::cout << std::string(88, '=') << "\n";
	std::cout << std::setw(50) << "Sort-Analyzer" << std::string(38, ' ') << "\n";
	std::cout << std::string(88, '=') << "\n";

	std::cout << std::string(88, '-') << std::endl;
	std::cout << std::setw(18) << "Algorytm |" 
			  << std::setw(25) << " Czas Wykonywania (ms) |" 
			  << std::setw(20) << " Zlozonosc Czasowa |"
			  << std::setw(25) << " Zlozonosc Pamieciowa |\n";
	std::cout << std::string(88, '-') << std::endl;

	for (const std::unique_ptr<SortAlgorithm>& algorithm : algorithms) {
		std::vector<double> kopiaTablicy = data;

		//Pomiar czasu wykonywania algorytmu
		auto start = std::chrono::high_resolution_clock::now();
		algorithm->sort(kopiaTablicy);//Lub (*algorithm).sort(...)
		auto end = std::chrono::high_resolution_clock::now();

		//Obliczenie czasu wykonywania algorytmu, zapisanie wynikow do pliku oraz wypisanie najlepszego na ekran
		std::chrono::duration<double, std::milli> duration = end - start;
		if (wyniki.good() == true) {
			wyniki << algorithm->getName() << " " << duration.count() << "\n";
		}
		if (static_cast<double>(duration.count()) < bestTime || bestTime == 0) {
			bestTime = static_cast<double>(duration.count());
			bestAlgorithm = algorithm->getName();
		}
		// Zapisuje wyniki dzia�ania alortytmu do bazy danych, jesli jest aktywna (wskaznik dbManager jest ustawiony i jest wlaczona opcja zapisu)
		if (dbManager && ConsoleUtils::DBStatus == true) {
			dbManager->saveResult(
				algorithm->getName(),
				static_cast<int>(data.size()),
				duration.count(),
				algorithm->getTComplexity(),
				algorithm->getSComplexity()
			);
		}

		std::cout << std::setw(16) << algorithm->getName() 
			<< std::setw(25) << duration.count() 
			<< std::setw(20) << algorithm->getTComplexity() 
			<< std::setw(25) << algorithm->getSComplexity() << "\n";
	}
	std::cout << "\nZwyciezca sortowania jest algorytm: " << bestAlgorithm << "\n";
	std::cout << "Czas sortowania: " << bestTime << " ms!\n";
};

//Implementacja metody generujacej zestaw losowych danych
std::vector<double> AlgorithmComparison::generateDataset(int dataSize, double min, double max) {
	std::vector<double> data(dataSize);


	/*
		Do generowania liczb pseudolosowych wykorzystuje biblioteke <random>,
		ktora jest nowsza bardziej precyzyjna i bezpieczniejsza niz funkcje z biblioteki <cstdlib>.
		Generatory liczb pseudolosowych z biblioteki <random> sa bardziej wydajne i maja lepsze wlasciwosci statystyczne.
		Jednak daloby sie rowniez uzyskac podobny efekt z wykorzystaniem funkcji rand() z biblioteki <cstdlib>.
	*/


	std::random_device rd; //Wygenerowanie "ziarna" do generatora liczb pseudolosowych
	std::mt19937 gen(rd()); //Utworzenie generatora liczb pseudolosowych z wykorzystaniem algorytmu Mersenne Twister
	std::uniform_real_distribution<double> rozklad(min, max); //Utworzenie rozkladu jednostajnego liczb calkowitych w zakreesie min - max

	//Petla, ktora wypelnia tablice liczbami pseudolosowymi
	for (size_t i = 0; i < dataSize; ++i) {
		data[i] = rozklad(gen);
	}

	return data;
};

//Implementacja metody wczytujacej dane z pliku
std::vector<double> AlgorithmComparison::uploadFileDataset(std::string fileName) {
	std::ifstream file(fileName); //Otworzenie pliku do odczytu danych

	std::vector<double> data; //Utworzenie tablicy dynamicznej, ktora bedzie przechowywac dane z pliku

	if (file.good() == true) { //Sprawdzenie czy plik zostal otworzony poprawnie
		double number{}; //Zmienna pomocnicza do przechowywania liczb z pliku
		while (file >> number) { //Petla, ktora wczytuje liczby z pliku
			data.push_back(number); //Dodanie liczby do tablicy
		}
		file.close(); //Zamkniecie pliku
	}
	else {
		std::cout << "Blad otwarcia pliku: " << fileName << ". Sprawdz czy plik zostal utworzony." << std::endl;
	}
	return data;
};

//Implementacja metody generujacej plik z danymi
void AlgorithmComparison::generateFileDataset(std::string fileName, int dataSize, double min, double max) {
	std::ofstream file("../data/" + fileName); //Otworzenie pliku do zapisu danych
	if (file.good() == true) { //Sprawdzenie czy plik zostal otworzony poprawnie
		std::vector<double> data = generateDataset(dataSize, min, max); //Wygenerowanie danych
		for (const double& number : data) { //Petla, ktora zapisuje dane do pliku
			file << number << " ";
		}
		file.close(); //Zamkniecie pliku
	}
	else {
		std::cout << "Blad otwarcia pliku: " << fileName << ". Sprawdz czy podana sciezka jest wlasciwa." << std::endl;
	}
}

