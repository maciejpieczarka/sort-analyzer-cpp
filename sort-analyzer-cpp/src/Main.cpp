#include <iostream>
#include <typeinfo>
#include <cmath>

#include <string>
#include <chrono>
#include <thread>

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
#include "../headers/DatabaseManager.h"

int main()
{
	// Konfiguracja bazy danych do zapisywania wynikow sortowania
	DatabaseManager dbManager("./../data/sort_analyzer.db"); 

	// Tworzenie hierarchii menu: glowne oraz podmenu dla typow danych i wyboru algorytmow
	MenuManager mainMenu, dataTypeMenu, algorithmPickerMenu;
	
	// Utworzenie obiektu do porownywania wydajnosci algorytmow sortowania
	AlgorithmComparison comparison;

	// Umozliwienie zapisywania wynikow porownań do bazy danych
	comparison.setDatabaseManager(&dbManager);

	//Zmienne przechowujace ilosc danych oraz zakres generowanych liczb
	int dataSize{};
	double lowerRange{}, upperRange{};
	std::string userResponse;

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
	dataTypeMenu.addOption("Losowo", [&dataSize, &lowerRange, &upperRange, &comparison, &userResponse](){
		std::cin.ignore();
		// Wprowadzanie danych do generacji liczb
		// z walidacja danych i obsluga wyjatkow
		while (true) {
			std::cout << "Podaj ilosc danych do wygenerowania (1 - 10 000): ";

			try {
				std::getline(std::cin, userResponse);

				// Jeśli użytkownik nic nie wpisał (tylko Enter) - pomiń
				if (userResponse.empty()) {
					std::cout << "Nie podano liczby. Spróbuj ponownie.\n";
					continue;
				}

				//konwersja wprowadzonych danych na int
				dataSize = std::stoi(userResponse);

				if (dataSize < 1 || dataSize > 10000) {
					//Wyjatek jesli wartosc wykracza poza zakres
					throw std::out_of_range("Nieprawidłowy zakres");
				}
				break; // Jeśli wszystko OK, wyjdź z pętli
			}
			//obsluga wyjatkow
			catch (std::invalid_argument const& ex) {
				std::cout << "Niepoprawny format. Podaj LICZBĘ z zakresu 1 - 10 000.\n";
				std::cin.clear(); // Wyczyść ewentualne błędy strumienia
			}
			catch (std::out_of_range const& ex) {
				std::cout << "Niepoprawny zakres. Podaj liczbę z zakresu 1 - 10 000.\n";
			}
		}
		ConsoleUtils::clear();

		while (true) {
		std::cout << "Podaj DOLNY zakres generowanych liczb: ";
		try {
			std::getline(std::cin, userResponse);

			if (userResponse.empty()) {
				std::cout << "Nie podano liczby. Spróbuj ponownie.\n";
				continue;
			}

			lowerRange = std::stod(userResponse);

			std::cout << "Podaj GORNY zakres generowanych liczb: ";
			std::getline(std::cin, userResponse);

			if (userResponse.empty()) {
				std::cout << "Nie podano liczby. Spróbuj ponownie.\n";
				continue;
			}

			upperRange = std::stod(userResponse);

			if (lowerRange >= upperRange) {
				throw std::out_of_range("Dolny zakres musi byc mniejszy niz gorny");
			}

			if (std::abs(lowerRange) > 1e6 || std::abs(upperRange) > 1e6) {
				throw std::out_of_range("Zakres nie moze przekraczac 1 000 000");
			}

			break;
		}
		catch (std::invalid_argument const& ex) {
			std::cout << "Niepoprawny format. Podaj liczbe.\n";
			std::cin.clear();
		}
		catch (std::out_of_range const& ex) {
			std::cout << "Blad: " << ex.what() << "\n";
		}
	}
		ConsoleUtils::clear();
		//Generuje zestaw danych od -1000000 do dataRange
		std::vector<double> data = comparison.generateDataset(dataSize, lowerRange, upperRange);
		comparison.compareData(data);
		});

	//Obsluga recznego wpisywania danych do sortowania
	dataTypeMenu.addOption("Recznie", [&comparison, &dataSize, &userResponse]() {
		std::vector<double> data;
		double num{};
		//Podanie ilosci liczb do posortowania z walidacja danych i obsluga wyjatkow
		std::cin.ignore();
		while (true) {
			try {
				std::cout << "Ile liczb chcesz posortowac? (1 - 100): ";
				std::getline(std::cin, userResponse);

				if (userResponse.empty()) {
					std::cout << "Nie podano liczby. Spróbuj ponownie.\n";
					continue;
				}

				dataSize = std::stoi(userResponse);

				if (dataSize < 1 || dataSize > 100) {
					throw std::out_of_range("Nieprawidłowy zakres");
				}
				break;
			}
			//Wyjatek wystepujacy w momencie niepoprawnego formatu liczby
			catch (const std::invalid_argument&) {
				std::cout << "Niepoprawny format. Podaj LICZBĘ z zakresu 1 - 100.\n";
			}
			//Wyjatek wystepujacy w momencie przekroczenia zakresu
			catch (const std::out_of_range&) {
				std::cout << "Niepoprawny zakres. Podaj liczbę z zakresu 1 - 100.\n";
			}
		}
		for (int i = 0; i < dataSize; ) {
			try {
				std::cout << "Podaj liczbe " << i+1 << ": ";
				std::getline(std::cin, userResponse);

				if (userResponse.empty()) {
					std::cout << "Nie podano liczby. Spróbuj ponownie.\n";
					continue;
				}

				num = std::stod(userResponse);

				// Sprawdzenie czy liczba jest skończona (nie NaN ani nieskończoność)
				if (!std::isfinite(num)) {
					throw std::invalid_argument("Nieprawidłowa wartość liczbowa");
				}

				data.push_back(num);
				i++; // Zwiększ licznik tylko po poprawnym wprowadzeniu
			}
			catch (const std::invalid_argument&) {
				std::cout << "Niepoprawny format. Podaj poprawną liczbę.\n";
			}
			catch (const std::out_of_range&) {
				std::cout << "Podana liczba jest zbyt duża. Spróbuj ponownie.\n";
			}
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
	//Dodawanie opcji do menu glownego
	mainMenu.addSubMenu("Porownaj algorytmy", dataTypeMenu);

	//Indeks przed dodaniem nowej opcji
	int idxZapisDB = mainMenu.getOptionsCount();

	// Dodanie opcji wlaczania/wylaczania zapisu wynikow do bazy danych
	mainMenu.addOption("Zapis do bazy danych: NIE", [&dbManager, &mainMenu, &idxZapisDB]() {
		char choice;
		std::cout << "Czy chcesz zapisac dane do bazy? [T/N]: ";
		std::cin >> choice;

		// Ustawienie flagi zapisu do bazy na podstawie wyboru uzytkownika
		if (choice == 't' || choice == 'T') {
			ConsoleUtils::DBStatus = true;
		}
		else if (choice == 'n' || choice == 'N') {
			ConsoleUtils::DBStatus = false;
		}
		else {
			// W przypadku niepoprawnego wyboru, powrot do menu po 2 sekundach
			std::cout << "Niepoprawny wybor - zaraz wrocisz do Menu\n";
			std::this_thread::sleep_for(std::chrono::seconds(2));
			ConsoleUtils::clear();
			return;
		}
		ConsoleUtils::clear();
		// Aktualizacja opisu opcji zapisu w menu glownym (aktualny stan zapisu do bazy danych)
		std::string newDesc = "Zapis do bazy danych: ";
		newDesc += (ConsoleUtils::DBStatus ? "TAK" : "NIE");
		mainMenu.updateOptionDesc(idxZapisDB, newDesc);
		});

	//Opcja wyswietlajaca instrukcje
	mainMenu.addOption("O Programie", []() {
		std::cout << "Sort Analyzer to aplikacja stworzona do porownania wydajnosci 6 algorytmow sortujacych.\n";
		std::cout << "Aplikacja pozwala na wybor sposobu przekazania danych do sortowania oraz porownanie algorytmow na tych samych danych.\n";
		std::cout << "Poruszanie sie po menu odbywa sie za pomoca klawiszy numerycznych.\n\n";
		std::cout << "Aplikacja stworzona przez: Maciej Pieczarka, Szymon Pajak, Piotr Zdebik MS - Informatyka. Semestr II\n";
		});

	//Opcja czyszczenia ekranu konsoli
	mainMenu.addOption("Wyczysc Ekran", []() {
		ConsoleUtils::clear();
		});

	
	mainMenu.runMenu();
}
