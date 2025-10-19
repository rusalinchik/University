#include <iostream>
#include <cstring>
#include <cctype>

int main() {
	setlocale (LC_ALL, "RU");
	int count = 0;
	const int SIZE = 256;
	char str[SIZE];
	std::cout << "Введите строку: ";
	std::cin.getline(str, SIZE);
	for (int i = 0; str[i] != '\0'; i++) {
		str[i] = tolower(static_cast<unsigned char>(str[i]));
	}
	
	for (int i = 0; str[i] != '\0'; i++) {
		bool before = false;
		for (int j = 0; j < i; j++) {
			if (str[i] == str[j]) {
				before = true;
				break;
			}
		}
		if (!before) {
			count++;
		}
	}
	std::cout << "Различных символов: " << count << std::endl;
	return 0;
}