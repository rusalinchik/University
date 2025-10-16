#include <iostream>
#include <algorithm>
using namespace std;

int orient(double x1, double y1, double px, double py, double x2, double y2);
bool onseg(double a[2], double b[2], double p[2]);
bool doIntersect(double a[2], double b[2], double c[2], double d[2]);
bool polyIntersect(double mass1[][2], int n1, double mass2[][2], int n2);

int main() {
    setlocale(LC_ALL, "RU");
    int n1, n2;

    cout << "Введите количество вершин первого многоугольника: ";
    cin >> n1;
    double mass1[100][2];
    cout << "Введите координаты вершин первого многоугольника (x y):\n";
    for (int i = 0; i < n1; ++i)
        cin >> mass1[i][0] >> mass1[i][1];

    cout << "Введите количество вершин второго многоугольника: ";
    cin >> n2;
    double mass2[100][2];
    cout << "Введите координаты вершин второго многоугольника (x y):\n";
    for (int i = 0; i < n2; ++i)
        cin >> mass2[i][0] >> mass2[i][1];

    if (polyIntersect(mass1, n1, mass2, n2))
        cout << "Многоугольники пересекаются.\n";
    else
        cout << "Многоугольники не пересекаются.\n";

    return 0;
}

int orient(double x1, double y1, double px, double py, double x2, double y2) {
    double val = (px - x1) * (y2 - y1) - (py - y1) * (x2 - x1);
    if (val > 0) 
        return 1;
    if (val < 0) 
        return -1;  
    return 0;                
}

bool onseg(double a[2], double b[2], double p[2]) {
    return min(a[0], b[0]) <= p[0] && p[0] <= max(a[0], b[0]) &&
        min(a[1], b[1]) <= p[1] && p[1] <= max(a[1], b[1]);
}

bool doIntersect(double a[2], double b[2], double c[2], double d[2]) {
    int o1 = orient(a[0], a[1], c[0], c[1], b[0], b[1]);
    int o2 = orient(a[0], a[1], d[0], d[1], b[0], b[1]);
    int o3 = orient(c[0], c[1], a[0], a[1], d[0], d[1]);
    int o4 = orient(c[0], c[1], b[0], b[1], d[0], d[1]);

    if (o1 != o2 && o3 != o4) return true;

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

bool polyIntersect(double mass1[][2], int n1, double mass2[][2], int n2) {
    for (int i = 0; i < n1; ++i) {
        double a[2] = { mass1[i][0], mass1[i][1] };
        double b[2] = { mass1[(i + 1) % n1][0], mass1[(i + 1) % n1][1] };
        for (int j = 0; j < n2; ++j) {
            double c[2] = { mass2[j][0], mass2[j][1] };
            double d[2] = { mass2[(j + 1) % n2][0], mass2[(j + 1) % n2][1] };
            if (doIntersect(a, b, c, d))
                return true;
        }
    }
    return false;
}