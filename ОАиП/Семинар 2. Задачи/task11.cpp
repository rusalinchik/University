#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Код | Символ" << endl;
    for (int i = 32; i <= 126; i++) {
        cout << i << '\t' << (char)i << endl;
    }
    return 0;
}

