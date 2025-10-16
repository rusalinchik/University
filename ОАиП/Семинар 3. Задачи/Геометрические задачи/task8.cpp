#include <iostream>
#include <cmath>
using namespace std;

double length(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    setlocale(LC_ALL, "RU");
    double x1, y1, x2, y2;
    cout << "Введите координаты первой точки (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Введите координаты второй точки (x2 y2): ";
    cin >> x2 >> y2;
    double l = length(x1, y1, x2, y2);
    cout << "Длина отрезка: " << l << endl;
    return 0;
}
