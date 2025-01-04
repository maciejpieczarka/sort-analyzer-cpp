#pragma once

#include "SortAlgorithm.h"

//Klasa odpowiadajaca za sortowanie przez wybieranie
class SelectionSort : public SortAlgorithm {
public:
	//Nadpisana metoda sortowania - sortowanie przez wybieranie
	void sort(std::vector<int>& data) override;

	//Zaimplementowana metoda zwracaj�ca nazw� algorytmu
	std::string getName() const override { return "Selection Sort"; };

	//Zaimplementowane metody zwracaj�ce z�o�ono�� czasow� i pami�ciow�
	std::string getTComplexity() const override { return "O(n^2)"; };
	std::string getSComplexity() const override { return "O(1)"; };
};