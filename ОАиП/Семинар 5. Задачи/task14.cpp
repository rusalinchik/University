#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <cmath>

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));

    std::vector<int> consumption(24);
    for (int& c : consumption) {
        c = 100 + rand() % 401; 
    }

    std::cout << "Энергопотребление по часам:\n";
    for (int i = 0; i < 24; i++) {
        std::cout << "Час " << i << ": " << consumption[i] << " кВт·ч\n";
    }

    double total = std::accumulate(consumption.begin(), consumption.end(), 0.0);
    double average = total / consumption.size();

    auto maxIt = std::max_element(consumption.begin(), consumption.end());
    int peakHour = std::distance(consumption.begin(), maxIt);

    std::vector<double> deviation(consumption.size());
    std::transform(consumption.begin(), consumption.end(), deviation.begin(),
        [average](double c) { return std::abs(c - average); });

    std::vector<double> sortedDeviation = deviation;
    std::sort(sortedDeviation.begin(), sortedDeviation.end());

    std::cout << "\nСуммарное потребление: " << total << " кВт·ч\n";
    std::cout << "Среднее потребление: " << average << " кВт·ч\n";
    std::cout << "Час пикового потребления: " << peakHour << " (" << *maxIt << " кВт·ч)\n";

    std::cout << "Отклонение каждого часа от среднего:\n";
    for (int i = 0; i < 24; i++) {
        std::cout << "Час " << i << ": " << deviation[i] << "\n";
    }

    std::cout << "\nТоп-5 минимальных часов по отклонению от среднего:\n";
    for (int i = 0; i < 5 && i < sortedDeviation.size(); i++) {
        std::cout << sortedDeviation[i] << " ";
    }
    std::cout << std::endl;

}