#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <windows.h>

class MenuManager {
public:
	//Metoda odpowiadajaca za wyswietlenie menu glownego
	void displayMenu();

private:
	//Metoda odpowiadajaca za wyswietlenie instrukcji aplikacji
	void displayInstruction();

	//Metoda odpowiadajaca za wyswietlenie menu porownania algorytmow
	void displayComparisonMenu();
};