#pragma once
#include <iostream>

template <class T>
struct item {
	T a;
	T b;
	bool isInQueue;
	item() { a = 0; b = 0; isInQueue = false; };

	T compare() { return a < b ? a : b; };
	void set(T first, T second);
	void print();
};

template<class T>
void item<T>::set(T first, T second)
{
	a = abs(first);
	b = abs(second);
}

template<class T>
void item<T>::print()
{
	std::cout << a << " " << b;
}

template<class T>
size_t findMin(item<T>* mas, size_t n)
{
	T min = -1;
	bool isFirst = true;
	size_t indexMin=0;

	for (size_t i = 0; i < n; i++)
	{
		if (mas[i].isInQueue == false) {
			if (mas[i].compare() < min || isFirst == true) {
				min = mas[i].compare();
				indexMin = i;
				isFirst = false;
			}
		}
	}
	return indexMin;
}

template<class T>
size_t* getQueue(item<T>* mas, size_t n) {
	size_t* queue = new size_t[n];
	size_t index = -1, leftBorder = 0, rightBorder = n - 1;

	while (leftBorder <= rightBorder) {
		index = findMin(mas, n);
		
		if (mas[index].a < mas[index].b) {
			queue[leftBorder] = index;
			leftBorder++;
		}
		else {
			queue[rightBorder] = index;
			rightBorder--;
		}
		mas[index].isInQueue = true;
	}

	return queue;
}

template<class T>
void visual(item<T>* mas, size_t n, size_t* queue) {
	
	int now = 0;
	int firstSum = 0;

	std::cout << "\n";

	for (size_t i = 0; i < n; i++) {
		now = queue[i];

		std::cout << "|";
		for (size_t j = 0; j < mas[now].a; j++) {
			std::cout << "-";
			firstSum++;
		}
	}

	std::cout << " First sum is " << firstSum<<"\n";

	int sumTimeOnFirst = mas[queue[0]].a;
	int sumTimeOnSecond = 0;
	int difference = 0;
	int secondSum = 0;

	for (size_t i = 1; i < n; i++)
	{
		difference = sumTimeOnFirst - sumTimeOnSecond;

		std::cout << "|";
		if (difference > 0) {
			sumTimeOnSecond += difference;
			int count = difference;

			while (count != 0) {
				std::cout << "_";
				count--;
			}
			std::cout << "|";
		}
		else difference = 0;
		

		for (size_t j = 0; j < mas[queue[i-1]].b; j++)
		{
			std::cout << "-";
			secondSum++;
		}

		now = queue[i];
		sumTimeOnFirst += mas[now].a;
		sumTimeOnSecond += mas[queue[i-1]].b;
	}
	difference = sumTimeOnFirst - sumTimeOnSecond;

	std::cout << "|";
	if (difference > 0) {
		sumTimeOnSecond += difference;
		int count = difference;

		while (count != 0) {
			std::cout << "_";
			count--;
		}
		std::cout << "|";
	}
	else difference = 0;

	sumTimeOnSecond += mas[queue[n - 1]].b;
	for (size_t i = 0; i < mas[queue[n-1]].b; i++)
	{
		std::cout << "-";
		secondSum++;
	}

	std::cout <<"| Second sum is "<< secondSum << "\n";

	std::cout << "Out of work is " << sumTimeOnSecond - secondSum << "\n";
}

template<class T>
size_t* rec(item<T>* mas, size_t n) {

}