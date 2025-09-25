#include <iostream>
using namespace std;

int main() {
    setlocale (LC_ALL, "RU");
    int age;
    cout << "Введите возраст : ";
    cin >> age;
    if (age <0)
        cout << "Возраст не может быть отрицательным";
    else if (age < 18)
        cout << "Возраст меньше 18 лет";
    else if (age <= 60)
        cout << "Возраст не привосходит 60 лет";
    else
       cout << "Возраст больше 60 лет";
    return 0;
}
