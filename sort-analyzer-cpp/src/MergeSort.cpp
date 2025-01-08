#include "../headers/MergeSort.h"

void MergeSort::merge(std::vector<int>& data, int left, int mid, int right) {
	int leftSize = mid - left + 1;
	int rightSize = right - mid;

	//Tymczasowe tablice dynamiczne do przechowania prawej i lewej czesci danych
	std::vector<int> leftArray(leftSize);
	std::vector<int> rightArray(rightSize);

	//Kopiowanie danych do tablic tymczasowych
	for (size_t i = 0; i < leftSize; ++i) {
		leftArray[i] = data[left + i];
	}
	for (size_t i = 0; i < rightSize; ++i) {
		rightArray[i] = data[mid + 1 + i];
	}

	int i{}, j{}, k{ left };

	while (i < leftSize && j < rightSize) {
		if (leftArray[i] <= rightArray[j]) {
			data[k] = leftArray[i];
			++i;
		}
		else {
			data[k] = rightArray[j];
			++j;
		}
		++k;
	}

	while (i < leftSize) {
		data[k] = leftArray[i];
		++i;
		++k;
	}

	while (j < rightSize) {
		data[k] = rightArray[j];
		++j;
		++k;
	}
};

void MergeSort::mergeSort(std::vector<int>& data, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		// Sort the left half
		mergeSort(data, left, mid);

		// Sort the right half
		mergeSort(data, mid + 1, right);

		// Merge the sorted halves
		merge(data, left, mid, right);
	}
}

void MergeSort::sort(std::vector<int>& data) {
	mergeSort(data, 0, data.size() - 1);
}