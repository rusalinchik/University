#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <time.h>

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));

    int n, A, B;
    std::cout << "Введите количество чисел: ";
    std::cin >> n;

    std::cout << "Введите нижнюю границу диапазона чисел: ";
    std::cin >> A;
    std::cout << "Введите верхнюю границу диапазона чисел: ";
    std::cin >> B;

    if (A > B) {
        std::swap(A, B);
    }

    std::vector<int> v(n);

    for (int& x : v) {
        x = rand() % (B - A + 1) + A;
    }

    std::cout << "Исходный вектор: ";
    for (int x : v) std::cout << x << " ";
    std::cout << std::endl;

    v.erase(std::remove_if(v.begin(), v.end(), [](int x) { return x < 0; }), v.end());

    std::cout << "После удаления отрицательных чисел: ";
    for (int x : v) std::cout << x << " ";
    std::cout << std::endl;

}