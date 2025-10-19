#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));

    int A, B;
    std::cout << "Введите нижнюю границу уровня топлива: ";
    std::cin >> A;
    std::cout << "Введите верхнюю границу уровня топлива: ";
    std::cin >> B;

    if (A > B) std::swap(A, B);

    std::vector<double> fuel(50);
    for (double& f : fuel) {
        f = rand() % (B - A + 1) + A;
    }

    std::cout << "\nВсе значения уровня топлива:\n";
    for (double f : fuel) std::cout << f << " ";
    std::cout << "\n";

    double minFuel = *std::min_element(fuel.begin(), fuel.end());
    double maxFuel = *std::max_element(fuel.begin(), fuel.end());
    bool below5Percent = std::any_of(fuel.begin(), fuel.end(),
        [maxFuel](double f) { return f < 0.05 * maxFuel; });
    double avgConsumption = fuel.front() - fuel.back();

    std::vector<double> sortedFuel = fuel;
    std::sort(sortedFuel.begin(), sortedFuel.end());
    double median;
    int n = sortedFuel.size();
    if (n % 2 == 0)
        median = (sortedFuel[n / 2 - 1] + sortedFuel[n / 2]) / 2.0;
    else
        median = sortedFuel[n / 2];

    std::cout << "Минимальный уровень топлива: " << minFuel << std::endl;
    std::cout << "Был ли уровень ниже 5% от максимального: " << (below5Percent ? "Да" : "Нет") << std::endl;
    std::cout << "Среднее потребление (начальное - конечное): " << avgConsumption << std::endl;
    std::cout << "Медиана уровня топлива: " << median << std::endl;

}