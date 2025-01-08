#pragma once

#include "SortAlgorithm.h"
#include <vector>
#include <string>

//Klasa odpowiadajaca za sortowanie przez scalanie
class MergeSort : public SortAlgorithm {
public:
	//Nadpisana metoda sortowania - sortowanie przez scalanie
	void sort(std::vector<int>& data) override;

	//Zaimplementowana metoda zwracajaca nazwe algorytmu
	std::string getName() const override { return "Merge Sort"; };

	//Zaimplementowane metody zwracajace zlozonosc czasowa i pamieciowa
	std::string getTComplexity() const override { return "O(N*logN)"; };
	std::string getSComplexity() const override { return "O(N)"; };

private:
	void mergeSort(std::vector<int>& data, int left, int right);
	void merge(std::vector<int>& data, int left, int mid, int right);
};