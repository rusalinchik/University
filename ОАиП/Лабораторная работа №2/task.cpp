#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>


int task1(char* str);                       
int task2(char* str);                       
int task3(char* str);                       
void task4(char* str);                      
int task5(char* str);                       
void task6(const char* str, char* result); 

int main() {
    setlocale(LC_ALL, "RU");
    const int SIZE = 256;
    char input[SIZE];
    std::cout << "Введите строку из 10 слов на латинице:\n";
    std::cin.getline(input, SIZE);

    char str1[SIZE], str2[SIZE], str3[SIZE], str4[SIZE], str5[SIZE], temp[SIZE];
    std::strcpy(str1, input);
    std::strcpy(str2, input);
    std::strcpy(str3, input);
    std::strcpy(str4, input);
    std::strcpy(str5, input);
    std::strcpy(temp, input);

    std::cout << "\n1. Количество слов, оканчивающихся на 'a': " << task1(str1);
    std::cout << "\n2. Длина самого короткого слова: " << task2(str2);
    std::cout << "\n3. Количество букв 'b' во втором слове: " << task3(str3);
    task4(str4);
    std::cout << "\n4. Строка в нижнем регистре: " << str4;
    std::cout << "\n5. Количество слов, у которых первый и последний символ совпадают: " << task5(str5);

    char result[50];
    task6(input, result);
    if (result[0] != '\0') {
        std::cout << "\n6. Самая короткая общая подстрока между любыми словами (минимум 2 буквы): " << result;
    }
    else {
        std::cout << "\n6. Общих подстрок длиной ≥2 нет.";
    }

    std::cout << std::endl;
    return 0;
}

int task1(char* str) {
    int count = 0;
    char* word = std::strtok(str, " ");
    while (word != nullptr) {
        int len = std::strlen(word);
        if (len > 0) {
            char last = static_cast<char>(std::tolower(static_cast<unsigned char>(word[len - 1])));
            if (last == 'a') count++;
        }
        word = std::strtok(nullptr, " ");
    }
    return count;
}

int task2(char* str) {
    int min = INT_MAX;
    char* word = std::strtok(str, " ");
    while (word != nullptr) {
        int len = std::strlen(word);
        if (len < min) 
            min = len;
        word = std::strtok(nullptr, " ");
    }
    return min;
}

int task3(char* str) {
    int wordIndex = 0;
    char* word = std::strtok(str, " ");
    while (word != nullptr) {
        wordIndex++;
        if (wordIndex == 2) {
            int count = 0;
            for (int i = 0; word[i] != '\0'; ++i) {
                if (word[i] == 'b' || word[i] == 'B') count++;
            }
            return count;
        }
        word = std::strtok(nullptr, " ");
    }
    return 0;
}

void task4(char* str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        str[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(str[i])));
    }
}

int task5(char* str) {
    int count = 0;
    char* word = std::strtok(str, " ");
    while (word != nullptr) {
        int len = std::strlen(word);
        if (len > 0) {
            char first = static_cast<char>(std::tolower(static_cast<unsigned char>(word[0])));
            char last = static_cast<char>(std::tolower(static_cast<unsigned char>(word[len - 1])));
            if (first == last) count++;
        }
        word = std::strtok(nullptr, " ");
    }
    return count;
}

void task6(const char* str, char* result) {
    result[0] = '\0';
    int minLength = INT_MAX;

    const int MAX_WORDS = 10;
    char buffer[256];
    char* words[MAX_WORDS];
    int wordCount = 0;

    std::strcpy(buffer, str);
    char* word = std::strtok(buffer, " ");
    while (word != nullptr && wordCount < MAX_WORDS) {
        words[wordCount++] = word;
        word = std::strtok(nullptr, " ");
    }

    for (int i = 0; i < wordCount; ++i) {
        for (int j = i + 1; j < wordCount; ++j) {
            char* w1 = words[i];
            char* w2 = words[j];
            int len1 = std::strlen(w1);
            int len2 = std::strlen(w2);

            for (int start1 = 0; start1 < len1; ++start1) {
                for (int end1 = start1 + 1; end1 < len1; ++end1) { 
                    int subLen = end1 - start1 + 1;
                    if (subLen > minLength) continue;

                    for (int start2 = 0; start2 <= len2 - subLen; ++start2) {
                        bool match = true;
                        for (int k = 0; k < subLen; ++k) {
                            char c1 = static_cast<char>(std::tolower(static_cast<unsigned char>(w1[start1 + k])));
                            char c2 = static_cast<char>(std::tolower(static_cast<unsigned char>(w2[start2 + k])));
                            if (c1 != c2) {
                                match = false;
                                break;
                            }
                        }
                        if (match) {
                            if (subLen < minLength) {
                                minLength = subLen;
                                std::memcpy(result, w1 + start1, subLen);
                                result[subLen] = '\0';
                            }
                            break; 
                        }
                    }
                }
            }
        }
    }
}