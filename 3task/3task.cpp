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

template<typename T>
void testVectorQueue() {
    VectorQueue<T> queue;
    int num = -1;
    while (num != 0) {
        system("CLS");
        std::cout << "Тестирование векторной очереди типа " << typeid(T).name() << "\n";
        std::cout << "1. Добавление элемента\n";
        std::cout << "2. Удаление и вывод элемента\n";
        std::cout << "3. Проверка на пустоту\n";
        std::cout << "4. Удаление и вывод всех элементов очереди\n";
        std::cout << "0. Выход\n";
        std::cin >> num;
        switch (num) {
        case 1: T temp; std::cout << "Введите элемент: "; std::cin >> temp; queue.push(temp); break;
        case 2: std::cout << "Удаленный элемент: " << queue.pop(); std::cout << "\n"; break;
        case 3: std::cout << (queue.isEmpty() ? "Очередь пуста" : "Очередь не пуста"); std::cout << "\n"; break;
        case 4: while (!queue.isEmpty()) { std::cout << queue.pop() << ' '; std::cout << "\n"; } break;
        default: break;
        }
        system("pause");
    }
}

template<typename T>
void testArray() {
    system("CLS");
    unsigned int size;
    std::cout << "Тестирование массива типа " << typeid(T).name() << "\n";
    std::cout << "Введите размер: ";
    std::cin >> size;
    T* arr = new T[size];
    std::cout << "Введите элементы: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    reverseFirstArrayHalf<T>(arr, size);

    std::cout << "Элементы после перестановки первой половины массива в обратном порядке: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << "\n";
    system("pause");
}

template <typename T>
void testListQueue() {
    ListQueue<T> queue;
    int num = -1;
    while (num != 0) {
        system("CLS");
        std::cout << "Тестирование списковой очереди типа " << typeid(T).name() << "\n";
        std::cout << "1. Добавление элемента\n";
        std::cout << "2. Удаление и вывод элемента\n";
        std::cout << "3. Проверка на пустоту\n";
        std::cout << "4. Удаление и вывод всех элементов очереди\n";
        std::cout << "0. Выход\n";
        std::cin >> num;
        switch (num) {
        case 1: T temp; std::cout << "Введите элемент: "; std::cin >> temp; queue.push(temp); break;
        case 2: std::cout << "Удаленный элемент: " << queue.pop(); std::cout << "\n"; break;
        case 3: std::cout << (queue.isEmpty() ? "Очередь пуста" : "Очередь не пуста"); std::cout << "\n"; break;
        case 4: while (!queue.isEmpty()) { std::cout << queue.pop() << ' '; std::cout << "\n"; } break;
        default: break;
        }
        system("pause");
    }
}

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
        case 1: testArray<unsigned int>(); break;
        case 2: testArray<unsigned char>(); break;
        case 3: testVectorQueue<unsigned int>(); break;
        case 4: testVectorQueue<unsigned char>(); break;
        case 5: testListQueue<unsigned int>(); break;
        case 6: testListQueue<unsigned char>(); break;
        default: break;
        }
        system("CLS");
    }
    return 0;
}