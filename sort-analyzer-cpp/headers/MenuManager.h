#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cstdlib>

class MenuManager {
public:
    //Deklaracje konstruktorow
    MenuManager();
    MenuManager(const std::string& consolePhrase, bool& isMain);

    //Deklaracje setterow
	void setConsolePhrase(const std::string& consolePhrase);
	void setIsMain(const bool& isMain);
	void setShouldExit(const bool& shouldExit);

    // Dodaje zagniezdzone menu, ktore wyswietla sie jako opcja i przekierowuje
    // do nastepnego wyboru
    void addSubMenu(const std::string& description, MenuManager nestedMenu);

	// Dodaje nowa opcje do menu z jej opisem i funkcja do wykonania
    void addOption(const std::string& description, const std::function<void()>& action);

    // Umozliwa edycje opisu opcji menu
    void updateOptionDesc(int index, const std::string& newDesc);

    // Zwraca liczbe opcji
    int getOptionsCount() const;

    // Metoda wyswietlajaca menu
    void displayMenu() const;

	// Metoda uruchamiajaca menu i zajmujaca sie wyborem opcji
    void runMenu();

    
private:
	bool m_ShouldExit = false;
	bool m_isMain = false;
    std::string m_consolePhrase;

    //Dynamiczna tablica przechowujaca nazwy opcji menu
    std::vector<std::string> options;

	//Dynamiczna tablica przechowujaca funkcje zwrotne danych opcji
    std::vector<std::function<void()>> funkcjeOpcji; // Nie uzywam wskaznika do funkcji, gdyz w main.cpp korzystam z wyrazen lambda
};