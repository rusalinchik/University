#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	const int size = 5;
	int mass[size];
	int maxIndex = 0;
	int minIndex = 0;
	cout << "Введите 15 целых чисел";
	for (int i = 0; i < size; i++) {
		cin >> mass[i];
	}
	for (int i = 0; i < size; i++) {
		if (mass[i] < mass[minIndex])
			minIndex = i;
		if (mass[i] > mass[maxIndex])
			maxIndex = i;
	}
	if (mass[minIndex] == 0 || mass[maxIndex] == 0) {
		for (int i = 0; i < minIndex; i++)
			mass[i] = 0;
	}
	for (int i = 0; i < size; i++)
		cout << mass[i];
	return 0;
}