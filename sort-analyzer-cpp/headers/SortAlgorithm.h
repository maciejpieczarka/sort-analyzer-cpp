#pragma once

#include <vector>
#include <string>

class SortAlgorithm {
public:
	//Wirtualny destruktor
	virtual ~SortAlgorithm() {};

	//Czysto wirtualna metoda sortowania do zaimplementowania 
	// w klasach dziedzicz�cych
	virtual void sort(std::vector<int>& data) = 0;

	//Wirtualna metoda, kt�ra zwraca nazw� algorytmu
	virtual std::string getName() const = 0;
};