#include <iostream>
#include <cstring>
#include <cctype> 

int main() {
    setlocale(LC_ALL, "RU");
    const int SIZE = 256;
    char A[SIZE], B[SIZE];

    std::cout << "Введите строку A: ";
    std::cin.getline(A, SIZE);
    std::cout << "Введите строку B: ";
    std::cin.getline(B, SIZE);
    bool allfound = true;

    for (int i = 0; B[i] != '\0'; i++) {
        bool found = false;
        char bChar = std::tolower(static_cast<unsigned char>(B[i]));

        for (int j = 0; A[j] != '\0'; j++) {
            char aChar = std::tolower(static_cast<unsigned char>(A[j]));
            if (bChar == aChar) {
                found = true;
                break;
            }
        }

        if (!found) {
            allfound = false;
            break;
        }
    }

    if (allfound)
        std::cout << "Да\n";
    else
        std::cout << "Нет\n";

    return 0;
}