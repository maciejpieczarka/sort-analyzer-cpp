#include "../headers/MergeSort.h"

void MergeSort::sort(std::vector<int>& data) {
	mergeSort(data);
}

void MergeSort::merge(std::vector<int>& leftArray, std::vector<int>& rightArray, std::vector<int>& data) {
	int leftSize = data.size() / 2;
	int rightSize = data.size() - leftSize;

	int i{}, l{}, r{}; // Indeksy tablic leftArray, rightArray, data

	while (l < leftSize && r < rightSize) {
		// Porownanie elementow z lewej i prawej polowy tablicy
		if (leftArray[l] < rightArray[r]) {
			data[i] = leftArray[l]; // Jesli element z lewej polowy jest mniejszy, to zostaje on dodany do tablicy "data"
			i++;
			l++;
		}
		else {
			data[i] = rightArray[r]; // Jesli element z prawej polowy jest mniejszy, to zostaje on dodany do tablicy "data"
			i++;
			r++;
		}
	}
	while (l < leftSize) {
		data[i] = leftArray[l]; // Jesli w lewej polowie tablicy zostaly jeszcze elementy, to zostaja one dodane do tablicy "data"
		i++;
		l++;
	}

	while (r < rightSize) {
		data[i] = rightArray[r]; // Jesli w prawej polowie tablicy zostaly jeszcze elementy, to zostaja one dodane do tablicy "data"
		i++;
		r++;
	}
};


void MergeSort::mergeSort(std::vector<int>& data) {
	int dataSize = data.size();
	if (dataSize <= 1) return;

	//Zmienna przechowujaca srodkowy index tablicy danych
	int middle = dataSize / 2;

	// Dynamiczne tablice tymczasowe, ktore przechowuja wartosci lewej i prawej
	// polowy tablicy "data"
	std::vector<int> leftArray(middle);
	std::vector<int> rightArray(dataSize - middle);

	int j{};
	for (int i = 0; i < dataSize; ++i) {
		if (i < middle) {
			leftArray[i] = data[i];
		}
		else {
			rightArray[j] = data[i];
			j++;
		}
	}
	mergeSort(leftArray);
	mergeSort(rightArray);
	merge(leftArray, rightArray, data);
}

