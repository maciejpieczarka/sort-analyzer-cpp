#include "../headers/QuickSort.h"

//Implementacja metody sortujacej QuickSort
void QuickSort::sort(std::vector<double>& data) {
	if (data.empty()) return;

	quickSort(data, 0, data.size() - 1);
}

// Rekurencyjna implementacja metody quickSort, ktora sortuje elementy tablicy
void QuickSort::quickSort(std::vector<double>& data, int low, int high) {
	//Bazoowy przypadek rekurencji
	if (low < high) {
		//Znalezienie pivotu
        int pivotIndex = partition(data, low, high);

		//Rekurencyjne wywolanie quickSort dla podtablic lewej i prawej
        quickSort(data, low, pivotIndex - 1);
        quickSort(data, pivotIndex + 1, high);
    }
}

// Metoda partition, ktora dzieli tablice na dwie czesci
int QuickSort::partition(std::vector<double>& data, int low, int high) {
    double pivot = data[high];
	int temp{};

    int i = low - 1;

	//Iteracja po elementach tablicy
	for (int j = low; j < high; ++j) {
		//Jesli element jest mniejszy od pivota, zamieniamy go z elementem na pozycji i+1
		if (data[j] < pivot) {
			++i;
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}

	//Zamiana pivota z elementem na pozycji i+1
	temp = data[i + 1];
	data[i + 1] = data[high];
	data[high] = temp;

	return i + 1;
}