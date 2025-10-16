#include <iostream>
#include <cmath>
using namespace std;

int orient(double x1, double y1, double x2, double y2, double px, double py);
bool inside(double dots[][2], int n, double px, double py);

int main() {
    setlocale(LC_ALL, "RU");
    int n;
    double px, py;

    cout << "Введите количество вершин: ";
    cin >> n;

    double dots[100][2];
    cout << "Введите координаты вершин (x y):\n";
    for (int i = 0; i < n; ++i)
        cin >> dots[i][0] >> dots[i][1];

    cout << "Введите координаты точки (x y): ";
    cin >> px >> py;

    if (inside(dots, n, px, py))
        cout << "YES (точка внутри или на границе)\n";
    else
        cout << "NO (точка снаружи)\n";

    return 0;
}

int orient(double x1, double y1, double x2, double y2, double px, double py) {
    double val = (x2 - x1) * (py - y1) - (y2 - y1) * (px - x1);
    if (val > 0) return 1;
    if (val < 0) return -1;
    return 0;                
}

bool inside(double dots[][2], int n, double px, double py) {
    int sign = 0;

    for (int i = 0; i < n; ++i) {
        int r = orient(
            dots[i][0], dots[i][1],
            dots[(i + 1) % n][0], dots[(i + 1) % n][1],
            px, py
        );

        if (r == 0)
            return true; 
        else if (sign == 0)
            sign = r; 
        else if (r != sign)
            return false; 
    }

    return true;
}