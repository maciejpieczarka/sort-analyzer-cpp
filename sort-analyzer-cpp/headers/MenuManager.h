#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cstdlib>

class MenuManager {
public:
    // Dodaje zagniezdzone menu, ktore wyswietla sie jako opcja i przekierowuje
    // do nastepnego wyboru
    void addSubMenu(const std::string& description, MenuManager nestedMenu);

	// Dodaje nowa opcje do menu z jej opisem i funkcja do wykonania
    void addOption(const std::string& description, const std::function<void()>& action);

    // Metoda wyswietlajaca menu
    void displayMenu(std::string menuDescription = "") const;

	// Metoda uruchamiajaca menu i zajmujaca sie wyborem opcji
    void runMenu();

private:
    //Dynamiczna tablica przechowujaca nazwy opcji menu
    std::vector<std::string> options;

	//Dynamiczna tablica przechowujaca funkcje zwrotne danych opcji
    std::vector<std::function<void()>> funkcjeOpcji; // Nie uzywam wskaznika do funkcji, gdyz w main.cpp korzystam z wyrazen lambda
};