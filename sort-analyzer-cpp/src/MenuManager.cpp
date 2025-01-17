#include "../headers/MenuManager.h"

void MenuManager::displayMenu() {
	unsigned short menuChoice{};
	bool isChoiceCorrect = false;
	
	do {
		std::cout << "======================\n";
		std::cout << "Sort-Analyzer\n";
		std::cout << "======================\n";
		std::cout << "1. Porownaj Algorytmy\n";
		std::cout << "2. Wyswietl intrukcje\n";
		std::cout << "3. Wyjscie\n";
		std::cout << "Twoj wybor: ";
		std::cin >> menuChoice;

		std::system("cls");

		switch (menuChoice) {
		case 1:
			isChoiceCorrect = true;
			displayComparisonMenu();
			break;
		case 2:
			isChoiceCorrect = true;
			displayInstruction();
			break;
		case 3:
			isChoiceCorrect = true;
			exit(0);
			break;
		default:
			
			break;
		};

	} while (isChoiceCorrect == false);

}

void MenuManager::displayComparisonMenu() {
	unsigned short menuChoice{};
	bool isChoiceCorrect = false;
	do {
		std::cout << "======================\n";
		std::cout << "Sort-Analyzer\n";
		std::cout << "======================\n";
		std::cout << "W jaki sposob chcesz przekazac dane do sortowania?\n";
		std::cout << "1. Wygeneruj losowe dane\n";
		std::cout << "2. Wczytaj dane z pliku\n";
		std::cout << "3. Podaj dane recznie\n";
		std::cout << "4. Wroc do menu glownego\n";
		std::cout << "Twoj wybor: ";
		std::cin >> menuChoice;
		std::system("cls");
		switch (menuChoice) {
		case 1:
			isChoiceCorrect = true;
			break;
		case 2:
			isChoiceCorrect = true;
			break;
		case 3:
			isChoiceCorrect = true;
			break;
		case 4:
			isChoiceCorrect = true;
			displayMenu();
			break;
		default:
			break;
		};
	} while (isChoiceCorrect == false);
}

void MenuManager::displayInstruction() {
	std::cout << "======================\n";
	std::cout << "Sort-Analyzer\n";
	std::cout << "======================\n";
	std::cout << "instrukcja";
}
