#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	const int size = 10;
	int mass[size];
	int maxIndex = 0;
	int minIndex = 0;
	cout << "Введите 10 натуральных чисел: ";
	for (int i = 0; i < size; i++) {
		cin >> mass[i];
	}
	for (int i = 0; i < size; i++) {
		if (mass[i] < mass[minIndex])
			minIndex = i;
		if (mass[i] > mass[maxIndex])
			maxIndex = i;
	}
	if (minIndex == 4 && maxIndex == 9) {
		double k = (mass[maxIndex] + mass[minIndex]) / 2.0;
		cout << "Среднее арифметическое минимального и максимального элементов = " << k;
	}
	else
		cout << "Максимальный и минимальный элемент не стоят на 10 и 5 месте.";
	return 0;
}