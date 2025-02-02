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
	dataTypeMenu.addOption("Losowo", [&dataSize, &dataRange, &comparison](){
		std::cout << "Podaj ilosc danych do wygenerowania (1 - 10 000): ";
		std::cin >> dataSize;
		std::system("cls");
		std::cout << "Podaj zakres generowanych liczb (1 - 10 000): ";
		std::cin >> dataRange;
		std::system("cls");
		std::vector<double> data = comparison.generateDataset(dataSize, 0, dataRange);
		comparison.compareData(data);
		});
	dataTypeMenu.addOption("Recznie", [&comparison, &dataSize]() {
		std::vector<double> data;
		double num{};
		std::cout << "Ile liczb chcesz posortowac?: ";
		std::cin >> dataSize;
		for (int i = 0; i < dataSize; i++) {
			std::cout << "Podaj liczbe " << i+1 << ": ";
			std::cin >> num;
			data.push_back(num);
		}
		std::system("cls");
		comparison.compareData(data);
		});
	dataTypeMenu.addOption("Z Pliku", []() {});


	//konfiguracja menu glownego
	mainMenu.setIsMain(true);
	//Dodawanie opcji do mennu glownego
	mainMenu.addSubMenu("Porownaj algorytmy", dataTypeMenu);
	mainMenu.addOption("Wyswietl Instrukcje", []() {
		std::cout << "Sort Analyzer to aplikacja stworzona do porownania wydajnosci 6 algorytmow sortujacych.\n ";
		std::cout << "Aplikacja pozwala na wybor sposobu przekazania danych do sortowania oraz porownanie algorytmow na tych samych danych.\n";
		std::cout << "Poruszanie sie po menu odbywa sie za pomoca klawiszy numerycznych.\n";
		std::cout << "Aplikacja stworzona przez: Maciej Pieczarka MS - Informatyka. Semestr I, Grupa 2.\n";
		});

	
	mainMenu.runMenu();


	//Generacja pliku z danymi
	//comparison.generateFileDataset("Tablica10.txt", 100, 0, 9999);

	//std::vector<int> data = comparison.uploadFileDataset("./data/Tablica10.txt");
	
	/*std::vector<int> data = comparison.generateDataset(10000, 0, 9);
	comparison.compareData(data);*/

	
	//menuManager.displayMenu();
}
