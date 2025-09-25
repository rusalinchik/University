#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int k;
    cout << "Введите число: ";
    cin >> k;
    if (k % 3 == 0 && k % 5 != 0)
        cout << "Число делится на 3";
    else if (k % 3 != 0 && k % 5 == 0)
        cout << "Число делится на 5";
    else if (k % 3 == 0 && k % 5 == 0)
        cout << "Число делится на 3 и 5";
    else
        cout << "Число не делится ни на 3, ни на 5";
    return 0;
}