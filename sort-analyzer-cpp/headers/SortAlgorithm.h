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

	//Wirtualna metoda, kt�ra zwraca nazwe algorytmu
	virtual std::string getName() const = 0;

	//Wirtualne metody zwracajace z�ozonosc czasowa i pamieciowa
	virtual std::string getTComplexity() const = 0;
	virtual std::string getSComplexity() const = 0;
};