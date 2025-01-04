#pragma once

#include "SortAlgorithm.h"

//Klasa odpowiadajaca za sortowanie przez wybieranie
class SelectionSort : public SortAlgorithm {
public:
	//Nadpisana metoda sortowania - sortowanie przez wybieranie
	void sort(std::vector<int>& data) override;

	//Zaimplementowana metoda zwracajaca nazwe algorytmu
	std::string getName() const override { return "Selection Sort"; };

	//Zaimplementowane metody zwracajace z³o¿onosc czasowa i pamieciowa
	std::string getTComplexity() const override { return "O(n^2)"; };
	std::string getSComplexity() const override { return "O(1)"; };
};