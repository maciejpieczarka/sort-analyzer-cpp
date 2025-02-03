#include "../headers/MenuManager.h"
#include <iomanip>
//Implementacja konstruktora domyslnego
MenuManager::MenuManager() 
    : m_consolePhrase("Wybierz opcje"),
    m_isMain(false){}

//Implementacja konstruktora z parametrami
MenuManager::MenuManager(const std::string& consolePhrase, bool& isMain) 
    : m_consolePhrase(consolePhrase), 
    m_isMain(isMain) {}

void MenuManager::setShouldExit(const bool& shouldExit) {
	m_ShouldExit = shouldExit;
}

//Implementacja settera dla frazy, ktora wyswietla sie w konsoli
void MenuManager::setConsolePhrase(const std::string& consolePhrase) {
	m_consolePhrase = consolePhrase;
}

//Implementacja settera dla zmiennej, ktora sprawdza czy menu jest menu glownym
void MenuManager::setIsMain(const bool& isMain) {
	m_isMain = isMain;
}

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

void MenuManager::displayMenu() const {

    std::cout << std::string(88, '=') << "\n";
	std::cout << std::setw(50) << "Sort-Analyzer" << std::string(38, ' ') << "\n";
    std::cout << std::string(88, '=') << "\n";
	if (m_consolePhrase.length() > 0) {
        std::cout << "\n" << m_consolePhrase << "\n";
	}
    for (std::size_t i = 0; i < options.size(); ++i) {
        std::cout << (i + 1) << ". " << options[i] << "\n";
    }
    
	if (m_isMain) {
		std::cout << "0. Zakoncz program\n";
    }
    else {
        std::cout << "0. Cofnij\n";
    }
}

void MenuManager::runMenu() {
    while (true) {
        int wybranaOpcja;
        displayMenu();
        std::cout << "\nTwoj wybor: ";
        std::cin >> wybranaOpcja;
        std::system("cls");

        if (wybranaOpcja == 0) {
            if (m_isMain) {
                std::cout << "Zakonczono program.\n";
            }
            break;
        }

        if (wybranaOpcja > 0 && wybranaOpcja <= static_cast<int>(funkcjeOpcji.size())) { //Konwersja z typu size_t na typ int
            funkcjeOpcji[wybranaOpcja - 1]();   // Wykonaj wybrana funkcje
			if (m_ShouldExit) {
				break;
			}
        }
        else {
            std::cout << "Zly wybor, sprobuj ponownie\n";
            
        }
    }
}
