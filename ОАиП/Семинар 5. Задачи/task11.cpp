#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>

    int main() {
        setlocale(LC_ALL, "RU");
        std::cout << "На понимаю по условию задачи как создавать вектор??? Надо рандомные значения или пользователь должен вводить или самой значения придумать и присвоить вектору. Здесь будет рандомно, в некоторых задачах, где чисел не так много - вручную. \n\n";
        srand(time(NULL));

        int A, B;
        std::cout << "Введите нижнюю границу диапазона чисел: ";
        std::cin >> A;
        std::cout << "Введите верхнюю границу диапазона чисел: ";
        std::cin >> B;

        if (A > B) std::swap(A, B);

        std::vector<double> vibration(50);
        for (double& x : vibration) {
            x = rand() % (B - A + 1) + A;
        }

        std::cout << "\nВсе значения амплитуд до фильтрации:\n";
        for (double v : vibration) std::cout << v << " ";
        std::cout << "\n";

        vibration.erase(
            std::remove_if(vibration.begin(), vibration.end(),
                [](double v) { return v < 0.1; }),
            vibration.end()
        );

        if (vibration.empty()) {
            std::cout << "\nВсе значения были шумом (<0.1)!\n";
            return 0;
        }

        double avg = std::accumulate(vibration.begin(), vibration.end(), 0.0) / vibration.size();
        double maxVal = *std::max_element(vibration.begin(), vibration.end());
        bool allAboveThreshold = std::all_of(vibration.begin(), vibration.end(),
            [](double v) { return v > 0.5; });

        std::sort(vibration.begin(), vibration.end(), std::greater<double>());
        int count = std::min(10, (int)vibration.size());

        std::cout << "Средняя амплитуда: " << avg << std::endl;
        std::cout << "Максимальная амплитуда: " << maxVal << std::endl;
        std::cout << "Все значения превышают порог 0.5: " << (allAboveThreshold ? "Да" : "Нет") << std::endl;
        std::cout << "10 наибольших амплитуд:";
        for (int i = 0; i < count; i++) std::cout << vibration[i] << " ";
        std::cout << std::endl;

    }