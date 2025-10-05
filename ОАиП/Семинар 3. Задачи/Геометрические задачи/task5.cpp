#include <iostream>
#include <cmath>
using namespace std;

bool Colliner(double x1, double y1, double x2, double y2, double x3, double y3) {
	int crossProduct = (x2 - x1) * (y3 - y1) * (y2 - y1) - (y2 - y1) * (x3 - x1);
	return crossProduct == 0;
}

int main() {
	setlocale(LC_ALL, "RU");
	int mass[3][2];
	cout << "Введите координаты 3 точек x,y " << endl;
	for (int i = 0; i < 3; i++) {
		cout << "Вершина " << i + 1 << " = ";
		cin >> mass[i][0] >> mass[i][1];
	}
	if (Colliner(mass[0][0], mass[0][1], mass[1][0], mass[1][1], mass[2][0], mass[2][1])) {
		cout << "Точки лежат на одной прямой" << endl;
	}
	else 
		cout << "Точки не лежат на одной прямой" << endl;
	return 0;
}
