#include "../headers/BubbleSort.h"

void BubbleSort::sort(std::vector<int>& data) {
	int size = data.size();
	int temp{};
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (data[j] > data[j + 1]) {
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}