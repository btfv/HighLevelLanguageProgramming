#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <list>
#include <chrono>
#include <string>
#include <fstream>
#include <iterator>
#include <stdio.h>

struct PassportData {
    unsigned int series;
    unsigned int number;
};
struct DepositData {
    unsigned int depositNumber;
    PassportData passportData;
    int category;
    /*
    * 1 - срочный
    * 2 - несрочный
    * 3 - третий
    */
    int currentValue;
    std::time_t lastOperationDate;
};

bool readFromBinFile(std::list<DepositData>*, std::string&);
void writeToBinFile(std::list<DepositData>*, std::string&);
void mainMenu(std::list<DepositData>*);
void addDepositMenu(std::list<DepositData>*);
bool addDepositAction(std::list<DepositData>*, DepositData&);
void removeDepositMenu(std::list<DepositData>*);
bool removeDepositAction(std::list<DepositData>*, unsigned int);
void showAllDepositsMenu(std::list<DepositData>*);
void createBinaryFile(std::string&);
bool changeDepositAction(std::list<DepositData>*, unsigned int, int);
void addRandomDeposit(std::list<DepositData>*);
void changeDepositMenu(std::list<DepositData>*);
void biggestDepositMenu(std::list<DepositData>*);

std::string getStringCategory(int cat);
int main(int argc, char* argv[])
{
    setlocale(LC_CTYPE, "Russian");
    std::srand(std::time(nullptr));

    std::string path;
    if (argc > 1) {
        path = argv[1];
    }
    else {
        std::cout << "Введите имя файла: ";
        std::cin >> path;
    }
    std::list<DepositData> depositList;
    if (!readFromBinFile(&depositList, path)) {
        createBinaryFile(path);
    };
    
    mainMenu(&depositList);

    writeToBinFile(&depositList, path);
    return 0;
}

bool readFromBinFile(std::list<DepositData>* list, std::string& path) {
    std::ifstream ifs(path, std::ios::binary);
    if (!ifs.is_open()) {
        return false;
    }
    while (!ifs.eof()) {
        DepositData data;
        ifs.read(reinterpret_cast<char*>(&data), sizeof(data));
        if (!ifs.eof())
            list->push_back(data);
    }
    ifs.close();
    return true;
}

void createBinaryFile(std::string& path) {
    std::ofstream ofs(path, std::ios::binary);
    ofs.close();
}

void writeToBinFile(std::list<DepositData>* list, std::string& path) {
    std::ofstream ofs(path, std::ios::binary);
    if (!ofs.is_open()) {
        return;
    }
    
    std::list<DepositData>::iterator it = list->begin();

    while (it != list->end()) {
        DepositData data = *it;
        ofs.write(reinterpret_cast<char*>(&data), sizeof(data));
        it++;
    }
    ofs.close();
}

void mainMenu(std::list<DepositData>* list) {
    int num = -1;
    while (num != 0) {
        system("CLS");
        std::cout << "Главное меню\n";
        std::cout << "1. Добавление счёта\n";
        std::cout << "2. Удаление счёта\n";
        std::cout << "3. Показать все счета\n";
        std::cout << "4. Добавить счёт со случайными значениями\n";
        std::cout << "5. Изменить счёт\n";
        std::cout << "6. Самый большой срочный депозит\n";
        std::cout << "0. Выход\n";
        std::cin >> num;
        switch (num) {
        case 1: addDepositMenu(list); break;
        case 2: removeDepositMenu(list); break;
        case 3: showAllDepositsMenu(list); break;
        case 4: addRandomDeposit(list); break;
        case 5: changeDepositMenu(list); break;
        case 6: biggestDepositMenu(list); break;
        default: break;
        }
    }
}

