#include "../headers/AlgorithmComparison.h"

#include <iostream> //Wyjscie / wejscie
#include <iomanip> //Manipulatory strumienia
#include <chrono> // Mierzenie czasu wykonywania algorytmow
#include <random> // Generacja liczb pseudolosowych

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

	std::random_device rd; //Wygenerowanie "ziarna" do generatora liczb pseudolosowych
	std::mt19937 gen(rd()); //Utworzenie generatora liczb pseudolosowych z wykorzystaniem algorytmu Mersenne Twister
	std::uniform_int_distribution<int> rozklad(min, max); //Utworzenie rozkladu jednostajnego liczb calkowitych w zakreesie min - max

	//Petla, ktora wypelnia tablice liczbami pseudolosowymi
	for (size_t i = 0; i < dataSize; ++i) {
		data[i] = rozklad(gen);
	}

	return data;
};

