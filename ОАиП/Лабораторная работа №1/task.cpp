#include <iostream>

int main() {
	setlocale(LC_ALL, "RU");
	const int size = 10;
	int mass[size];
	int sum = 0;
	int max = mass[0];
	std::cout << "Введите 10 целых чисел: ";
	for (int i = 0; i < size; i++) {
		std::cin >> mass[i];
	}
	std::cout << "Элементы массива: ";
	for (int i = 0; i < size; i++) {
		std::cout << mass[i]<< " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < size; i++) {
		sum += mass[i];
	}
	std::cout << "Сумма элементов массива: " << sum << std::endl;
	for (int i = 0; i < size; i++) {
		if (mass[i] > max) {
			max = mass[i];
		}
	}
	std::cout << "Максимальный элемент массива: " << max << std::endl;
	for (int i = 0; i < size - 1; i++) {
		int maxIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (mass[j] > mass[maxIndex]) {
				maxIndex = j;
			}
		}
		int temp = mass[i];
		mass[i] = mass[maxIndex];
		mass[maxIndex] = temp;
	}
	std::cout << "Отсортированные элементы массива по убыванию: ";
	for (int i = 0; i < size; i++) {
		std::cout << mass[i] << " ";
	}
	std::cout<< std::endl;
	return 0;
}