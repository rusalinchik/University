#include <iostream>
#include <cstring>

int main() {
    setlocale(LC_ALL, "RU");
    const int size = 256;  

    char str1[size], str2[size];

    std::cout << "Введите первую строку: ";
    std::cin.getline(str1, size);
    std::cout << "Введите вторую строку: ";
    std::cin.getline(str2, size);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int dp[size][size] = { 0 }; 
    int maxlen = 0;
    int endIndex = 0;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxlen) {
                    maxlen = dp[i][j];
                    endIndex = i - 1;
                }
            }
            else {
                dp[i][j] = 0;
            }
        }
    }

    if (maxlen > 0) {
        std::cout << "Наибольшая общая подстрока: ";
        for (int i = endIndex - maxlen + 1; i <= endIndex; i++) {
            std::cout << str1[i];
        }
    }
    else {
        std::cout << "Общих подстрок не найдено" << std::endl;
    }

    return 0;
}