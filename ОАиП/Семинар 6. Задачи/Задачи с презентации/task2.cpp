#include <iostream>
#include <cstring>

int main() {
    setlocale(LC_ALL, "RU");
    const int SIZE = 256;
    char str[SIZE];
    char ch;

    std::cout << "Введите строку: ";
    std::cin.getline(str, SIZE);
    std::cout << "Введите символ для удаления: ";
    std::cin >> ch;

    int j = 0; 
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ch) {
            str[j++] = str[i]; 
        }
    }
    str[j] = '\0';
    std::cout << "Результат: " << str << std::endl;
    return 0;
}