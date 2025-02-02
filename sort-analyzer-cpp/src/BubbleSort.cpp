#include "../headers/BubbleSort.h"

//Implementacja metody sortowania babelkowego
void BubbleSort::sort(std::vector<double>& data) {
	unsigned int iloscDanych = data.size();
	int temp{};

	//Iteracja po wszystkich elementach
	for (int i = 0; i < iloscDanych - 1; i++) {

		//Wewnetrzna iteracja po elementach, ktora przesuwa najwieksza wartosc na koniec
		for (int j = 0; j < iloscDanych - i - 1; j++) {

			//Zamiana miejscami elementow jesli sa w zlej kolejnosci
			if (data[j] > data[j + 1]) {
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}