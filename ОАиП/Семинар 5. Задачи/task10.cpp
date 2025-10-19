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
            int left = start;
            int right = i - 1;
            while (left < right) {
                char temp = str[left];
                str[left] = str[right];
                str[right] = temp;
                left++;
                right--;
            }
            start = i + 1;
        }
    }

    std::cout << "Результат: " << str << std::endl;
    return 0;
}