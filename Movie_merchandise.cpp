#include <iostream>
#include <vector>
#include <string>
#include "includes.h"
#include "validInput.h"
#include "menu.h"
using namespace std;
Menu menu;
void order_cola(int& summa, vector<string>& order) {
    int count;
    int user_choose;
    const int CountOfProduction = 3;
    int size_price[CountOfProduction] = {40, 75, 100 };
    string type[CountOfProduction] = {"Маленькая", "Средняя", "Большая" };
    system("cls");
    cout << "\n\n\n\nВыберите размер колы:" << endl;
    user_choose = menu.ChooseSize(size_price, type);
    cout << "Как много бутылок хотите купить?" << endl;
    do
    {
        count = get_input<int>("Ваш выбор >");
        if (count < 1) {
            cout << "Вы не можете заказать такое количество!\n";
        }
    } while (count < 1);

    string output = to_string(count) + " x " + type[user_choose - 1] + " бутылка колы: " + to_string(count) + \
        " x " + to_string(size_price[user_choose - 1]) + " = " + \
        to_string(count * size_price[user_choose - 1]) + " рублей\n";
    order.push_back(output);
    summa += size_price[user_choose - 1] * count;


}
void order_popcorn(int& summa, vector<string>& order) {
    int count;
    int user_choose;
    const int CountOfProduction = 3;
    int size_price[CountOfProduction] = {40, 75, 100 };
    string type[CountOfProduction] = {"Маленькое", "Среднее", "Большое" };
    system("cls");
    cout << "\n\n\n\nВыберите размер ведра попкорна:" << endl;
    user_choose = menu.ChooseSize(size_price, type);
    cout << "Как много попкорна хотите купить?" << endl;
    do {
        count = get_input<int>("Ваш выбор >");
        if (count < 1) {
            cout << "Вы не можете заказать такое количество!\n";
        }
    } while (count < 1);
    string output = to_string(count) + " x " + type[user_choose - 1] + " ведро попкорна: " + \
        to_string(count) +  " x " + to_string(size_price[user_choose - 1]) + " = " + \
        to_string(count * size_price[user_choose - 1]) + " рублей\n";
    order.push_back(output);
    summa += size_price[user_choose - 1] * count;

}
void order_chips(int& summa, vector<string>& order) {
    int count;
    int type_chips = 0, user_size;
    const int CountOfProduction = 3;
    int size_price[CountOfProduction] = {49, 89, 129};
    string type[CountOfProduction] = { "Маленькая","Средняя","Большая" };
    vector<string> type_product = { "Лук", "Сметана и зелень", "Краб", "Сыр" };
    system("cls");
    cout << "\n\n\n\nВыберите вкус чипсов:" << endl;
    type_chips = menu.ChooseProduct(type_product);
    system("cls");
    cout << "\n\n\n\nРазмер:" << endl;
    user_size = menu.ChooseSize(size_price, type);
    cout << "Как много чипсов хотите купить?" << endl;
    do {
        count = get_input<int>("Ваш выбор >");
        if (count < 1) {
            cout << "Вы не можете заказать такое количество!\n";
        }
    } while (count < 1);

    string output = to_string(count) + " x " + type_product[type_chips - 1] + " " + type[user_size - 1] + \
        " чипсы: " + to_string(count) + " x " + to_string(size_price[user_size - 1]) + " = " + \
        to_string(count * size_price[user_size - 1]) + " рублей\n";
    order.push_back(output);
    summa += size_price[user_size - 1] * count;

}

void print_order(int summa, const vector<string>& order) {
    if (!order.empty()) {
        cout << "Заказ:" << endl << endl;
        for (const auto &i: order) {
            cout << i;
        }
    }
    cout << endl << "Итого: " << summa << " рублей" << endl;
}


void movie_merchandaise() {
    int result_sum = 0;
    vector<string> order;
    vector<string>ProductList = {"Заказать колу", "Заказать попкорн", "Чипсы"};
    bool next;
    system("cls");
    cout << "\n\n\n\nВы бы хотели заказать напитки или закуски?" << endl;
    next = menu.YesOrNo();
    while (next) {
        int user_chose;
        system("cls");
        cout << "\n\n\nВыберите продукт:" << endl;
        user_chose = menu.ChooseProduct(ProductList);
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
        system("cls");
        cout << "\n\n\n\nЗаказать что-то ещё?" << endl;
        next = menu.YesOrNo();
    }

    print_order(result_sum, order);
    system("pause");
    // вызов функции оплаты
}


