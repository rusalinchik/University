#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int c;
    cout << "Введите целое число: ";
    std::cin >> c;
    for (int i = 1; i <= c; i++) {
        int k = i * i;
        cout << i << " в квадрате = " << k << endl;
    }
    return 0;
}
