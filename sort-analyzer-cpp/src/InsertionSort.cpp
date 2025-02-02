#include "../headers/InsertionSort.h"

void InsertionSort::sort(std::vector<double>& data)
{
	unsigned int iloscDanych = data.size();
	int temp{};
	//Iteracja po wszystkich elementach
	for (int i = 1; i < iloscDanych; i++)
	{
		//Zapamietanie wartosci obecnej iteracji
		temp = data[i];

		//Zapisanie do zmiennej j elementu poprzedzajacego obecny
		int j = i - 1;

		/* Przesun elementy data[0..i-1], ktore sa wieksze niz obecny, 
		o jedna pozycje dalej niz sa obecnie */
		while (j >= 0 && data[j] > temp)
		{
			data[j + 1] = data[j];
			--j;
		}
		//Wstawienie zapamietanej wartosci na wlasciwe miejsce
		data[j + 1] = temp;
	}
}
