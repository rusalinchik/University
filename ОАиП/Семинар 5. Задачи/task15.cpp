#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));

    const int t_ch = 5;
    const int t_m = 30;
    const int p_ch = 5;
    const int p_m = 100;

    double t_min, t_max;
    std::cout << "Введите нижнюю границу температуры: ";
    std::cin >> t_min;
    std::cout << "Введите верхнюю границу температуры: ";
    std::cin >> t_max;
    if (t_min > t_max) std::swap(t_min, t_max);

    double p_min, p_max;
    std::cout << "Введите нижнюю границу давления: ";
    std::cin >> p_min;
    std::cout << "Введите верхнюю границу давления: ";
    std::cin >> p_max;
    if (p_min > p_max) std::swap(p_min, p_max);

    std::vector<std::vector<double>> temp(t_ch, std::vector<double>(t_m));
    std::vector<std::vector<double>> press(p_ch, std::vector<double>(p_m));

    for (int i = 0; i < t_ch; i++)
        for (int j = 0; j < t_m; j++)
            temp[i][j] = t_min + (rand() / (RAND_MAX + 1.0)) * (t_max - t_min);

    for (int i = 0; i < p_ch; i++)
        for (int j = 0; j < p_m; j++)
            press[i][j] = p_min + (rand() / (RAND_MAX + 1.0)) * (p_max - p_min);

    std::vector<double> avg_t(t_ch);
    for (int i = 0; i < t_ch; i++)
        avg_t[i] = std::accumulate(temp[i].begin(), temp[i].end(), 0.0) / t_m;

    std::vector<double> t_var(t_ch);
    for (int i = 0; i < t_ch; i++) {
        auto mm = std::minmax_element(temp[i].begin(), temp[i].end());
        t_var[i] = *mm.second - *mm.first;
    }
    int max_var_ch = std::distance(t_var.begin(), std::max_element(t_var.begin(), t_var.end()));

    std::vector<std::pair<double, double>> p_mm(p_ch);
    for (int i = 0; i < p_ch; i++) {
        auto mm = std::minmax_element(press[i].begin(), press[i].end());
        p_mm[i] = { *mm.first, *mm.second };
    }

    std::vector<std::vector<double>> t_diff(t_ch, std::vector<double>(t_m - 1));
    for (int i = 0; i < t_ch; i++)
        std::transform(temp[i].begin(), temp[i].end() - 1, temp[i].begin() + 1, t_diff[i].begin(),
            [](double a, double b) { return b - a; });

    std::vector<std::vector<double>> p_diff(p_ch, std::vector<double>(p_m - 1));
    for (int i = 0; i < p_ch; i++)
        std::transform(press[i].begin(), press[i].end() - 1, press[i].begin() + 1, p_diff[i].begin(),
            [](double a, double b) { return b - a; });

    std::vector<std::vector<double>> p_norm(p_ch, std::vector<double>(p_m));
    for (int i = 0; i < p_ch; i++) {
        double minp = p_mm[i].first;
        double maxp = p_mm[i].second;
        std::transform(press[i].begin(), press[i].end(), p_norm[i].begin(),
            [minp, maxp](double val) { return (val - minp) / (maxp - minp); });
    }

    std::cout << "\nТемпературы всех каналов:\n";
    for (int i = 0; i < t_ch; i++) {
        std::cout << "Канал " << i << ": ";
        for (double v : temp[i]) std::cout << v << " ";
        std::cout << "\n";
    }

    std::cout << "\nДавление всех каналов:\n";
    for (int i = 0; i < p_ch; i++) {
        std::cout << "Канал " << i << ": ";
        for (double v : press[i]) std::cout << v << " ";
        std::cout << "\n";
    }

    std::cout << "\nЗначения давления после нормализации (>0.9):\n";
    for (int i = 0; i < p_ch; i++) {
        std::for_each(p_norm[i].begin(), p_norm[i].end(),
            [](double val) { if (val > 0.9) std::cout << val << " "; });
        std::cout << "\n";
    }

    std::vector<std::pair<double, int>> avg_t_idx(t_ch);
    for (int i = 0; i < t_ch; i++)
        avg_t_idx[i] = { avg_t[i], i };

    std::sort(avg_t_idx.begin(), avg_t_idx.end());
    std::cout << "\nКанал с максимальной средней температурой: "
        << avg_t_idx.back().second << " (" << avg_t_idx.back().first << ")\n";

    std::cout << "\nСредние температуры каналов:\n";
    for (int i = 0; i < t_ch; i++)
        std::cout << "Канал " << i << ": " << avg_t[i] << "\n";

    std::cout << "Канал с наибольшей вариацией температуры: " << max_var_ch << "\n";

    std::cout << "\nМинимальное и максимальное давление каждого канала:\n";
    for (int i = 0; i < p_ch; i++)
        std::cout << "Канал " << i << ": min=" << p_mm[i].first
        << ", max=" << p_mm[i].second << "\n";

}