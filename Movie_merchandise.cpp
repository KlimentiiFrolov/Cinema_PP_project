// Добавить проверку входных данных.
// Добавить общее меню.
// Добавить больше товаров.
// Добавить функцию оплаты.
// Пофиксить вывод.


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
    const int CountOfProdustion = 3;
    int size_price[CountOfProdustion] = { 40,75,100 };
    string type[CountOfProdustion] = { "Маленькая","средняя","Большая" };
    system("cls");
    cout << "\n\n\n\nВыберите размер колы:" << endl;
    user_choose = menu.ChooseSize(size_price, type);
    /*cout << "1 - Маленькая - " << size_price[0] << " РУБ" << endl;
    cout << "2 - Средняя - " << size_price[1] << " РУБ" << endl;
    cout << "3 - Большая - " << size_price[2] << " РУБ" << endl;
    cout << "Ваш выбор > ";
    cin >> user_chose;*/

    cout << "Как много бутылок хотите купить?" << endl;
    do
    {
        count = get_input<int>("Ваш выбор > ");
        if (count < 1) {
            cout << "Вы не можете заказать такое количество!\n";
        }
    } while (count < 1);

    string output = to_string(count) + " x " + type[user_choose - 1] + " бутылка колы: " + to_string(count) + " x " + to_string(size_price[user_choose - 1]) + " = " + to_string(count * size_price[user_choose - 1]) + " руб\n";
    order.push_back(output);
    summa += size_price[user_choose - 1] * count;


}
void order_popcorn(int& summa, vector<string>& order) {
    int count;
    int user_choose;
    const int CountOfProdustion = 3;
    int size_price[CountOfProdustion] = { 40,75,100 };
    string type[CountOfProdustion] = { "Маленькое","Среднее","Большое" };
    system("cls");
    cout << "\n\n\n\nВыберите размер ведра попкорна:" << endl;
    user_choose = menu.ChooseSize(size_price, type);
    /*cout << "1 - Маленькая - " << size_price[0] << " РУБ" << endl;
    cout << "2 - Средняя - " << size_price[1] << " РУБ" << endl;
    cout << "3 - Большая - " << size_price[2] << " РУБ" << endl;
    cout << "Ваш выбор > ";
    cin >> user_chose;*/

    cout << "Как много попкорна хотите купить?" << endl;
    do
    {
        count = get_input<int>("Ваш выбор > ");
        if (count < 1) {
            cout << "Вы не можете заказать такое количество!\n";
        }
    } while (count < 1);

    string output = to_string(count) + " x " + type[user_choose - 1] + " ведро попкорна: " + to_string(count) + " x " + to_string(size_price[user_choose - 1]) + " = " + to_string(count * size_price[user_choose - 1]) + " руб\n";
    order.push_back(output);
    summa += size_price[user_choose - 1] * count;

}



void print_order(int summa, const vector<string>& order) {
    cout << "Ваш заказ:" << endl << endl;
    for (const auto& i : order) {
        cout << i;
    }

    cout << endl << "Всего: " << summa << " RUB" << endl;
}


void movie_merchandaise() {
    int result_sum = 0;
    vector<string> order;
    vector<string>ProductList = {"Заказать колу", "Заказать попкорн"};
    bool next;
    system("cls");
    cout << "\n\n\n\nВы бы хотели заказать напитки или закуски?" << endl;
    next = menu.YesOrNo();
    while (next == true) {
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
        }
        system("cls");
        cout << "\n\n\n\nЗаказать что-то ещё?" << endl;
        next = menu.YesOrNo();
    }

    print_order(result_sum, order);
    system("pause");
    // вызов функции оплаты
}


