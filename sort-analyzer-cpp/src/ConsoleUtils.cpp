#include "../headers/ConsoleUtils.h"
#include <iostream>

void ConsoleUtils::clear() {
        #if defined _WIN32
                std::system("cls");
                //clrscr(); // including header file : conio.h
        #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                std::system("clear");
                //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
        #elif defined (__APPLE__)
                std::system("clear");
        #endif
}

bool ConsoleUtils::DBStatus = false;