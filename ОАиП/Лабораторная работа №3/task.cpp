#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>

struct Order {
    static const int MAX_ORDERS = 1000; 
    char name[256];
    int quantity;
    double price;
};

void writeOutput(const char* text);
void createFile();
int  loadOrders(Order arr[]);
void saveOrders(Order arr[], int n);
void findOrder();
void sortOrders();
void appendOrder();
void filterOrders();
void menu();

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RU");
 
    std::ofstream clear("output.txt");
    clear.close();

    menu();
    return 0;
}


void writeOutput(const char* text) {
    std::ofstream fout("output.txt", std::ios::app);
    fout << text << std::endl;
    fout.close();
}

void createFile() {
    std::ofstream fout("orders.txt");
    std::ofstream out("output.txt", std::ios::app);
    out << "Создание нового файла orders.txt\n";

    while (true) {
        char name[256];
        std::cout << "Название товара (пустая строка — конец): ";
        std::cin.getline(name, 256);

        if (std::strlen(name) == 0)
            break;

        int quantity;
        double price;

        std::cout << "Количество: ";
        std::cin >> quantity;
        std::cout << "Цена: ";
        std::cin >> price;
        std::cin.ignore();

        fout << name << " " << quantity << " " << price << std::endl;

        out << "Добавлен товар: " << name << " "
            << quantity << " " << price << std::endl;
    }

    fout.close();
    out.close();
}

int loadOrders(Order arr[]) {
    std::ifstream fin("orders.txt");
    if (!fin) return 0;

    int n = 0;
    while (fin >> arr[n].name >> arr[n].quantity >> arr[n].price && n < Order::MAX_ORDERS)
        n++;

    fin.close();
    return n;
}

void saveOrders(Order arr[], int n) {
    std::ofstream fout("orders.txt");
    for (int i = 0; i < n; i++)
        fout << arr[i].name << " " << arr[i].quantity << " " << arr[i].price << std::endl;
    fout.close();
}

void findOrder() { //поиск товара по названию
    char key[256];
    std::cout << "Введите название товара: ";
    std::cin.getline(key, 256);

    std::ifstream fin("orders.txt");
    std::ofstream out("output.txt", std::ios::app);
    out << "Поиск товара: " << key << std::endl;

    bool found = false;
    char name[256];
    int q;
    double p;

    while (fin >> name >> q >> p) {
        if (std::strcmp(name, key) == 0) {
            std::cout << "Найдено: " << name << " " << q << " " << p << std::endl;
            out << "Найдено: " << name << " " << q << " " << p << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "Товар не найден.\n";
        out << "Товар не найден.\n";
    }

    fin.close();
    out.close();
}

void sortOrders() { //сортирует товары
    Order arr[Order::MAX_ORDERS];
    int n = loadOrders(arr);

    std::cout << "1 — по названию\n2 — по количеству\n3 — по цене\nВыберите: ";
    int mode;
    std::cin >> mode;
    std::cin.ignore();

    std::ofstream out("output.txt", std::ios::app);
    out << "Сортировка, критерий: " << mode << std::endl;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            bool swapNeeded = false;

            if (mode == 1 && std::strcmp(arr[i].name, arr[j].name) > 0)
                swapNeeded = true;

            if (mode == 2 && arr[i].quantity > arr[j].quantity)
                swapNeeded = true;

            if (mode == 3 && arr[i].price > arr[j].price)
                swapNeeded = true;

            if (swapNeeded) {
                Order tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    saveOrders(arr, n);

    out << "Сортировка завершена.\n";
    out.close();

    std::cout << "Товары отсортированы.\n";
}

void appendOrder() {//добавляет товар в конец файла
    std::ofstream fout("orders.txt", std::ios::app);
    std::ofstream out("output.txt", std::ios::app);

    char name[256];
    std::cout << "Название товара: ";
    std::cin.getline(name, 256);

        int q;
    double p;
    std::cout << "Количество: ";
    std::cin >> q;
    std::cout << "Цена: ";
    std::cin >> p;
    std::cin.ignore();

    fout << name << " " << q << " " << p << std::endl;
    fout.close();

    out << "Добавлен товар: " << name << " " << q << " " << p << std::endl;
    out.close();

    std::cout << "Товар добавлен.\n";
}

void filterOrders() { //фильтрует товары по максимальной цене
    double maxPrice;
    std::cout << "Введите максимальную цену: ";
    std::cin >> maxPrice;
    std::cin.ignore();

    std::ifstream fin("orders.txt");
    std::ofstream out("output.txt", std::ios::app);

    out << "Фильтр: цена <= " << maxPrice << std::endl;

    char name[256];
    int q;
    double p;

    std::cout << "Подходящие товары:\n";

    while (fin >> name >> q >> p) {
        if (p <= maxPrice) {
            std::cout << name << " " << q << " " << p << std::endl;
            out << name << " " << q << " " << p << std::endl;
        }
    }

    fin.close();
    out.close();
}

void menu() {
    while (true) {
        std::cout << "\n=== МЕНЮ ===\n";
        std::cout << "1 — Создать файл и заполнить\n";
        std::cout << "2 — Найти товар\n";
        std::cout << "3 — Сортировать товары\n";
        std::cout << "4 — Добавить товар\n";
        std::cout << "5 — Фильтр по цене\n";
        std::cout << "0 — Выход\nВыбор: ";

        int cmd;
        std::cin >> cmd;
        std::cin.ignore();

        switch (cmd) {
        case 1: createFile(); break;
        case 2: findOrder(); break;
        case 3: sortOrders(); break;
        case 4: appendOrder(); break;
        case 5: filterOrders(); break;
        case 0: return;
        default: std::cout << "Неверный пункт.\n";
        }
    }
}