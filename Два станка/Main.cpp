#include "Machine.h"

int main() {
	std::cout << "Enter count of items (n>0): ";
	size_t n;
	std::cin >> n;
	item<int>* mas = new item<int>[n];
	int first, second;

	std::cout << "\nEnter time on first and second machine for all items: ";
	for (size_t i = 0; i < n; i++)
	{
		std::cin >> first >> second;
		mas[i].set(first, second);
	}

	size_t* queue = getQueue(mas, n); // אכדמנטעל

	std::cout << "\nI | a b";
	for (size_t i = 0; i < n; i++)
	{
		std::cout << "\n" << i << " | ";
		mas[i].print();
	}
	std::cout << "\n";
	for (size_t i = 0; i < n; i++)
	{
		std::cout << queue[i] << " ";
	}

	visual(mas, n, queue);

	std::cin.ignore().get();
	return 0;
}