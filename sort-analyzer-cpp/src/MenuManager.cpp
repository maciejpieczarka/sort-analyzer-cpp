#include "../headers/MenuManager.h"


void MenuManager::addSubMenu(const std::string& description, MenuManager nestedMenu) {
    options.push_back(description);
    funkcjeOpcji.push_back([nestedMenu]() mutable {
		nestedMenu.runMenu();  // Uruchom zagniezdzone menu
        });
}

void MenuManager::addOption(const std::string& description, const std::function<void()>& action) {
	options.push_back(description);
    funkcjeOpcji.push_back(action);
}

void MenuManager::displayMenu(std::string menuDescription) const {
    std::cout << "======================\n";
    std::cout << "Sort-Analyzer\n";
    std::cout << "======================\n";
	if (menuDescription.length() > 0) {
		std::cout << menuDescription << "\n";
	}
    for (std::size_t i = 0; i < options.size(); ++i) {
        std::cout << (i + 1) << ". " << options[i] << std::endl;
    }
    std::cout << "0. Wyjdz\n";
}

void MenuManager::runMenu() {
    while (true) {
        int wybranaOpcja{};
        displayMenu("Wybierz opcje");
        std::cout << "Twoj wybor: ";
        std::cin >> wybranaOpcja;
        std::system("cls");

        if (wybranaOpcja == 0) {
            std::cout << "Zakonczono program.\n";
            break;
        }

        if (wybranaOpcja > 0 && wybranaOpcja <= static_cast<int>(funkcjeOpcji.size())) { //Konwersja z typu size_t na typ int
            funkcjeOpcji[wybranaOpcja - 1]();  // Wykonaj wybrana funkcje
        }
        else {
            std::cout << "Zly wybor, sprobuj ponownie\n";
            
        }
    }
}

//void MenuManager::displayMenu() {
//	unsigned short menuChoice{};
//	bool isChoiceCorrect = false;
//	
//	do {
//		
//		std::cout << "1. Porownaj Algorytmy\n";
//		std::cout << "2. Wyswietl intrukcje\n";
//		std::cout << "3. Wyjscie\n";
//		std::cout << "Twoj wybor: ";
//		std::cin >> menuChoice;
//
//		std::system("cls");
//
//		switch (menuChoice) {
//		case 1:
//			isChoiceCorrect = true;
//			displayComparisonMenu();
//			break;
//		case 2:
//			isChoiceCorrect = true;
//			displayInstruction();
//			break;
//		case 3:
//			isChoiceCorrect = true;
//			exit(0);
//			break;
//		default:
//			
//			break;
//		};
//
//	} while (isChoiceCorrect == false);
//
//}

//void MenuManager::displayComparisonMenu() {
//	unsigned short menuChoice{};
//	bool isChoiceCorrect = false;
//	do {
//		std::cout << "======================\n";
//		std::cout << "Sort-Analyzer\n";
//		std::cout << "======================\n";
//		std::cout << "W jaki sposob chcesz przekazac dane do sortowania?\n";
//		std::cout << "1. Wygeneruj losowe dane\n";
//		std::cout << "2. Wczytaj dane z pliku\n";
//		std::cout << "3. Podaj dane recznie\n";
//		std::cout << "4. Wroc do menu glownego\n";
//		std::cout << "Twoj wybor: ";
//		std::cin >> menuChoice;
//		std::system("cls");
//		switch (menuChoice) {
//		case 1:
//			isChoiceCorrect = true;
//			break;
//		case 2:
//			isChoiceCorrect = true;
//			break;
//		case 3:
//			isChoiceCorrect = true;
//			break;
//		case 4:
//			isChoiceCorrect = true;
//			displayMenu();
//			break;
//		default:
//			break;
//		};
//	} while (isChoiceCorrect == false);
//}
//
//void MenuManager::displayInstruction() {
//	std::cout << "======================\n";
//	std::cout << "Sort-Analyzer\n";
//	std::cout << "======================\n";
//	std::cout << "instrukcja";
//}
