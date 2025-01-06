#pragma once

#include "SortAlgorithm.h"

//Klasa odpowiadajaca za sortowanie przez kopcowanie
class HeapSort : public SortAlgorithm {
public:
	//Nadpisana metoda sortowania - sortowanie przez kopcowanie
	void sort(std::vector<int>& data) override;

	//Zaimplementowana metoda zwracajaca nazwe algorytmu
	std::string getName() const override { return "Heap Sort"; };

	//Zaimplementowane metody zwracajace zlozonosc czasowa i pamieciowa
	std::string getTComplexity() const override { return "O(N*logN)"; };
	std::string getSComplexity() const override { return "O(1)"; };

private:
	void heapify(std::vector<int>& data, int n, int i);
	void buildHeap(std::vector<int>& data, int n);
};