#define _CRT_SECURE_NO_WARNINGS
#include <typeinfo>
#include <iostream>
#include <conio.h>
#include "id_string.h"
#include "decimal_string.h"
void init(string**&, int&);
void test(string**&, const int&);

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
        default: return 0;
        }
    }

    delete[] arr;
    return 0;
}
void init(string** &arr, int& arr_size) {
    int num = 0;
    while (num != 3) {
        //std::cin.clear();
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
            return;
        }
        
    }
}

void test(string** &arr, const int &arr_size) {
    int num = 0;
    while (num != 3) {
        system("CLS");
        std::cout << "Тестирование: \n";

        std::cout << "1. Строка\n";
        std::cout << "2. Строка-идентификатор\n";
        std::cout << "3. Десятичная строка\n";

        std::cout << "4. Выход\n";

        std::cin >> num;

        switch (num) {
        case 1: init(arr, arr_size); break;
        case 2: test(arr, arr_size); break;
        default: return;
        }
    }
    _getch();
}