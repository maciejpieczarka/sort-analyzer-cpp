#pragma once

#include "SortAlgorithm.h"

//Klasa odpowiadajaca za sortowanie babelkowe
class BubbleSort : public SortAlgorithm {
public:
	//Nadpisana metoda sortowania - Sortowanie babelkowe
	void sort(std::vector<int>& data) override;

	//Zaimplementowana metoda zwracaj�ca nazw� algorytmu
	std::string getName() const override { return "Bubble Sort"; };

	//Zaimplementowane metody zwracaj�ce z�o�ono�� czasow� i pami�ciow�
	std::string getTComplexity() const override { return "O(n^2)"; };
	std::string getSComplexity() const override { return "O(1)"; };
};