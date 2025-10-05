#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	const int n = 15;
	double mass[n];
	int maxIndex = 0;
	int minIndex = 0;
	cout << "Ведите 15 чисел последовательности: ";
	for (int i = 0; i < n; i++) {
		cin >> mass[i];
	}
	for (int i = 0; i < n; i++) {
		if (mass[i] < mass[minIndex])
			minIndex = i;
	}
	swap(mass[0], mass[minIndex]);
	for (int i = 0; i < n; i++) {
		if (mass[i] > mass[maxIndex])
			maxIndex = i;
	}
	swap(mass[n - 1], mass[maxIndex]);
	for (int i = 0; i < n; i++)
		cout << mass[i] << " ";
	return 0;
}