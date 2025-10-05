#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	const int size = 15;
	double mass[size];
	int minIndex = 0;
	int maxIndex = 0;
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
	for (int i = 0; i < size; i++) {
		if (maxIndex == 0 && minIndex == 1) {
			mass[i] /= 2;
			cout << mass[i] * 2 << " - " << mass[i] << endl;
		} 
		else 
			cout << "Числа не удовлетворяют условию" << endl;
		break;
	}
	return 0;
}