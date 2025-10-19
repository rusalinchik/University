#include <iostream>
#include <cstring>

int main() {
    setlocale(LC_ALL, "RU");
    const int SIZE = 256;
    char str[SIZE];

    std::cout << "Введите строку: ";
    std::cin.getline(str, SIZE);

    int len = std::strlen(str);
    int j = 0; 

    for (int i = 0; i < len; i++) {
        if (!(str[i] >= '0' && str[i] <= '9')) { 
            str[j] = str[i];
            j++;
        }
    }

    str[j] = '\0'; 

    std::cout << "Результат: " << str << std::endl;

    return 0;
}