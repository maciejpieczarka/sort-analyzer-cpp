#pragma once

#include "SortAlgorithm.h"

//Klasa odpowiadajaca za sortowanie babelkowe
class BubbleSort : public SortAlgorithm {
public:
	//Metoda sortowania b�belkowego
	void sort(std::vector<int>& data) override;

	//Zaimplementowana metoda zwracaj�ca nazw� algorytmu
	std::string getName() const override { return "Bubble Sort"; };
};