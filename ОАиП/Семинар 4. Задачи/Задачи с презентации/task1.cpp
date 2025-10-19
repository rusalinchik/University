#include <iostream>
#include <cmath> 

int main() {
    setlocale(LC_ALL, "RU");
    double points[3][3];

    for (int i = 0; i < 3; ++i) {
        std::cout << "Введите координаты точки " << i + 1 << " (x y): ";
        std::cin >> points[i][0] >> points[i][1];
        points[i][2] = 1;
    }

    double det = points[0][0] * (points[1][1] * points[2][2] - points[1][2] * points[2][1])
        - points[0][1] * (points[1][0] * points[2][2] - points[1][2] * points[2][0])
        + points[0][2] * (points[1][0] * points[2][1] - points[1][1] * points[2][0]);

    double S = 0.5 * std::abs(det);

    std::cout << "Площадь треугольника: " << S << std::endl;

    return 0;
}