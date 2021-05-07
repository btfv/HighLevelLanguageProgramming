#include <iostream>
#include "ListQueue.h"
#include "VectorQueue.h"

template<typename T>
void reverseFirstArrayHalf(T* arr, const unsigned int size) {
    int l = 0;
    int r = size / 2 - 1;
    T temp;
    while (r - l > 0) {
        temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    }
}

void testUIntArray();
void testUCharArray();
void testVectorUCharQueue();
void testVectorUIntQueue();
void testListUCharQueue();
void testListUIntQueue();

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int num = -1;
    while (num != 0) {
        std::cout << "1. Тестирование функции перестановки первой половины массива типа unsigned int в обратном порядке\n";
        std::cout << "2. Тестирование функции перестановки первой половины массива типа unsigned char в обратном порядке\n";
        std::cout << "3. Тестирование шаблона класса (векторная очередь элементов типа unsigned int)\n";
        std::cout << "4. Тестирование шаблона класса (векторная очередь элементов типа unsigned char)\n";
        std::cout << "5. Тестирование шаблона класса (списковая очередь элементов типа unsigned int)\n";
        std::cout << "6. Тестирование шаблона класса (списковая очередь элементов типа unsigned char)\n";
        std::cout << "0. Выход\n";
        std::cin >> num;
        switch (num) {
        case 1: testUIntArray(); break;
        case 2: testUCharArray(); break;
        case 3: testVectorUIntQueue(); break;
        case 4: testVectorUCharQueue(); break;
        case 5: testListUIntQueue(); break;
        case 6: testListUCharQueue(); break;
        default: break;
        }
        system("CLS");
    }
    return 0;
}

void testUIntArray() {
    system("CLS");
    unsigned int size;
    std::cout << "Тестирование массива типа unsigned int\n";
    std::cout << "Введите размер: ";
    std::cin >> size;
    unsigned int* arr = new unsigned int[size];
    std::cout << "Введите элементы: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    reverseFirstArrayHalf<unsigned int>(arr, size);

    std::cout << "Элементы после перестановки первой половины массива в обратном порядке: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << "\n";
    system("pause");
}

void testUCharArray() {
    system("CLS");
    unsigned int size;
    std::cout << "Тестирование массива типа unsigned char\n";
    std::cout << "Введите размер: ";
    std::cin >> size;
    unsigned char* arr = new unsigned char[size];
    std::cout << "Введите элементы: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    reverseFirstArrayHalf<unsigned char>(arr, size);

    std::cout << "Элементы после перестановки первой половины массива в обратном порядке: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << "\n";
    system("pause");
}

void testVectorUCharQueue() {
    system("CLS");
    VectorQueue<unsigned char> queue;
    int num = -1;
    while (num != 0) {
        std::cout << "Тестирование векторной очереди типа unsigned char\n";
        std::cout << "1. Добавление элемента\n";
        std::cout << "2. Удаление и вывод элемента\n";
        std::cout << "3. Проверка на пустоту\n";
        std::cout << "4. Удаление и вывод всех элементов очереди\n";
        std::cout << "0. Выход\n";
        std::cin >> num;
        switch (num) {
        case 1: unsigned char temp; std::cout << "Введите элемент: "; std::cin >> temp; queue.push(temp); break;
        case 2: std::cout << "Удаленный элемент: " << queue.pop(); std::cout << "\n"; break;
        case 3: std::cout << (queue.isEmpty() ? "Очередь пуста" : "Очередь не пуста"); std::cout << "\n"; break;
        case 4: while (!queue.isEmpty()) { std::cout << queue.pop() << ' '; std::cout << "\n"; } break;
        default: break;
        }
        system("pause");
        system("CLS");
    }
}

void testVectorUIntQueue() {
    system("CLS");
    VectorQueue<unsigned int> queue;
    int num = -1;
    while (num != 0) {
        std::cout << "Тестирование векторной очереди типа unsigned int\n";
        std::cout << "1. Добавление элемента\n";
        std::cout << "2. Удаление и вывод элемента\n";
        std::cout << "3. Проверка на пустоту\n";
        std::cout << "4. Удаление и вывод всех элементов очереди\n";
        std::cout << "0. Выход\n";
        std::cin >> num;
        switch (num) {
        case 1: unsigned int temp; std::cout << "Введите элемент: "; std::cin >> temp; queue.push(temp); break;
        case 2: std::cout << "Удаленный элемент: " << queue.pop(); std::cout << "\n"; break;
        case 3: std::cout << (queue.isEmpty() ? "Очередь пуста" : "Очередь не пуста"); std::cout << "\n"; break;
        case 4: while (!queue.isEmpty()) { std::cout << queue.pop() << ' '; std::cout << "\n"; } break;
        default: break;
        }
        system("pause");
        system("CLS");
    }
}

void testListUCharQueue() {
    system("CLS");
    ListQueue<unsigned char> queue;
    int num = -1;
    while (num != 0) {
        std::cout << "Тестирование списковой очереди типа unsigned char\n";
        std::cout << "1. Добавление элемента\n";
        std::cout << "2. Удаление и вывод элемента\n";
        std::cout << "3. Проверка на пустоту\n";
        std::cout << "4. Удаление и вывод всех элементов очереди\n";
        std::cout << "0. Выход\n";
        std::cin >> num;
        switch (num) {
        case 1: unsigned char temp; std::cout << "Введите элемент: "; std::cin >> temp; queue.push(temp); break;
        case 2: std::cout << "Удаленный элемент: " << queue.pop(); std::cout << "\n"; break;
        case 3: std::cout << (queue.isEmpty() ? "Очередь пуста" : "Очередь не пуста"); std::cout << "\n"; break;
        case 4: while (!queue.isEmpty()) { std::cout << queue.pop() << ' '; std::cout << "\n"; } break;
        default: break;
        }
        system("pause");
        system("CLS");
    }
}

void testListUIntQueue() {
    system("CLS");
    ListQueue<unsigned int> queue;
    int num = -1;
    while (num != 0) {
        std::cout << "Тестирование списковой очереди типа unsigned int\n";
        std::cout << "1. Добавление элемента\n";
        std::cout << "2. Удаление и вывод элемента\n";
        std::cout << "3. Проверка на пустоту\n";
        std::cout << "4. Удаление и вывод всех элементов очереди\n";
        std::cout << "0. Выход\n";
        std::cin >> num;
        switch (num) {
        case 1: unsigned int temp; std::cout << "Введите элемент: "; std::cin >> temp; queue.push(temp); break;
        case 2: std::cout << "Удаленный элемент: " << queue.pop(); std::cout << "\n"; break;
        case 3: std::cout << (queue.isEmpty() ? "Очередь пуста" : "Очередь не пуста"); std::cout << "\n"; break;
        case 4: while (!queue.isEmpty()) { std::cout << queue.pop() << ' '; std::cout << "\n"; } break;
        default: break;
        }
        system("pause");
        system("CLS");
    }
}