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
using namespace std;


void order_cola(int& summa, vector<string>& order) {
    int count;
    int user_chose;
    int size_price[3] = { 40,75,100 };
    string type[3] = { "Small","Average","Big" };

    cout << "Select a size of cola:" << endl;
    cout << "1 - Small - " << size_price[0] << " RUB" << endl;
    cout << "2 - Average - " << size_price[1] << " RUB" << endl;
    cout << "3 - Big - " << size_price[2] << " RUB" << endl;
    cout << "Your chose >";
    cin >> user_chose;

    cout << "How many bottles of cola do you want to buy?" << endl << "Your chose >";
    cin >> count;

    string output = to_string(count) + " x " + type[user_chose - 1] + " Bottle of Cola: " + to_string(count) + " x " + to_string(size_price[user_chose - 1]) + " = " + to_string(count * size_price[user_chose - 1]) + " RUB\n";
    order.push_back(output);
    summa += size_price[user_chose - 1] * count;


}
void order_popcorn(int& summa, vector<string>& order) {
    int count;
    int user_chose;
    int size_price[3] = { 40,75,100 };
    string type[3] = { "Small","Average","Big" };

    cout << "Select a size of cola:" << endl;
    cout << "1 - Small - " << size_price[0] << " RUB" << endl;
    cout << "2 - Average - " << size_price[1] << " RUB" << endl;
    cout << "3 - Big - " << size_price[2] << " RUB" << endl;
    cout << "Your chose : ";

    cin >> user_chose;

    cout << "How many buckets of popcorn do you want to order?" << endl << "Your chose >";
    cin >> count;

    string output = to_string(count) + " x " + type[user_chose - 1] + " Popcorn: " + to_string(count) + " x " + to_string(size_price[user_chose - 1]) + " = " + to_string(count * size_price[user_chose - 1]) + " RUB\n";
    order.push_back(output);
    summa += size_price[user_chose - 1] * count;

}



void print_order(int summa, const vector<string>& order) {
    cout << "Your order:" << endl << endl;
    for (const auto & i : order) {
        cout << i;
    }

    cout << endl << "Total: " << summa << " RUB" << endl;
}


void movie_merchandaise() {
    int result_sum = 0;
    vector<string> order;
    char next;

    cout << "Would you like to purchase any drinks or snacks for the movie?" << endl << "Type Y - for Yes or type N - for No" << endl;
    next = get_input<char>("Your chose >");
    while (!(next == 'Y' || next == 'N')) {
        cout << "Некорректный ввод! Попробуйте ещё раз!" << endl;
        next = get_input<char>("Your chose >");
    }
    while (next == 'Y') {
        int user_chose;
        cout << "Select a product:\n1 - Order Cola\n2 - Order Popcorn" << endl << "Your chose >";
        cin >> user_chose;
        switch (user_chose) {
        case 1:
            order_cola(result_sum, order);
            break;
        case 2:
            order_popcorn(result_sum, order);
            break;
        }
        cout << "Continue ordering?" << endl << "Type Y - for Yes or type N - for No" << endl << "Your chose >";
        next = get_input<char>("Your chose >");
        while (!(next == 'Y' || next == 'N')) {
            cout << "Некорректный ввод! Попробуйте ещё раз!" << endl;
            next = get_input<char>("Your chose >");
        }
    }

    print_order(result_sum, order);
    // вызов функции оплаты
}


