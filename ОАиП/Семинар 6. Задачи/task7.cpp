#include <iostream>
#include <cctype>
#include <cstring>

int main() {
    setlocale(LC_ALL, "RU");
    const int SIZE = 256;
    char str[SIZE];

    std::cout << "Введите строку: ";
    std::cin.getline(str, SIZE);

    for (char* p = str; *p != '\0'; ) {
        char current = *p;   // текущий символ
        int count = 0;

        // Считаем количество повторов подряд
        char* q = p;
        while (*q == current) {
            ++count;
            ++q;
        }

        // Выводим символ и количество повторов
        std::cout << current << count;

        // Переходим к следующей новой букве
        p = q;
    }

    std::cout << std::endl;

    return 0;
}