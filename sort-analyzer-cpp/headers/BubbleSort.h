#pragma once

#include "SortAlgorithm.h"

//Klasa odpowiadajaca za sortowanie babelkowe
class BubbleSort : public SortAlgorithm {
public:
	//Nadpisana metoda sortowania - Sortowanie babelkowe
	void sort(std::vector<int>& data) override;

	//Zaimplementowana metoda zwracajaca nazwe algorytmu
	std::string getName() const override { return "Bubble Sort"; };

	//Zaimplementowane metody zwracajace zlozonosc czasowa i pamieciowa
	std::string getTComplexity() const override { return "O(n^2)"; };
	std::string getSComplexity() const override { return "O(1)"; };
};