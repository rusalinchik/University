#include <iostream>
#include <algorithm>
using namespace std;

double orient(double a[2], double b[2], double c[2]);
bool onseg(double a[2], double b[2], double p[2]);
bool intersect(double a[2], double b[2], double c[2], double d[2]);
bool interpoint(double a[2], double b[2], double c[2], double d[2], double p[2]);

int main() {
    setlocale(LC_ALL, "RU");
    double a[2], b[2], c[2], d[2];
    cout << "Введите координаты точек A(x1 y1), B(x2 y2), C(x3 y3), D(x4 y4):\n";
    cout << "Точка А: ";
    cin >> a[0] >> a[1];
    cout << "Точка B: ";
    cin >> b[0] >> b[1];
    cout << "Точка C: ";
    cin >> c[0] >> c[1];
    cout << "Точка D: ";
    cin >> d[0] >> d[1];

    if (intersect(a, b, c, d)) {
        cout << "Отрезки пересекаются.\n";
        double p[2];
        if (interpoint(a, b, c, d, p)) {
            if (onseg(a, b, p) && onseg(c, d, p))
                cout << "Точка пересечения: (" << p[0] << ", " << p[1] << ")\n";
        }
    }
    else {
        cout << "Отрезки не пересекаются.\n";
    }

    return 0;
}

double orient(double a[2], double b[2], double c[2]) {
    return (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0]);
}

bool onseg(double a[2], double b[2], double p[2]) {
    return min(a[0], b[0]) <= p[0] && p[0] <= max(a[0], b[0]) &&
        min(a[1], b[1]) <= p[1] && p[1] <= max(a[1], b[1]);
}

bool intersect(double a[2], double b[2], double c[2], double d[2]) {
    double o1 = orient(a, b, c);
    double o2 = orient(a, b, d);
    double o3 = orient(c, d, a);
    double o4 = orient(c, d, b);

    if (o1 * o2 < 0 && o3 * o4 < 0)
        return true;

    if (o1 == 0 && onseg(a, b, c)) 
        return true;
    if (o2 == 0 && onseg(a, b, d)) 
        return true;
    if (o3 == 0 && onseg(c, d, a)) 
        return true;
    if (o4 == 0 && onseg(c, d, b)) 
        return true;

    return false;
}

bool interpoint(double a[2], double b[2], double c[2], double d[2], double p[2]) {
    double A1 = b[1] - a[1];
    double B1 = a[0] - b[0];
    double C1 = A1 * a[0] + B1 * a[1];

    double A2 = d[1] - c[1];
    double B2 = c[0] - d[0];
    double C2 = A2 * c[0] + B2 * c[1];

    double det = A1 * B2 - A2 * B1;
    if (det == 0)
        return false;

    p[0] = (B2 * C1 - B1 * C2) / det;
    p[1] = (A1 * C2 - A2 * C1) / det;
    return true;
}