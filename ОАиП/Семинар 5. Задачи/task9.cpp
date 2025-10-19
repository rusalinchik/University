#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    setlocale(LC_ALL, "RU");
    std::vector<double> power(20);

    std::cout << "Введите 20 измерений мощности двигателя (в кВт):\n";
    for (int i = 0; i < 20; i++) {
        std::cin >> power[i];
    }

    power.erase(
        std::remove_if(power.begin(), power.end(),
            [](double p) { return p < 0; }),
        power.end()
    );

    if (power.empty()) {
        std::cout << "\nВсе значения были отрицательными!\n";
        return 0;
    }

    double minPower = *std::min_element(power.begin(), power.end());
    double maxPower = *std::max_element(power.begin(), power.end());
    double avgPower = std::accumulate(power.begin(), power.end(), 0.0) / power.size();
    bool inRange = std::all_of(power.begin(), power.end(),
        [](double p) { return p >= 10 && p <= 90; });

    std::vector<double> sortedPower = power;
    std::sort(sortedPower.begin(), sortedPower.end());
    double median;
    int n = sortedPower.size();
    if (n % 2 == 0)
        median = (sortedPower[n / 2 - 1] + sortedPower[n / 2]) / 2.0;
    else
        median = sortedPower[n / 2];

    std::cout << "\nМинимальная мощность: " << minPower << " кВт";
    std::cout << "\nМаксимальная мощность: " << maxPower << " кВт";
    std::cout << "\nСредняя мощность: " << avgPower << " кВт";
    std::cout << "\nДвигатель работал в диапазоне 10-90 кВт: " << (inRange ? "Да" : "Нет");
    std::cout << "\nМедиана мощности: " << median << " кВт" << std::endl;

}