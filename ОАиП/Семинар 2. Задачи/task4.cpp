#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int k;
    cout <<"Введите целое число: ";
    std::cin >> k;
    if (k % 2 == 0)
        cout << "Число " << k << " - чётное";
    else
        cout << "Число " << k << " - нечётное";
    return 0;
}