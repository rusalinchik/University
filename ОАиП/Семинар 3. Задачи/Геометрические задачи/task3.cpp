#include <iostream>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	double mass[3][2];
	cout << "Введите координаты 4 вершин треугольника (x, y): " << endl;
	for (int i = 0; i < 4; i++) {
		cout << "Вершина " << i + 1 << " = ";
		cin >> mass[i][0] >> mass[i][1];
	}
	double x1 = mass[0][0], y1 = mass[0][1];
	double x2 = mass[1][0], y2 = mass[1][1];
	double x3 = mass[2][0], y3 = mass[2][1];
	double centerX = (x1 + x2 + x3) / 3;
	double centerY = (y1 + y2 + y3) / 3;

	cout << "Координаты центра масс треугольника: (" << centerX << "; " << centerY << ")" << endl;

	return 0;
}
