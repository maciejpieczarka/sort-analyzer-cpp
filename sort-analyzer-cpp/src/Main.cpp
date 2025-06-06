﻿#include <iostream>
#include <limits>
#include <typeinfo>
#include <cmath>

//Pliki naglowkowe
#include "../headers/BubbleSort.h"
#include "../headers/InsertionSort.h"
#include "../headers/HeapSort.h"
#include "../headers/MergeSort.h"
#include "../headers/SelectionSort.h"
#include "../headers/QuickSort.h"
#include "../headers/AlgorithmComparison.h"
#include "../headers/MenuManager.h"
#include "../headers/ConsoleUtils.h"



int main()
{
	//Inicjalizacja klas menu
	MenuManager mainMenu, dataTypeMenu, algorithmPickerMenu;
	
	//Inicjalizacja klasy porownujacej algorytmy
	AlgorithmComparison comparison;

	//Zmienne przechowujace ilosc danych oraz zakres generowanych liczb
	int dataSize{};
	double dataRange{};


	// Zainicjalizowanie obiektow algorytmow jako unikalne wskazniki
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

	//Obsluga generowania losowych danych do sortowania
	//Przekazanie do funkcji lambda zmiennych dataSize, dataRange oraz comparison poprzez referencje, aby pracowac na oryginalach
	dataTypeMenu.addOption("Losowo", [&dataSize, &dataRange, &comparison](){
		while (true) {
			std::cout << "Podaj ilosc danych do wygenerowania (1 - 10 000): ";
			std::cin >> dataSize;
			if (dataSize < 1 || dataSize > 100000) {
				ConsoleUtils::clear();
				std::cout << "Niepoprawna ilosc danych. Podaj liczbe z zakresu 1 - 10 000.\n";
			}
			else {
				break;
			}
		}
		ConsoleUtils::clear();
		while (true) {
			std::cout << "Podaj zakres generowanych liczb: ";
			std::cin >> dataRange;
			if (dataRange <= -1e6 || dataRange > 1e6) {
				ConsoleUtils::clear();
				std::cout << "Podano nieprawidlowy zakres!\n";
			}
			else {
				break;
			}
		}
		ConsoleUtils::clear();
		//Generuje zestaw danych od -1000000 do dataRange
		std::vector<double> data = comparison.generateDataset(dataSize, -1e6, dataRange);
		comparison.compareData(data);
		});

	//Obsluga recznego wpisywania danych do sortowania
	dataTypeMenu.addOption("Recznie", [&comparison, &dataSize]() {
		std::vector<double> data;
		double num{};
		while (true) {
			std::cout << "Ile liczb chcesz posortowac? (1 - 100): ";
			std::cin >> dataSize;
			if (dataSize < 1 || dataSize > 100) {
				ConsoleUtils::clear();
				std::cout << "Niepoprawna ilosc danych. Podaj liczbe z zakresu 1 - 100.\n";
			}
			else {
				break;
			}
		}
		for (int i = 0; i < dataSize; i++) {
			std::cout << "Podaj liczbe " << i+1 << ": ";
			std::cin >> num;
			data.push_back(num);
		}
		ConsoleUtils::clear();
		comparison.compareData(data);
		});

	//Obsluga wczytywania danych z pliku do sortowania
	dataTypeMenu.addOption("Z Pliku", [&comparison]() {
		std::string path;
		char choice;
		std::vector<double> data;
		std::cout << "Utworz plik o nazwie: \'/data/data.txt\'\n";
		std::cout << "Liczby w pliku powinny byc oddzielone spacja.\n";
		std::cout << "\nCzy utworzono plik? (T/N): ";
		std::cin >> choice;
		if (choice == 'T' || choice == 't') {
			//Wczytuje zestaw danych z pliku data.txt
			std::vector<double> data = comparison.uploadFileDataset("../data/data.txt");
			if (data.size() > 0) {
				comparison.compareData(data);
			}
			else {
				std::cout << "Plik jest pusty.\n";
			}
		}
		else {
			std::cout << "Generuje losowy plik...\n";
			//Generuje plik z danymi w zakresie od -1000000 do 1000000
			comparison.generateFileDataset("data.txt", 10000, -1e6, 1e6);
			std::vector<double> data = comparison.uploadFileDataset("../data/data.txt");
			comparison.compareData(data);
		}
		});


	//konfiguracja menu glownego
	mainMenu.setIsMain(true);
	//Dodawanie opcji do mennu glownego
	mainMenu.addSubMenu("Porownaj algorytmy", dataTypeMenu);

	//Opcja wyswietlajaca instrukcje
	mainMenu.addOption("O Programie", []() {
		std::cout << "Sort Analyzer to aplikacja stworzona do porownania wydajnosci 6 algorytmow sortujacych.\n";
		std::cout << "Aplikacja pozwala na wybor sposobu przekazania danych do sortowania oraz porownanie algorytmow na tych samych danych.\n";
		std::cout << "Poruszanie sie po menu odbywa sie za pomoca klawiszy numerycznych.\n\n";
		std::cout << "Aplikacja stworzona przez: Maciej Pieczarka MS - Informatyka. Semestr I, Grupa 2.\n";
		});

	//Opcja czyszczenia ekranu konsoli
	mainMenu.addOption("Wyczysc Ekran", []() {
		ConsoleUtils::clear();
		});

	
	mainMenu.runMenu();
}
