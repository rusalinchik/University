#include <iostream>

int main() {
    setlocale(LC_ALL, "RU");
    int n, m;
    std::cout << "Введите количество строк и столбов через пробел: ";
    std::cin >> n >> m;
    int matrix[100][100];
    std::cout << "Введите саму матрицу:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            std::cin >> matrix[i][j];
    }
    int rowMin[100], rowMax[100];
    int colMin[100], colMax[100];
    for (int i = 0; i < n; i++) {
        rowMin[i] = matrix[i][0];
        rowMax[i] = matrix[i][0];
        for (int j = 1; j < m; ++j) {
            if (matrix[i][j] < rowMin[i]) 
                rowMin[i] = matrix[i][j];
            if (matrix[i][j] > rowMax[i])
                rowMax[i] = matrix[i][j];
        }
    }
    for (int j = 0; j < m; ++j) {
        colMin[j] = matrix[0][j];
        colMax[j] = matrix[0][j];
        for (int i = 1; i < n; ++i) {
            if (matrix[i][j] < colMin[j]) 
                colMin[j] = matrix[i][j];
            if (matrix[i][j] > colMax[j]) 
                colMax[j] = matrix[i][j];
        }
    }
    bool found = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int val = matrix[i][j];
            if (val == rowMin[i] && val == colMax[j]) {
                std::cout << "Тип A: значение = " << val << ", строка = " << i + 1 << " столбец = " << j + 1 << "\n";
                found = true;
            }
            if (val == rowMax[i] && val == colMin[j]) {
                std::cout << "Тип B: значение = " << val << ", строка = " << i + 1 << " столбец = " << j + 1 << "\n";
                found = true;
            }
        }
    }
    if (!found)
        std::cout << "NONE\n";
    return 0;
}