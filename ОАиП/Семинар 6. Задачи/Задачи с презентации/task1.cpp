#include <iostream>
#include <cstring>

int main() {
    setlocale(LC_ALL, "RU");
    const int SIZE = 256;
    char str[SIZE];

    std::cout << "Введите строку: ";
    std::cin.getline(str, SIZE);

    int len = std::strlen(str);
    int maxlen = 0; 
    int maxbig = 0;    

    int i = 0;
    while (i < len) {
        while (i < len && str[i] == ' ') i++;
        int start = i; 
        while (i < len && str[i] != ' ') i++;

        int wordLen = i - start;
        if (wordLen > maxlen) {
            maxlen = wordLen;
            maxbig = start;
        }
    }

    if (maxlen > 0) {
        std::cout << "Самое длинное слово: ";
        for (int j = 0; j < maxlen; j++) {
            std::cout << str[maxbig + j];
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Слова не найдены." << std::endl;
    }

    return 0;
}