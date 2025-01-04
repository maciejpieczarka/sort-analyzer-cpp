#pragma once

#include <vector>
#include <string>

class SortAlgorithm {
public:
	//Wirtualny destruktor
	virtual ~SortAlgorithm() {};

	//Czysto wirtualna metoda sortowania do zaimplementowania 
	// w klasach dziedzicz¹cych
	virtual void sort(std::vector<int>& data) = 0;

	//Wirtualna metoda, która zwraca nazwê algorytmu
	virtual std::string getName() const = 0;

	//Wirtualne metody zwracaj¹ce z³o¿onoœæ czasow¹ i pamiêciow¹
	virtual std::string getTComplexity() const = 0;
	virtual std::string getSComplexity() const = 0;
};