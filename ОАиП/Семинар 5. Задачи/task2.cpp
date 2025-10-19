#include<iostream>
#include<vector>
#include<algorithm>

int main() {
    setlocale(LC_ALL, "RU");
    std::vector<int> v(10);
    for (int i = 0; i < 10; i++) { v[i] = i + 1; }

    std::for_each(v.begin(), v.end(), [](int x) { std::cout  << x * 2 << " "; });
    return 0;
}