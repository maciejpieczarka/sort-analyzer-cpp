#include <iostream>

//Pliki naglowkowe
#include "../headers/BubbleSort.h"
#include "../headers/InsertionSort.h"
#include "../headers/HeapSort.h"
#include "../headers/MergeSort.h"
#include "../headers/SelectionSort.h"
#include "../headers/QuickSort.h"
#include "../headers/AlgorithmComparison.h"
#include "../headers/MenuManager.h"

void instruction() {
	std::cout << "Instrukcja oprogramowania.\n";
}

int main()
{
	MenuManager mainMenu, dataTypeMenu;
	AlgorithmComparison comparison;
	MenuManager menuManager;

	comparison.addAlgorithm(std::make_unique<BubbleSort>());
	comparison.addAlgorithm(std::make_unique<InsertionSort>());
	comparison.addAlgorithm(std::make_unique<HeapSort>());
	comparison.addAlgorithm(std::make_unique<MergeSort>());
	comparison.addAlgorithm(std::make_unique<SelectionSort>());
	comparison.addAlgorithm(std::make_unique<QuickSort>());

	//Ddawanie opcji do menu wyboru typu danych
	dataTypeMenu.addOption("Losowo", []() {});

	//Dodawanie opcji do mennu glownego
	mainMenu.addSubMenu("Porownaj algorytmy", dataTypeMenu);
	mainMenu.addOption("Wyswietl Instrukcje", []() {
		std::cout << "Instrukcja aplikacji.\n"; 
		});

	
	mainMenu.runMenu();


	//Generacja pliku z danymi
	//comparison.generateFileDataset("Tablica10.txt", 100, 0, 9999);

	//std::vector<int> data = comparison.uploadFileDataset("./data/Tablica10.txt");
	
	/*std::vector<int> data = comparison.generateDataset(10000, 0, 9);
	comparison.compareData(data);*/

	
	//menuManager.displayMenu();
}
