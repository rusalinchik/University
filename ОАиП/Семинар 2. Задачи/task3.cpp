#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    double c;
    cout << "Введите температуру в градусах Цельсия: ";
    cin >> c;
    double f = c * 1.8 + 32;
    cout << "Температура в градусах по Фаренгейту: "<< f;
    return 0;
}
