#include <iostream>
#include <cctype>   // для isupper, islower
#include <cstring>  

int main() {
    setlocale(LC_ALL, "RU");
    const int SIZE = 256;
    char text[SIZE];
    int shift;

    std::cout << "Текст: ";
    std::cin.getline(text, SIZE);

    std::cout << "Сдвиг: ";
    std::cin >> shift;

    for (char* p = text; *p != '\0'; ++p) {
        if (std::isupper(static_cast<unsigned char>(*p))) {
            // Сдвиг для заглавной буквы 'A'..'Z'
            *p = ((*p - 'A' + shift) % 26 + 26) % 26 + 'A'; // добавляем +26 для отрицательных сдвигов
        }
        else if (std::islower(static_cast<unsigned char>(*p))) {
            // Сдвиг для строчной буквы 'a'..'z'
            *p = ((*p - 'a' + shift) % 26 + 26) % 26 + 'a';
        }
        // остальные символы остаются без изменений
    }

    std::cout << "Зашифрованный текст: " << text << std::endl;

    return 0;
}
