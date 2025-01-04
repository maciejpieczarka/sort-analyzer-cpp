#pragma once

#include "SortAlgorithm.h"

//Klasa odpowiadajaca za sortowanie przez wybieranie
class SelectionSort : public SortAlgorithm {
public:
	//Nadpisana metoda sortowania - sortowanie przez wybieranie
	void sort(std::vector<int>& data) override;

	//Zaimplementowana metoda zwracaj¹ca nazwê algorytmu
	std::string getName() const override { return "Selection Sort"; };

	//Zaimplementowane metody zwracaj¹ce z³o¿onoœæ czasow¹ i pamiêciow¹
	std::string getTComplexity() const override { return "O(n^2)"; };
	std::string getSComplexity() const override { return "O(1)"; };
};