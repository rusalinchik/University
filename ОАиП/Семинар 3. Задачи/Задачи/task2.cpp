#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	int n, k;
	int max = 0;
	int even = 0;
	cout << "Введите количество чисел: ";
	cin >> n;
	cout << "Введите сами числа: ";
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k % 2 == 0) 
			even++;
		else {
			if (k > max)
				max = k;
		}
	}
	if (max == 0)
		cout << "Нечётных натуральных чисел в последовательности нет." << endl;
	else
		cout << "Наибольшее нечётное число = " << max << endl;
	cout << "Количество чётных чисел = " << even << endl;

}