void addDepositMenu(std::list<DepositData>* list) {
    int num = -1;

    DepositData data = { 0, {0, 0}, -1, -1, NULL };

    while (num != 0) {
        system("CLS");
        std::cout << "Добавление депозита\n";
        if (data.depositNumber == 0) {
            std::cout << "1. Введите номер (>0)\n";
        }
        else {
            std::cout << "1. Номер введен (" << data.depositNumber << ")\n";
        }
        if (data.category == -1) {
            std::cout << "2. Введите категорию (1 - срочная, 2 - несрочная, 3 - третья)\n";
        }
        else {
            std::cout << "2. Категория введена (";
            std::cout << getStringCategory(data.category);
            std::cout << ")\n";
        }
        if (data.passportData.number == 0) {
            std::cout << "3. Введите номер паспорта\n";
        }
        else {
            std::cout << "3. Номер паспорта введен (" << data.passportData.number << ")\n";
        }
        if (data.passportData.series == 0) {
            std::cout << "4. Введите серию паспорта\n";
        }
        else {
            std::cout << "4. Серия паспорта введена (" << data.passportData.series << ")\n";
        }
        if (data.currentValue == -1) {
            std::cout << "5. Введите значение депозита\n";
        }
        else {
            std::cout << "5. Значение депозита введено (" << data.currentValue << ")\n";
        }
        std::cout << "6. Добавить\n";
        std::cout << "0. Выход\n";
        std::cin >> num;
        switch (num) {
        case 1: std::cout << "Введите значение поля: "; std::cin >> data.depositNumber; break;
        case 2: std::cout << "Введите значение поля: "; std::cin >> data.category; break;
        case 3: std::cout << "Введите значение поля: "; std::cin >> data.passportData.number; break;
        case 4: std::cout << "Введите значение поля: "; std::cin >> data.passportData.series; break;
        case 5: std::cout << "Введите значение поля: "; std::cin >> data.currentValue; break;
        case 6: if(addDepositAction(list, data)) return; break;
        default: break;
        }
    }
}

bool addDepositAction(std::list<DepositData>* list, DepositData& data) {
    if (data.depositNumber == 0 || data.category == -1 || data.currentValue == -1 || data.passportData.number == 0 || data.passportData.series == 0) {
        std::cout << "Не все поля заполнены!\n";
        system("pause");
        return false;
    }
    data.lastOperationDate = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::list<DepositData>::iterator it = list->begin();
    while (it != list->end() && it->depositNumber < data.depositNumber) {
        it++;
    }
    if (it != list->end() && it->depositNumber == data.depositNumber) {
        std::cout << "Счет с таким номером уже существует!\n";
        system("pause");
        return false;
    }
    list->insert(it, data);
    std::cout << "Операция успешно выполнена!\n";
    system("pause");
    return true;
}

void removeDepositMenu(std::list<DepositData>* list) {
    int num = -1;

    unsigned int depositNumber = 0;

    while (num != 0) {
        system("CLS");
        std::cout << "Удаление счёта\n";
        if (depositNumber) {
            std::cout << "1. Номер счёта введен (" << depositNumber << ")\n";
        }
        else {
            std::cout << "1. Введите номер счёта\n";
        }
        std::cout << "2. Удалить\n";
        std::cout << "0. Выход\n";
        std::cin >> num;

        switch (num) {
        case 1: std::cin >> depositNumber; break;
        case 2: if (removeDepositAction(list, depositNumber)) return; break;
        default: break;
        }
    }
}

bool removeDepositAction(std::list<DepositData>* list, unsigned int depositNumber) {
    std::list<DepositData>::iterator it = list->begin();
    while (it != list->end() && it->depositNumber != depositNumber) {
        it++;
    }
    if (it == list->end()) {
        std::cout << "Счёт с таким номерои не найден!\n";
        system("pause");
        return false;
    }
    list->erase(it);
    std::cout << "Успешно удалено\n";
    system("pause");
    return true;
}

