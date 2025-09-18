#include <iostream>

int main() {
	setlocale(LC_ALL, "RU");
	int car;
	unsigned long long p = 1;
	int counter = 1;
	std::cout << "Введите кол-во автомобилей, произведённых на фабрике:";
	std::cin >> car;
	if (car < 0) {
		std::cout << "Количество машин не может быть отрицательное!";
		return 1;
	}
	while (counter <= car) {
		p *= counter;
		counter++;
	}
	std::cout << "Производительность машин на фабрике: " << p;
	return 0;
}