#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

int main() {
    setlocale(LC_ALL, "RU");
    const int SIZE = 256;
    char str[SIZE], target[SIZE], replacement[SIZE], result[SIZE * 2]; 
    result[0] = '\0'; 

    std::cout << "Введите строку: ";
    std::cin.getline(str, SIZE);
    std::cout << "Введите подстроку для замены: ";
    std::cin.getline(target, SIZE);
    std::cout << "Введите строку-замену: ";
    std::cin.getline(replacement, SIZE);

    int lenstr = std::strlen(str);
    int lentarget = std::strlen(target);

    int i = 0;
    while (i < lenstr) {
        if (std::strncmp(&str[i], target, lentarget) == 0) {
            std::strcat(result, replacement); 
            i += lentarget;        
        }
        else {
            char temp[2] = { str[i], '\0' }; 
            std::strcat(result, temp);
            i++;
        }
    }
    std::cout << "Результат: " << result << std::endl;
    return 0;
}