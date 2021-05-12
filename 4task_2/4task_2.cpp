#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stack>
#include <conio.h>

void readFile(std::string&);
void consoleMenu();
void writeResult(std::stack<int>&, std::stack<int>&);

int main(int argc, char* argv[])
{
    setlocale(LC_CTYPE, "Russian");
    system("CLS");
    std::cout << "Ввод из файла? (y - да, n - нет)\n";
    char answer = _getch();
    if (answer == 'y' || answer == 'Y') {
        std::string path;
        if (argc > 1) {
            path = argv[1];
        }
        else {
            std::cout << "Введите имя файла: ";
            std::cin >> path;
        }
        readFile(path);
    }
    else if(answer == 'n' || answer == 'N'){
        consoleMenu();
    }
    else {
        main(argc, argv);
    }
    return 0;
}

void consoleMenu() {
    system("CLS");
    int num_of_train_cars = 0;
    std::stack<int> first_type;
    std::stack<int> second_type;
    std::cout << "Введите количество вагонов в составе: ";
    std::cin >> num_of_train_cars;
    std::cout << "Введите типы вагонов состава с головы поезда: ";
    int type;
    for (int i = 0; i < num_of_train_cars; i++) {
        std::cin >> type;
        switch (type) {
        case 1: first_type.push(i); break;
        case 2: second_type.push(i); break;
        default: std::cout << "Существуют только два типа: 1 и 2!\n"; i--; break;
        }
    }
    writeResult(first_type, second_type);
}

void writeResult(std::stack<int>& first_type, std::stack<int>& second_type) {
    std::cout << "Состав из вагонов первого типа: ";
    if (first_type.empty()) {
        std::cout << "пуст\n";
    }
    while (!first_type.empty()) {
        std::cout << first_type.top() + 1 << ' ';
        first_type.pop();
    }
    std::cout << "\n";
    std::cout << "Состав из вагонов второго типа: ";
    if (second_type.empty()) {
        std::cout << "пуст\n";
    }
    while (!second_type.empty()) {
        std::cout << second_type.top() + 1 << ' ';
        second_type.pop();
    }
}

void readFile(std::string& path) {
    system("CLS");
    std::ifstream ifs(path, std::ios::in);
    if (!ifs.is_open()) {
        std::cout << "Файл не открывается!\n";
        return;
    }
    std::stack<int> first_type;
    std::stack<int> second_type;

    int type = 0;
    int i = 0;
    while (!ifs.eof()) {
        ifs >> type;
        if (!ifs.eof()) {
            switch (type) {
            case 1: first_type.push(i); break;
            case 2: second_type.push(i); break;
            default: std::cout << "Существуют только два типа: 1 и 2!\n"; return;
            }
        }
        i++;
    }
    ifs.close();
    writeResult(first_type, second_type);
}