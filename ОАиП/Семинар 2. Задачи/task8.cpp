#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "RU");
    char s;
    int count=0;
    cout << "Введите строку на латинице: ";
    while (cin.get(s) && s != '\n') {
        s = tolower(s);
        if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
            count++;
    }
    cout << "Количество гласных букв: " << count << endl;
    return 0;
}

