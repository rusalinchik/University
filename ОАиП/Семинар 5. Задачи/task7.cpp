#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    setlocale(LC_ALL, "RU");
    int n;
    std::cout << "Введите количество температур: ";
    std::cin >> n;

    std::vector<double> temps(n);

    std::cout << "Введите " << n << " температур(ы): ";
    for (int i = 0; i < n; i++) {
        std::cin >> temps[i];
    }

    temps.erase(
        std::remove_if(temps.begin(), temps.end(),
            [](double t) { return t < -50 || t > 50; }),
        temps.end()
    );

    if (temps.empty()) {
        std::cout << "Все значения вне диапазона [-50, 50]" << std::endl;
        return 0;
    }

    double avg = std::accumulate(temps.begin(), temps.end(), 0.0) / temps.size();

    std::vector<double>::iterator minIt = std::min_element(temps.begin(), temps.end());
    std::vector<double>::iterator maxIt = std::max_element(temps.begin(), temps.end());

    bool allAbove = std::all_of(temps.begin(), temps.end(),
        [](double t) { return t > -10; });

    std::cout << "После фильтрации диапазона [-50, 50]: ";
    for (double t : temps) std::cout << t << " ";
    std::cout << "\nСредняя температура: " << avg;
    std::cout << "\nМинимальная температура: " << *minIt;
    std::cout << "\nМаксимальная температура: " << *maxIt;
    std::cout << "\nВсе температуры выше -10: " << (allAbove ? "Да" : "Нет") << std::endl;

}