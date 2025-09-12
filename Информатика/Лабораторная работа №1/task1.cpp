#include <iostream>

int main() {
    setlocale(LC_ALL, "rus");
    double speed;
    std::cout << "Введите скорость автомобиля (км/ч):";
    std::cin >> speed;
    if (speed < 0)
        std::cout << "Скорость не может быть отрицательной" << std::endl;
    if (speed < 60) 
        std::cout << "Скорость в пределах нормы" << std::endl;
    else if (speed <= 80) 
        std::cout << "Вы приближаетесь к привышению скорости" << std::endl;
    else 
        std::cout << "Превышение скорости" << std::endl;
    return 0;
}