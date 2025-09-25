#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int n;
    int k = 0;
    cout << "Введите число: ";
    cin >> n;
    for (int i = 0; i <= n; i++) {
        if (i % 2 == 0 || i % 5 == 0)
            k += i;
    }
    cout << "Сумма чисел, которая делится на 5 или на 2 = "<< k;
    return 0;
}

