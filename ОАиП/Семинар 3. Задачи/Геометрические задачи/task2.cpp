#include <iostream>
#include <cmath>
using namespace std;

double distance(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
	setlocale(LC_ALL, "RU");
	double mass[4][2];
	cout << "Введите координаты 4 вершин  (x, y): " << endl;
	for (int i = 0; i < 4; i++) {
		cout << "Вершина " << i + 1 << " = ";
		cin >> mass[i][0] >> mass[i][1];
	}
	double perimetr = 0.0;
	for (int i = 0; i < 4; i++) {
		int next = (i + 1) % 4;
		perimetr += distance(mass[i][0], mass[i][1], mass[next][0], mass[next][1]);
	}
	cout << "Периметр треугольника: " << perimetr << endl;

	return 0;
}