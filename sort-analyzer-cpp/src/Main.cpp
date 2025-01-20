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
	MenuManager mainMenu, dataTypeMenu, algorithmPickerMenu;
	
	AlgorithmComparison comparison;
	MenuManager menuManager;
	int dataSize{}, dataRange{};


	// Zainicjalizowanie obiektow algorytmow
	comparison.addAlgorithm(std::make_unique<BubbleSort>());
	comparison.addAlgorithm(std::make_unique<InsertionSort>());
	comparison.addAlgorithm(std::make_unique<HeapSort>());
	comparison.addAlgorithm(std::make_unique<MergeSort>());
	comparison.addAlgorithm(std::make_unique<SelectionSort>());
	comparison.addAlgorithm(std::make_unique<QuickSort>());

	//Konfiguracja menu do wyboru typu danych
	dataTypeMenu.setConsolePhrase("W jaki sposob chcesz przekazac dane do sortowania?");
	dataTypeMenu.setShouldExit(true);
	//Dodawanie opcji do menu wyboru typu danych
	dataTypeMenu.addOption("Losowo", [&dataSize, &dataRange, &comparison, dataTypeMenu](){
		std::cout << "Podaj ilosc danych do wygenerowania (1 - 10 000): ";
		std::cin >> dataSize;
		std::system("cls");
		std::cout << "Podaj zakres generowanych liczb (1 - 10 000): ";
		std::cin >> dataRange;
		std::system("cls");
		std::vector<int> data = comparison.generateDataset(dataSize, 0, dataRange);
		comparison.compareData(data);
		});
	dataTypeMenu.addOption("Recznie", []() {});
	dataTypeMenu.addOption("Z Pliku", []() {});


	//konfiguracja menu glownego
	mainMenu.setIsMain(true);
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
