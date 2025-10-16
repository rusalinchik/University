#include <iostream>

int main() {
    std::setlocale(LC_ALL, "RU");

    int n;
    std::cout << "Введите размер квадратной матрицы: ";
    std::cin >> n;

    int matrix[50][50];
    std::cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> matrix[i][j];
    int sumDiag1 = 0; 
    int sumDiag2 = 0; 
    for (int i = 0; i < n; i++) {
        sumDiag1 += matrix[i][i];
        sumDiag2 += matrix[i][n - 1 - i];
    }
    if (sumDiag1 != sumDiag2) {
        std::cout << "NO" << std::endl;
        return 0;
    }
    int magicSum = sumDiag1;
    for (int i = 0; i < n; i++) {
        int rowsum = 0;
        for (int j = 0; j < n; j++)
            rowsum += matrix[i][j];
        if (rowsum != magicSum) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    for (int j = 0; j < n; j++) {
        int colsum = 0;
        for (int i = 0; i < n; i++)
            colsum += matrix[i][j];
        if (colsum != magicSum) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    std::cout << "YES" << std::endl;
    std::cout << "Общая сумма равна = " << magicSum << std::endl;

    return 0;
}