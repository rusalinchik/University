#include <iostream>
using namespace std;

int main() {
    int n;
    unsigned long long factorial = 1; // Используем unsigned long long для больших чисел
    
    cout << "Введите количество автомобилей для расчета производительности: ";
    cin >> n;
    
    // Проверка на корректность ввода
    if (n < 0) {
        cout << "Ошибка: количество автомобилей не может быть отрицательным!" << endl;
        return 1;
    }
    
    if (n > 20) {
        cout << "Внимание: для чисел больше 20 результат может выходить за пределы типа данных!" << endl;
        cout << "Продолжить расчет? (y/n): ";
        char choice;
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            return 0;
        }
    }
    
    int i = 1;
    cout << "\nРасчет производительности..." << endl;
    cout << "n! = ";
    
    // Вычисление факториала с помощью цикла while
    while (i <= n) {
        factorial *= i;
        
        // Вывод промежуточных результатов
        if (i == n) {
            cout << i;
        } else {
            cout << i << " × ";
        }
        
        i++;
    }
    
    cout << " = " << factorial << endl;
    cout << "\nРезультат: " << n << "! = " << factorial << endl;
    
    // Дополнительная информация о производительности
    cout << "\nАнализ производительности:" << endl;
    cout << "Количество автомобилей: " << n << endl;
    cout << "Общая производительность: " << factorial << " условных единиц" << endl;
    
    if (n > 1) {
        double growth = static_cast<double>(factorial) / (n * (n-1));
        cout << "Коэффициент роста производительности: " << growth << endl;
    }
    
    return 0;
}