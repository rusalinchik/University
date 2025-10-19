#include <iostream>
#include <cstring>
#include <cctype>

bool isPalindrome(const char* str) {
	int length = strlen(str); 
	for (int i = 0; i < length / 2; ++i) {
		if ((str[i]) != (str[length - i - 1])) {
			return false;
		}
	}
	return true; 
}

int main() {
	setlocale(LC_ALL, "RU");
	const int SIZE = 256;
	char str[SIZE];
	int j = 0;
	std::cout << "Введите строку: ";
	std::cin.getline(str, SIZE);

	for (int i = 0; str[i] != '\0'; i++) {
		if (!isspace(static_cast<unsigned char>(str[i]))) {
			str[j++] = tolower(static_cast<unsigned char>(str[i]));
		}
	}
	str[j] = '\0';

	if (isPalindrome(str)) {
		std::cout << "Палиндромом." << std::endl;
	}
	else {
		std::cout << "НЕ палиндромом." << std::endl;
	}
	return 0;
}