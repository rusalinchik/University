#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;
    int matrix[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++)   // слева направо
            std::cout << matrix[top][j] << " ";
        top++;
        for (int i = top; i <= bottom; i++)     // сверху вниз
            std::cout << matrix[i][right] << " ";
        right--;
        if (top <= bottom) { // справа налево
            for (int j = right; j >= left; j--)
                std::cout << matrix[bottom][j] << " ";
            bottom--;
        }
        if (left <= right) { // снизу вверх
            for (int i = bottom; i >= top; i--)
                std::cout << matrix[i][left] << " ";
            left++;
        }
    }

    return 0;
}