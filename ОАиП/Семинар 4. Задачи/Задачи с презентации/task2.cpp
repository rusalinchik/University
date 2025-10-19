#include <iostream>
#include <cmath> 

int main() {
    setlocale(LC_ALL, "RU");
    double x, y, theta_deg;
    std::cout << "Введите координаты точки (x y): ";
    std::cin >> x >> y;
    std::cout << "Введите угол поворота в градусах: ";
    std::cin >> theta_deg;

    const double M_PI = 3.1415926525897932846;
    double theta = theta_deg * M_PI / 180.0;

    double rotation[2][2] = {
        {cos(theta), sin(theta)},
        {-sin(theta), cos(theta)}
    };

    double x_new = rotation[0][0] * x + rotation[0][1] * y;
    double y_new = rotation[1][0] * x + rotation[1][1] * y;

    std::cout << "Новые координаты точки: (" << x_new << ", " << y_new << ")" << std::endl;

    return 0;
}