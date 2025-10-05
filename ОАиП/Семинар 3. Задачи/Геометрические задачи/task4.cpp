#include <iostream>
#include <cmath>
using namespace std;

double distance(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
	setlocale(LC_ALL, "RU");
	double mass[4][2];
	cout << "Введите координаты 4 вершин прямоугольника: ";
	for (int i = 0; i < 4; i++) {
		cin >> mass[i][0] >> mass[i][1];
	}
	double diagonal = 0.0;
	diagonal = distance(mass[0][0], mass[0][1], mass[2][0], mass[2][1]);
	cout << "Диагональ прямоугольника: " << diagonal;
	return 0;
}