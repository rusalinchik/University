#include <iostream>

void transposeglav(int matrix[100][100], int n);
void transposepob(int matrix[100][100], int n);
void reflectVertical(int matrix[100][100], int n);
void reflectHorizontal(int matrix[100][100], int n);
bool areEqual(int a[100][100], int b[100][100], int n);


int main() {
	setlocale(LC_ALL, "RU");
	int n;
	std::cout << "Введите размер квадратной матрицы: ";
	std::cin >> n;
	int matrix[100][100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> matrix[i][j];
		}
	}

	int matrix_glav[100][100];
	int matrix_pob[100][100];
	int matrix_vert[100][100];
	int matrix_horiz[100][100];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix_glav[i][j] = matrix[i][j];
			matrix_pob[i][j] = matrix[i][j];
			matrix_vert[i][j] = matrix[i][j];
			matrix_horiz[i][j] = matrix[i][j];
		}
	}

	transposeglav(matrix_glav, n);
	transposepob(matrix_pob, n);
	reflectVertical(matrix_vert, n);
	reflectHorizontal(matrix_horiz, n);

	std::cout << "Сравнение матриц:\n";
	if (areEqual(matrix_glav, matrix_pob, n))
		std::cout << "Главная диагональ и побочная диагональ совпадают\n";
	if (areEqual(matrix_glav, matrix_vert, n))
		std::cout << "Главная диагональ и вертикальная ось совпадают\n";
	if (areEqual(matrix_glav, matrix_horiz, n))
		std::cout << "Главная диагональ и горизонтальная ось совпадают\n";
	if (areEqual(matrix_pob, matrix_vert, n))
		std::cout << "Побочная диагональ и вертикальная ось совпадают\n";
	if (areEqual(matrix_pob, matrix_horiz, n))
		std::cout << "Побочная диагональ и горизонтальная ось совпадают\n";
	if (areEqual(matrix_vert, matrix_horiz, n))
		std::cout << "Вертикальная ось и горизонтальная ось совпадают\n";
	else
		std::cout << "Никакие матрицы не совпадают";

	return 0;
}

void transposeglav(int matrix[100][100], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			std::swap(matrix[i][j], matrix[j][i]);
		}
	}
	std::cout << "Отражение относительно главной диагонали: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void transposepob(int matrix[100][100], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			std::swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
		}
	}
	std::cout << "Отражение относительно побочной диагонали: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void reflectVertical(int matrix[100][100], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n/2; j++) {
			std::swap(matrix[i][j], matrix[i][n - 1 - j]);
		}
	}
	std::cout << "Отражение относительно вертикальной оси:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void reflectHorizontal(int matrix[100][100], int n) {
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n; j++) {
			std::swap(matrix[i][j], matrix[n - 1 - i][j]);
		}
	}
	std::cout << "Отображение матрицы по горизонтальной оси:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

bool areEqual(int a[100][100], int b[100][100], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != b[i][j])
				return false;
		}
	}
	return true;
}