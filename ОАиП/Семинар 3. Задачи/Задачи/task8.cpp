#include <iostream>
using namespace std;

int main() {
	setlocale (LC_ALL, "RU");
	const int size = 10;
	int mass[size];
	int minIndex = 0;
	int maxIndex = 0;
	cout << "Введите 10 целых чисел: "; 
	for (int i = 0; i < size; i++) {
		cin >> mass[i];
	}
	for (int i = 0; i < size; i++) {
		if (mass[i] < mass[minIndex])
			minIndex = i;
		if (mass[i] > mass[maxIndex])
			maxIndex = i;
	}
	if (maxIndex == 1 && minIndex == 4) {
		for (int i = 5; i < size; i++) {
			mass[i] = mass[maxIndex];
		}
		cout << "Максимальный и минимальный элемент удовлетворяют условию" << endl;
		for (int i = 0; i < size; i++) {
			cout << mass[i] << " ";
		}
	}
	else
		cout << "Максимальный и минимальный элемент не удовлетворяют условию";

	return 0;
}