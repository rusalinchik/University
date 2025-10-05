#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	const int size = 15;
	double mass[size];
	int maxIndex = 0;
	int minIndex = 0;
	cout << "Введите 15 чисел: ";
	for (int i = 0; i < size; i++) {
		cin >> mass[i];
	}
	for (int i = 0; i < size; i++) {
		if (mass[i] < mass[minIndex])
			minIndex = i;
		if (mass[i] > mass[maxIndex])
			maxIndex = i;
	}
	if (maxIndex < minIndex) {
		double n = mass[maxIndex] * mass[minIndex];
		cout << "Произведение максимального и минимального элементов = " << n << endl;
	}
	else
		cout << "Максимальный элемент не предшествует минимальному." << endl;
	return 0;
}