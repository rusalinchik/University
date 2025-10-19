#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

int main() {
    setlocale(LC_ALL, "RU");
    const int SIZE = 256;
    char str[SIZE];
    int k;

    std::cout << "Строка: ";
    std::cin.getline(str, SIZE);
    std::cout << "k = ";
    std::cin >> k;

    int len = std::strlen(str);
    char printed[SIZE][SIZE]; 
    int count = 0;
    bool first = true;

    for (int i = 0; i <= len - k; i++) {
        bool bob = true;
        for (int j = i; j < i + k; j++) {
            for (int l = j + 1; l < i + k; l++) {
                if (str[j] == str[l]) {
                    bob = false;
                    break;
                }
            }
            if (!bob) break;        }

        if (bob) {
            bool alreadyprinted = false;
            for (int p = 0; p < count; p++) {
                if (std::strncmp(printed[p], str + i, k) == 0) {
                    alreadyprinted = true;
                    break;
                }
            }
            if (!alreadyprinted) {
                if (!first) std::cout << " ";
                for (int j = i; j < i + k; j++)
                    std::cout << str[j];
                std::strncpy(printed[count], str + i, k);
                printed[count][k] = '\0';
                count++;
                first = false;
            }
        }
    }

    std::cout << std::endl;
    return 0;
}