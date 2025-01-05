#include <iostream>

#include "../headers/BubbleSort.h"
#include "../headers/InsertionSort.h"
#include "../headers/AlgorithmComparison.h"
#include <vector>
int main()
{
	AlgorithmComparison comparison;

	comparison.addAlgorithm(std::make_unique<BubbleSort>());
	comparison.addAlgorithm(std::make_unique<InsertionSort>());

	std::vector<int> data = comparison.generateDataset(20000, 0, 999999);

	comparison.compareData(data);
}
