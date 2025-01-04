#include "../headers/SelectionSort.h"

//Implementacja metody sortowania przez wybieranie
void SelectionSort::sort(std::vector<int>& data)
{
	unsigned int iloscDanych = data.size();
	int temp{};

	//Iteracja po wszystkich elementach
	for (int i = 0; i < iloscDanych - 1; i++)
	{
		//Ustawienie indexu pierwszej wartosci jako index najmniejszej wartosci
		int min = i;

		//Iteracja po pozostalych wartosciach aby odnalezc wlasciwa wartosc najmniejsza
		for (int j = i + 1; j < iloscDanych; j++)
		{
			if (data[j] < data[min])
				//Ustawienie faktycznego indeksu wartosci minimalnej
				min = j;
		}
		//Zamiana miejscami elementu o wartosci najmniejszej z elementem obecnej iteracji jesli sa rozne
		if (min != i) {
			temp = data[i];
			data[i] = data[min];
			data[min] = temp;
		}
	}
}