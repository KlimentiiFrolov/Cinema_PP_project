// добавить функцию оплаты

#include <iostream>
#include <vector>
#include <string>
#include "includes.h"
#include "validInput.h"
#include <map>
#include <fstream>
using namespace std;

int check_input(string message, int limit) {
    int number;
    bool correct;
    do {
        cout << message;
        if (!(cin >> number) or number < 1 or number > limit or cin.get() != '\n') {
            cout << "Incorrect input, try again." << endl;
            cin.clear();
            cin.ignore(9999999999, '\n');
            correct = false;
        }
        else {
            correct = true;
        }
    } while (!correct);
    return number;
}
int check_input(string message) {
    int number;
    bool correct;
    do {
        cout << message;
        if (!(cin >> number) or number < 1 or cin.get() != '\n') {
            cout << "Incorrect input, try again." << endl;
            cin.clear();
            cin.ignore(9999999999, '\n');
            correct = false;
        }
        else {
            correct = true;
        }
    } while (!correct);
    return number;
}

void order_cola(int& summa, vector<string>& order) {
    int count;
    int user_chose;
    vector<int> size_price = { 40,75,100 };
    vector<string> type_product = { "Маленькая","Средняя","Большая" };

    cout << "Размер Колы:" << endl;
    for (int i = 0; i < type_product.size(); i++) {
        string output = to_string(i + 1) + " - " + type_product[i] + " - " + to_string(size_price[i]) + " Рублей\n";
        cout << output;
    }
    cout << type_product.size() + 1 << " - Отмена\n";
    user_chose = check_input("Выбор: ", type_product.size() + 1);
    if (user_chose == type_product.size() + 1) {
        return;
    }

    count = check_input("Количество: ");

    string output = to_string(count) + " x " + type_product[user_chose - 1] + " Кола: " + to_string(count) + " x " + to_string(size_price[user_chose - 1]) + " = " + to_string(count * size_price[user_chose - 1]) + " Рублей\n";
    order.push_back(output);
    summa += size_price[user_chose - 1] * count;


}
void order_popcorn(int& summa, vector<string>& order) {
    int count;
    int user_chose;
    vector<int> size_price = { 40,75,100 };
    vector<string> type_product = { "Маленький","Средний","Большой" };

    cout << "Размер Попкорна:" << endl;
    for (int i = 0; i < type_product.size(); i++) {
        string output = to_string(i + 1) + " - " + type_product[i] + " - " + to_string(size_price[i]) + " Рублей\n";
        cout << output;
    }

    cout << type_product.size() + 1 << " - Отмена\n";
    user_chose = check_input("Выбор: ", type_product.size() + 1);
    if (user_chose == type_product.size() + 1) {
        return;
    }
    count = check_input("Количество: ");

    string output = to_string(count) + " x " + type_product[user_chose - 1] + " Попкорн: " + to_string(count) + " x " + to_string(size_price[user_chose - 1]) + " = " + to_string(count * size_price[user_chose - 1]) + " Рублей\n";
    order.push_back(output);
    summa += size_price[user_chose - 1] * count;

}
void order_chips(int& summa, vector<string>& order) {
    int count;
    int type_chips;
    int user_size;

    cout << "Вкус чипсов:" << endl;
    vector<int> price = { 49,89,129 };
    vector<string> size = { "Маленькая","Средняя","Большая" };
    vector<string> type_product = { "Лук","Сметана и зелень","Краб","Сыр" };
    for (int i = 0; i < type_product.size(); i++) {
        string output = to_string(i + 1) + " - " + type_product[i] + "\n";
        cout << output;
    }
    cout << type_product.size() + 1 << " - Отмена\n";

    type_chips = check_input("Выбор: ", type_product.size() + 1);
    if (type_chips == type_product.size() + 1) {
        return;
    }

    cout << "Размер Чипсов:" << endl;
    for (int i = 0; i < size.size(); i++) {
        string output = to_string(i + 1) + " - " + size[i] + " - " + to_string(price[i]) + " Рублей\n";
        cout << output;
    }
    cout << size.size() + 1 << " - Отмена\n";
    user_size = check_input("Выбор: ", size.size() + 1);
    if (user_size == size.size() + 1) {
        return;
    }

    count = check_input("Количество: ");

    string output = to_string(count) + " x " + type_product[type_chips - 1] + " " + size[user_size - 1] + " Чипсы: " + to_string(count) + " x " + to_string(price[user_size - 1]) + " = " + to_string(count * price[user_size - 1]) + " Рублей\n";
    order.push_back(output);
    summa += price[user_size - 1] * count;

}

void print_order(int summa, vector<string> order) {
    if (order.size() > 0) {
        cout << "Заказ:" << endl << endl;
        for (int i = 0; i < order.size(); i++) {
            cout << order[i];
        }

        cout << endl << "Итого: " << summa << " RUB" << endl;
    }
}
void show_menu() {

    setlocale(LC_ALL, "en_US.utf8");
    ifstream inFile("menu.txt");

    char ch;

    while (inFile.get(ch)) {
        cout << ch;
    }
    setlocale(LC_ALL, "Russian");
    inFile.close();
}



void movie_merchandaise() {
    setlocale(LC_ALL, "Russian");
    int result_sum = 0;
    vector<string> order;
    char next;

    cout << "Добавить напитки или снэки к заказу?" << endl << "Нажмите Y для подтвеждения" << endl << "Выбор: ";
    cin >> next;
    show_menu();
    while (next == 'Y') {
        int user_chose;
        cout << "Выберете позицию из меню:\n1 - Кола\n2 - Попкорн\n3 - Чипсы\n4 - Отмена" << endl;
        user_chose = check_input("Выбор: ", 4);
        if (user_chose == 4) {
            break;
        }
        switch (user_chose) {
        case 1:
            order_cola(result_sum, order);
            break;
        case 2:
            order_popcorn(result_sum, order);
            break;
        case 3:
            order_chips(result_sum, order);
            break;
        }

        cout << "Добавить ещё?" << endl << "Нажмите Y для подтвеждения" << endl << "Выбор: ";
        cin >> next;
    }

    print_order(result_sum, order);
    // вызов функции оплаты
}


