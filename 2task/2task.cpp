#define _CRT_SECURE_NO_WARNINGS
#include <typeinfo>
#include <iostream>
#include <conio.h>

#include "id_string.h"
#include "decimal_string.h"
void init(string**&, int&);
void test(string**&, const int&);
void test_string(string*);
void test_id(id_string*, const char*);
void test_decimal(decimal_string*, const char*);

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int num = 0;
    string** arr = nullptr;
    int arr_size = 0;

    while (num != 3) {
        system("CLS");
        std::cout << "1. Инициализация элементов массива\n";
        std::cout << "2. Тестирование элементов массива\n";
        std::cout << "3. Выход\n";

        std::cin >> num;

        switch (num) {
        case 1: init(arr, arr_size); break;
        case 2: test(arr, arr_size); break;
        default: break;
        }
    }

    delete[] arr;
    return 0;
}
void init(string** &arr, int& arr_size) {
    int num = 0;
    while (num != 3) {
        system("CLS");
        std::cout << "1. Число элементов\n";
        std::cout << "2. Ввод элементов\n";
        std::cout << "3. Выход\n";

        std::cin >> num;
        switch(num) {
        case 1 :
            if (arr != nullptr) {
                break;
            }
            std::cout << "Введите количество элементов массива ";
            std::cin >> arr_size;
            arr = new string*[arr_size];
            break;
        case 2 : 
            int type;
            for (int i = 0; i < arr_size; i++) {
                std::cout << "Введите тип строки\n";
                std::cout << "1. string\n";
                std::cout << "2. id_string\n";
                std::cout << "3. decimal_string\n";
                std::cin >> type;
                std::cout << "Введите значение\n";

                switch (type) {
                case 1: arr[i] = new string(); break;
                case 2: arr[i] = new id_string(); break;
                case 3: arr[i] = new decimal_string(); break;
                default: arr[i] = new string(); break;
                }
                std::cin >> *arr[i];
                std::cout << "------------\n";
            }
            break;
        default :
            break;
        }
        
    }
}

void test(string** &arr, const int &arr_size) {
    int num = -1;
    int el = -1;
    char* example_dec = new char[100];
    char* example_id = new char[100];
    while (num != 4) {
        if (el < arr_size && el >= 0) {
            if (dynamic_cast<decimal_string*>(arr[el]) != nullptr) {
                test_decimal(dynamic_cast<decimal_string*>(arr[el]), example_dec);
            }
            else if (dynamic_cast<id_string*>(arr[el]) != nullptr) {
                test_id(dynamic_cast<id_string*>(arr[el]), example_id);
            }
            else {
                test_string(arr[el]);
            }
            el = -1;
        }
        system("CLS");
        std::cout << "Тестирование: \n";

        std::cout << "1. Введите номер элемента из массива\n";
        std::cout << "2. Введите целочисленную строку-операнд для тестирования decimal_string\n";
        std::cout << "3. Введите любую строку-операнд для тестирования id_string\n";

        std::cout << "4. Выход\n";

        std::cin >> num;

        switch (num) {
        case 1: std::cin >> el; break;
        case 2: std::cin >> example_dec; break;
        case 3: std::cin >> example_id; break;
        case 4: break;
        default: break;
        }
    }
    delete[] example_dec;
    delete[] example_id;
    _getch();
}

void test_string(string* str) {
    std::cout << "Элемент типа string\n";
    std::cout << "Строка: " << *str << "\n";
    std::cout << "Длина строки: " << str->get_length() << "\n";
    _getch();
}

void test_decimal(decimal_string* str, const char* example) {
    std::cout << "Элемент типа decimal_string\n";
    std::cout << "Строка: " << *str << "\n";
    std::cout << "Длина строки: " << str->get_length() << "\n";
    std::cout << "Знак числа: " << (str->get_sign() ? "+" : "-") << "\n";
    decimal_string x = *str + example;
    std::cout << "Операция сложения: " << x << "\n";
    _getch();
}

void test_id(id_string* str, const char* example) {
    std::cout << "Элемент типа id_string\n";
    std::cout << "Строка: " << *str << "\n";
    std::cout << "Длина строки: " << str->get_length() << "\n";
    id_string x = *str + example;
    std::cout << "Операция сложения: " << x << "\n";
    str->to_upper_case();
    std::cout << "Строка после перевода в верхний регистр: " << *str << "\n";
    _getch();
}