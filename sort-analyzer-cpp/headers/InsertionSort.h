#pragma once

#include "SortAlgorithm.h"

//Klasa odpowiadajaca za sortowanie przez wstawianie
class InsertionSort : public SortAlgorithm {
public:
	//Nadpisana metoda sortowania - sortowanie przez wstawianie
	void sort(std::vector<int>& data) override;

	//Zaimplementowana metoda zwracaj¹ca nazwê algorytmu
	std::string getName() const override { return "Insertion Sort"; };

	//Zaimplementowane metody zwracaj¹ce z³o¿onoœæ czasow¹ i pamiêciow¹
	std::string getTComplexity() const override { return "O(n^2) / O(n)"; }; //TODO: Different time complexity
	std::string getSComplexity() const override { return "O(1)"; };
};