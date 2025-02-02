#pragma once

#include "SortAlgorithm.h"
#include <vector>

class QuickSort : public SortAlgorithm {
public:
	void sort(std::vector<double>& data) override;

	//Zaimplementowana metoda zwracajaca nazwe algorytmu
	std::string getName() const override { return "Quick Sort"; };

	//Zaimplementowane metody zwracajace z³o¿onosc czasowa i pamieciowa
	std::string getTComplexity() const override { return "TODO"; }; //TODO: Different time complexity
	std::string getSComplexity() const override { return "O(n)"; };

private:
	void quickSort(std::vector<double>& data, int low, int high);
	int partition(std::vector<double>& data, int low, int high);
};