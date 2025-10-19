#include <iostream>
#include <cctype>   // для isalpha, toupper, tolower
#include <cstring>

int main() {
    setlocale(LC_ALL, "RU");
    const int SIZE = 512;
    char text[SIZE];

    std::cout << "Введите текст: ";
    std::cin.getline(text, SIZE);

    bool news = true;

    for (char* p = text; *p != '\0'; ++p) {
        if (std::isalpha(static_cast<unsigned char>(*p))) {
            if (news) {
                *p = std::toupper(static_cast<unsigned char>(*p)); 
                news = false;
            }
            else {
                *p = std::tolower(static_cast<unsigned char>(*p)); 
            }
        }
        else if (*p == '.' || * p == '!' || * p == '?') {
            news = true; 
        }
    }

    std::cout << "Исправленный текст: " << text << std::endl;

    return 0;
}