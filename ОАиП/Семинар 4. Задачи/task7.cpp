#include <iostream>

int main() {
    double a1 = 1, b1 = 1, c1 = 1, d1 = 6;
    double a2 = 2, b2 = -1, c2 = 3, d2 = 14;
    double a3 = -1, b3 = 4, c3 = -1, d3 = 2;

    double D = a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);

    if (D == 0) {
        std::cout << "Система не имеет единственного решения.\n";
        return 0;
    }

    double Dx = d1 * (b2 * c3 - b3 * c2) - b1 * (d2 * c3 - d3 * c2) + c1 * (d2 * b3 - d3 * b2);
    double Dy = a1 * (d2 * c3 - d3 * c2) - d1 * (a2 * c3 - a3 * c2) + c1 * (a2 * d3 - a3 * d2);
    double Dz = a1 * (b2 * d3 - b3 * d2) - b1 * (a2 * d3 - a3 * d2) + d1 * (a2 * b3 - a3 * b2);

    double x = Dx / D;
    double y = Dy / D;
    double z = Dz / D;

    std::cout << "x = " << x << "\n";
    std::cout << "y = " << y << "\n";
    std::cout << "z = " << z << "\n";

    return 0;
}