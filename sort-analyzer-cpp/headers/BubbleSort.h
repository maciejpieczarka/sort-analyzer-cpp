#pragma once

#include "SortAlgorithm.h"

//Klasa odpowiadajaca za sortowanie babelkowe
class BubbleSort : public SortAlgorithm {
public:
	//Metoda sortowania b¹belkowego
	void sort(std::vector<int>& data) override;

	//Zaimplementowana metoda zwracaj¹ca nazwê algorytmu
	std::string getName() const override { return "Bubble Sort"; };
};