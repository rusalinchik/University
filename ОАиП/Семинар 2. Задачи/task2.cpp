#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    double lenght, width;
    cout << "Введите длину прямоугольника: ";
    cin >> lenght;
    cout << "Введите ширину прямоугольника: ";
    cin >> width;
    cout << "Площадь прямоугольника =  " << width*lenght<<endl;
    return 0;
}

