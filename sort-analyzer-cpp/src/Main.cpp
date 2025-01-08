#include <iostream>

#include "../headers/BubbleSort.h"
#include "../headers/InsertionSort.h"
#include "../headers/HeapSort.h"
#include "../headers/MergeSort.h"
#include "../headers/SelectionSort.h"
#include "../headers/AlgorithmComparison.h"
#include <vector>
int main()
{
	AlgorithmComparison comparison;

	comparison.addAlgorithm(std::make_unique<BubbleSort>());
	comparison.addAlgorithm(std::make_unique<InsertionSort>());
	comparison.addAlgorithm(std::make_unique<HeapSort>());
	comparison.addAlgorithm(std::make_unique<MergeSort>());
	comparison.addAlgorithm(std::make_unique<SelectionSort>());

	//Generacja pliku z danymi
	//comparison.generateFileDataset("Tablica10.txt", 100, 0, 9999);

	std::vector<int> data = comparison.uploadFileDataset("./data/Tablica10.txt");
	
	//std::vector<int> data = comparison.generateDataset(100000, 0, 9);

	comparison.compareData(data);
}
