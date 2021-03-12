#include <iostream>
#include <conio.h>

#include "triangle.h"

Triangle* enterData();
void sideMenu(double&);
void angleMenu(double&);
void actionMenu(Triangle*, Triangle*);
void compare(Triangle*, Triangle*);
void menu();

int main()
{
    setlocale(LC_CTYPE, "Russian");
    menu();
    return -1;
}

void sideMenu(double& side) {
    std::cout << "Введите сторону: ";
    std::cin >> side;
    if (side <= 0) {
        sideMenu(side);
    }
}
void angleMenu(double& angle) {
    std::cout << "Введите угол в градусах: ";
    std::cin >> angle;
    if (angle <= 0 || angle > 90) {
        angleMenu(angle);
    }
}

Triangle* enterData() {
    int x = 0;
    double side = -1, left_angle = -1, right_angle = -1;

    while (x != -1) {
        switch (x) {
        case 1: sideMenu(side); break;
        case 2: angleMenu(left_angle); break;
        case 3: angleMenu(right_angle); break;
        }
        if (side != -1 && left_angle != -1 && right_angle != -1) {
            return new Triangle(side, left_angle, right_angle);
        }
        system("CLS");
        std::cout << "Введите данные и нажмите Enter:\n";
        if (side != -1) {
            std::cout << "1. Сторона: " << side << "\n";
        }
        else {
            std::cout << "1. Сторона: " << "\n";
        }
        if (left_angle != -1) {
            std::cout << "2. Первый угол: " << left_angle << "\n";
        }
        else {
            std::cout << "2. Первый угол: " << "\n";
        }
        if (right_angle != -1) {
            std::cout << "3. Второй угол: " << right_angle << "\n";
        }
        else {
            std::cout << "3. Второй угол: " << "\n";
        }
        std::cin >> x;
    }
    return enterData();
}

void menu() {
    Triangle *triangle1 = NULL, *triangle2 = NULL;
    int x = 0;
    while (x != -1) {
        switch (x)
        {
        case 1:
            triangle1 = enterData();
            break;
        case 2:
            triangle2 = enterData();
            break;
        }
        if (triangle1 != NULL && triangle2 != NULL) {
            actionMenu(triangle1, triangle2);
            return;
        }
        system("CLS");
        if (triangle1 != NULL) {
            std::cout << "Первый треугольник введен!\n";
        }
        else {
            std::cout << "Первый треугольник не введен!\n";
        }
        if (triangle2 != NULL) {
            std::cout << "Второй треугольник введен!\n";
        }
        else {
            std::cout << "Второй треугольник не введен!\n";
        }
        std::cout << "Введите номер треугольника для ввода данных (1 или 2):\n";
        std::cin >> x;
    }
}

void actionMenu(Triangle* triangle1, Triangle* triangle2) {
    int x = -1;

    while (x != 0) {
        system("CLS");
        switch (x) {
        case 1: triangle1->calculateSides(); _getch(); break;
        case 2: triangle1->calculateBisectors(); _getch(); break;
        case 3: compare(triangle1, triangle2); _getch(); break;
        }
        system("CLS");
        std::cout << "Введите данные и нажмите Enter:\n";
        std::cout << "1. Вычислить длины сторон (у первого треугольника)\n";
        std::cout << "2. Вычислить длины биссектрис (у первого треугольника)\n";
        std::cout << "3. Сравнить стороны треугольников\n";
        std::cout << "0. Выйти\n";
        std::cin >> x;
    }
    return;
}

void compare(Triangle* triangle1, Triangle* triangle2) {
    if (*triangle1 == *triangle2) {
        std::cout << "Треугольники равны!\n";
    }
    else {
        std::cout << "Треугольники не равны!\n";
    };
}