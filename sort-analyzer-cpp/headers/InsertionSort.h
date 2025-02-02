#pragma once

#include "SortAlgorithm.h"

//Klasa odpowiadajaca za sortowanie przez wstawianie
class InsertionSort : public SortAlgorithm {
public:
	//Nadpisana metoda sortowania - sortowanie przez wstawianie
	void sort(std::vector<double>& data) override;

	//Zaimplementowana metoda zwracajaca nazwe algorytmu
	std::string getName() const override { return "Insertion Sort"; };

	//Zaimplementowane metody zwracajace z³o¿onosc czasowa i pamieciowa
	std::string getTComplexity() const override { return "TODO"; }; //TODO: Different time complexity
	std::string getSComplexity() const override { return "O(1)"; };
};