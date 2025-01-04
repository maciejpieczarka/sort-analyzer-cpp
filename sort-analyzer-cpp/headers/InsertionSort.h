#pragma once

#include "SortAlgorithm.h"

//Klasa odpowiadajaca za sortowanie przez wstawianie
class InsertionSort : public SortAlgorithm {
public:
	//Nadpisana metoda sortowania - sortowanie przez wstawianie
	void sort(std::vector<int>& data) override;

	//Zaimplementowana metoda zwracaj�ca nazw� algorytmu
	std::string getName() const override { return "Insertion Sort"; };

	//Zaimplementowane metody zwracaj�ce z�o�ono�� czasow� i pami�ciow�
	std::string getTComplexity() const override { return "O(n^2) / O(n)"; }; //TODO: Different time complexity
	std::string getSComplexity() const override { return "O(1)"; };
};