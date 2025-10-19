#include <iostream>
#include <cstring>
#include <cctype> 

int main() {
    setlocale(LC_ALL, "RU");
    const int SIZE = 256;
    char str1[SIZE], str2[SIZE];

    std::cout << "Введите первую строку: ";
    std::cin.getline(str1, SIZE);
    std::cout << "Введите вторую строку: ";
    std::cin.getline(str2, SIZE);

    int len1 = std::strlen(str1);
    int len2 = std::strlen(str2);

    if (len1 != len2) {
        std::cout << "Нет" << std::endl;
        return 0;
    }

    int count[256] = { 0 }; 

    for (int i = 0; i < len1; i++) {
        unsigned char ch = std::tolower(str1[i]); 
        count[ch]++;
    }

    for (int i = 0; i < len2; i++) {
        unsigned char ch = std::tolower(str2[i]);
        count[ch]--;
    }

    bool anagram = true;
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            anagram = false;
            break;
        }
    }

    if (anagram)
        std::cout << "Да" << std::endl;
    else
        std::cout << "Нет" << std::endl;

    return 0;
}