void showAllDepositsMenu(std::list<DepositData>* list) {
    system("CLS");
    std::cout << "Список счетов\n";
        
    std::list<DepositData>::iterator it = list->begin();
    if (it == list->end()) {
        std::cout << "Список пуст!\n";
        system("pause");
        return;
    }
    printf("| N счёта |Количество денег|Серия паспорта|Номер паспорта|Категория вклада|Дата последнего обновления|\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    while (it != list->end()) {
        printf("|%8d|%17d|%14d|%14d|%16s|%12s", it->depositNumber, it->currentValue, it->passportData.series, it->passportData.number, getStringCategory(it->category).c_str(), ctime(&(it->lastOperationDate)));
        printf("------------------------------------------------------------------------------------------------------\n");
        it++;
    }
    system("pause");
}
std::string getStringCategory(int cat) {
    switch (cat) {
    case 1: return std::string("Срочный");
    case 2: return std::string("Несрочный");
    case 3: return std::string("Третий");
    default: return std::string("");
    }
}

void changeDepositMenu(std::list<DepositData>* list) {
    int num = -1;
    unsigned int depositNumber = 0;
    int money = 0;

    while (num != 0) {
        system("CLS");
        std::cout << "Изменение количества денег на счету счёта\n";
        if (depositNumber) {
            std::cout << "1. Номер счёта введен (" << depositNumber << ")\n";
        }
        else {
            std::cout << "1. Введите номер счёта\n";
        }
        if (money) {
            std::cout << "2. Значение изменения денег введено (" << money << ")\n";
        }
        else {
            std::cout << "2. Введите как изменить значение денег\n";
        }
        std::cout << "3. Изменить\n";
        std::cout << "0. Выход\n";
        std::cin >> num;

        switch (num) {
        case 1: std::cin >> depositNumber; break;
        case 2: std::cin >> money; break;
        case 3: if (changeDepositAction(list, depositNumber, money)) return; break;
        default: break;
        }
    }
}

bool changeDepositAction(std::list<DepositData>* list, unsigned int depositNumber, int money) {
    std::list<DepositData>::iterator it = list->begin();
    while (it != list->end() && it->depositNumber != depositNumber) {
        it++;
    }
    if (it == list->end()) {
        std::cout << "Счёт с таким номером не найден!\n";
        system("pause");
        return false;
    }
    it->currentValue += money;
    std::cout << "Успешно изменено\n";
    system("pause");
    return true;
}

void addRandomDeposit(std::list<DepositData>* list) {
    DepositData data = { std::rand() % 100, {std::rand() % 10000, std::rand() % 1000000}, std::rand() % 3 + 1, std::rand() % 10000000, NULL };
    if(!addDepositAction(list, data)) addRandomDeposit(list);
}

void biggestDepositMenu(std::list<DepositData>* list) {
    system("CLS");
    std::cout << "Самый крупный срочный счёт\n";

    std::list<DepositData>::iterator maxIt = list->end();
    std::list<DepositData>::iterator it = list->begin();
    if (it == list->end()) {
        std::cout << "Список пуст!\n";
        system("pause");
        return;
    }
    while (it != list->end()) {
        if (it->category == 1 && (maxIt == list->end() || maxIt->currentValue <= it->currentValue)) {
            maxIt = it;
        }
        it++;
    }
    if (maxIt == list->end()) {
        std::cout << "Срочных счетов нет\n";
    }
    else {
        printf("| N счёта |Количество денег|Серия паспорта|Номер паспорта|Категория вклада|Дата последнего обновления|\n");
        printf("------------------------------------------------------------------------------------------------------\n");
        printf("|%8d|%17d|%14d|%14d|%16s|%12s", maxIt->depositNumber, maxIt->currentValue, maxIt->passportData.series, maxIt->passportData.number, getStringCategory(maxIt->category).c_str(), ctime(&(maxIt->lastOperationDate)));
        printf("------------------------------------------------------------------------------------------------------\n");
    }
    system("pause");
}