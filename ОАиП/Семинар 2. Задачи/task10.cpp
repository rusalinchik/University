#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int n;
    cout << "Введите число: ";
    cin >> n;
    if (n < 0)
        cout << "Число отрицательное";
    else if (n == 0)
        cout << "Число равно нулю";
    else
        cout << "Число больше нуля";
    return 0;
}
