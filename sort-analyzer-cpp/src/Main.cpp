#include <iostream>

#include "../headers/BubbleSort.h"
#include <vector>
int main()
{
	BubbleSort bubbleSort;
	std::vector<int> data = { 10, 8, 4, 5, 2, 6, 18, 4 , -9, 0, -0};
	bubbleSort.sort(data);
	for (auto i : data)
		std::cout << i << " ";
}
