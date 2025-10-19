#include <iostream>
#include <cctype>   
#include <cstring>  

int main() {
    setlocale(LC_ALL, "RU");
    const int SIZE = 256;
    char str[SIZE];

    std::cout << "Введите строку: ";
    std::cin.getline(str, SIZE);

    int vowels = 0;
    int consonants = 0;

    for (char* p = str; *p != '\0'; ++p) {
        if (std::isalpha(static_cast<unsigned char>(*p))) { 
            char ch = std::tolower(static_cast<unsigned char>(*p));
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') 
                ++vowels;
            else 
                ++consonants;
        }
    }

    std::cout << "Гласных: " << vowels << std::endl;
    std::cout << "Согласных: " << consonants << std::endl;

    return 0;
}