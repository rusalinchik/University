#include <iostream>
#include <cstring>

int main() {
    setlocale(LC_ALL, "RU");
    const int SIZE = 256;
    char str[SIZE];

    std::cout << "Введите строку: ";
    std::cin.getline(str, SIZE);

    int len = std::strlen(str);
    int start = 0;

    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            if (i > start) { 
                for (int j = start; j < i; j++)
                    std::cout << str[j];
                std::cout << std::endl;
            }
            start = i + 1; 
        }
    }

    return 0;
}