#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	double length;
	cout << "Введите длину в сантиметрах: ";
	cin >> length;
	int m = length / 100;
	double c = length - m*100;
	cout << "Количество полных метров: " << m << endl;
	cout << "Количество оставшихся сантиметров: " << c << endl;
	return 0;
}