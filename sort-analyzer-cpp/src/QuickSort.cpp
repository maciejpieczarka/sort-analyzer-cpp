#include "../headers/QuickSort.h"

void QuickSort::sort(std::vector<double>& data) {
	if (data.empty()) return;

	quickSort(data, 0, data.size() - 1);
}

// Rekurencyjna implementacja metody quickSort, ktoora sortuje elementy tablicy
void QuickSort::quickSort(std::vector<double>& data, int low, int high) {
    if (low < high) {
        //TODO: komentarz
        int pivotIndex = partition(data, low, high);

		// TODO: komentarz
        quickSort(data, low, pivotIndex - 1);
        quickSort(data, pivotIndex + 1, high);
    }
}

int QuickSort::partition(std::vector<double>& data, int low, int high) {
    int pivot = data[high];
	int temp{};

    int i = low - 1;

	for (int j = low; j < high; ++j) {
		if (data[j] < pivot) {
			++i;
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}

	temp = data[i + 1];
	data[i + 1] = data[high];
	data[high] = temp;

	return i + 1;
}