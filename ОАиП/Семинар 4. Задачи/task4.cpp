#include <iostream>

int main() {
    setlocale(LC_ALL, "RU");
    int n;
    std::cout << "Введите размер квадратной матрицы: ";
    std::cin >> n;
    int matrix[100][100];
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int cur = 1;
    while (top <= bottom && left <= right) { 
        for (int j = left; j <= right; j++) // слева направо
            matrix[top][j] = cur++;
        top++;
        for (int i = top; i <= bottom; i++)   // сверху вниз
            matrix[i][right] = cur++;
        right--;
        if (top <= bottom) {         // справа налево
            for (int j = right; j >= left; j--)
                matrix[bottom][j] = cur++;
            bottom--;
        }
        if (left <= right) { // снизу вверх
            for (int i = bottom; i >= top; i--)
                matrix[i][left] = cur++;
            left++;
        }
    }
    std::cout << "Спиральная матрица:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }
    return 0;
}