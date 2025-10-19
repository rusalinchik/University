#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    setlocale(LC_ALL, "RU");
    std::vector<double> consumption(30);

    std::cout << "Введите потребление энергии за 30 дней (кВт·ч):\n";
    for (int i = 0; i < 30; i++) {
        std::cin >> consumption[i];
    }

    double total = std::accumulate(consumption.begin(), consumption.end(), 0.0);
    double average = total / consumption.size();

    auto minIt = std::min_element(consumption.begin(), consumption.end());
    auto maxIt = std::max_element(consumption.begin(), consumption.end());

    std::vector<double> peakDays;
    for (double val : consumption) {
        if (val > average * 1.2) {
            peakDays.push_back(val);
        }
    }

    std::cout << "\nОбщее потребление за месяц: " << total << " кВт·ч";
    std::cout << "\nСреднесуточное потребление: " << average << " кВт·ч";
    std::cout << "\nМинимальное потребление: " << *minIt << " кВт·ч";
    std::cout << "\nМаксимальное потребление: " << *maxIt << " кВт·ч";

    std::cout << "\nПиковые дни (больше на 20% среднего): ";
    for (double val : peakDays) std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}