#include "../headers/HeapSort.h"

//Metoda sortowania przez kopcowanie
void HeapSort::sort(std::vector<double>& data) {
	int dataSize = data.size();

	buildHeap(data, dataSize);

	for (size_t i = dataSize - 1; i > 0; --i) {
		int temp = data[0];
		data[0] = data[i];
		data[i] = temp;
		heapify(data, i, 0);
	}
};

void HeapSort::heapify(std::vector<double>& data, int dataSize, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < dataSize && data[left] > data[largest]) {
		largest = left;
	}

	if (right < dataSize && data[right] > data[largest]) {
		largest = right;
	}

	if (largest != i) {
		int temp = data[i];
		data[i] = data[largest];
		data[largest] = temp;

		heapify(data, dataSize, largest);
	}
};

//Metoda budowania kopca
void HeapSort::buildHeap(std::vector<double>& data, int dataSize) {
	for (int i = dataSize / 2 - 1; i >= 0; --i) {
		heapify(data, dataSize, i);
	}
};