#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    setlocale(LC_ALL, "RU");
    std::vector<int> speed(50);

    std::cout << "Введите 50 скоростей (от 0 до 180):\n";
    for (int i = 0; i < 50; i++) {
        std::cin >> speed[i];
    }

    speed.erase(
        std::remove_if(speed.begin(), speed.end(),
            [](int v) { return v > 120; }),
        speed.end()
    );

    if (speed.empty()) {
        std::cout << "\nВсе значения превышали 120!\n";
        return 0;
    }

    double avg = std::accumulate(speed.begin(), speed.end(), 0.0) / speed.size();

    bool allMoving = std::all_of(speed.begin(), speed.end(),
        [](int v) { return v > 0; });

    std::sort(speed.begin(), speed.end(), std::greater<int>());
    int count = std::min(10, (int)speed.size());

    std::cout << "\nСкорости после фильтрации <=120:\n";
    for (int v : speed) std::cout << v << " ";
    std::cout << "\nСредняя скорость: " << avg;
    std::cout << "\nВсе скорости > 0: " << (allMoving ? "Да" : "Нет");
    std::cout << "\n10 максимальных скоростей:\n";
    for (int i = 0; i < count; i++) std::cout << speed[i] << " ";
    std::cout << std::endl;

}