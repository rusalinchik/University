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
    std::cout << "Введите нижнюю границу давления: ";
    std::cin >> A;
    std::cout << "Введите верхнюю границу давления: ";
    std::cin >> B;

    if (A > B) std::swap(A, B);

    std::vector<double> pressure(50);
    for (double& p : pressure) {
        p = A + (rand() % (B - A + 1));
    }

    std::cout << "Все значения давления до фильтрации:\n";
    for (double p : pressure) std::cout << p << " ";
    std::cout << "\n";

    pressure.erase(
        std::remove_if(pressure.begin(), pressure.end(),
            [](double p) { return p < 0 || p > 12; }),
        pressure.end()
    );

    if (pressure.empty()) {
        std::cout << "Все измерения были ошибочными!\n";
        return 0;
    }

    double avg = std::accumulate(pressure.begin(), pressure.end(), 0.0) / pressure.size();
    auto minmax = std::minmax_element(pressure.begin(), pressure.end());
    double minPressure = *minmax.first;
    double maxPressure = *minmax.second;

    std::cout << "Среднее давление: " << avg << " бар\n";
    std::cout << "Минимальное давление: " << minPressure << " бар\n";
    std::cout << "Максимальное давление: " << maxPressure << " бар\n";

    std::cout << "Значения давления, превышающие 8 бар: ";
    std::for_each(pressure.begin(), pressure.end(),
        [](double p) { if (p > 8) std::cout << p << " "; });
    std::cout << std::endl;

}