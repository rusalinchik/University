#include <iostream>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	int n;
	int count = 0;
	cout << "Введите число, которое будет задавать количество членов последовательности: ";
	cin >> n;
	cout << "Ведите сами числа: ";
	for (int k = 1; k <= n; k++) {
		int A;
		cin >> A;
		if (A > pow(2, k))
			count++;
	}
	cout << "Количество членов, удовлетворяющих условию = " << count << endl;
	return 0;
}