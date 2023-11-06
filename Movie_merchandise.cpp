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
    string type[CountOfProduction] = {"���������", "�������", "�������" };
    system("cls");
    cout << "\n\n\n\n�������� ������ ����:" << endl;
    user_choose = menu.ChooseSize(size_price, type);
    cout << "��� ����� ������� ������ ������?" << endl;
    do
    {
        count = get_input<int>("��� ����� >");
        if (count < 1) {
            cout << "�� �� ������ �������� ����� ����������!\n";
        }
    } while (count < 1);

    string output = to_string(count) + " x " + type[user_choose - 1] + " ������� ����: " + to_string(count) + \
        " x " + to_string(size_price[user_choose - 1]) + " = " + \
        to_string(count * size_price[user_choose - 1]) + " ������\n";
    order.push_back(output);
    summa += size_price[user_choose - 1] * count;


}
void order_popcorn(int& summa, vector<string>& order) {
    int count;
    int user_choose;
    const int CountOfProduction = 3;
    int size_price[CountOfProduction] = {40, 75, 100 };
    string type[CountOfProduction] = {"���������", "�������", "�������" };
    system("cls");
    cout << "\n\n\n\n�������� ������ ����� ��������:" << endl;
    user_choose = menu.ChooseSize(size_price, type);
    cout << "��� ����� �������� ������ ������?" << endl;
    do {
        count = get_input<int>("��� ����� >");
        if (count < 1) {
            cout << "�� �� ������ �������� ����� ����������!\n";
        }
    } while (count < 1);
    string output = to_string(count) + " x " + type[user_choose - 1] + " ����� ��������: " + \
        to_string(count) +  " x " + to_string(size_price[user_choose - 1]) + " = " + \
        to_string(count * size_price[user_choose - 1]) + " ������\n";
    order.push_back(output);
    summa += size_price[user_choose - 1] * count;

}
void order_chips(int& summa, vector<string>& order) {
    int count;
    int type_chips = 0, user_size;
    const int CountOfProduction = 3;
    int size_price[CountOfProduction] = {49, 89, 129};
    string type[CountOfProduction] = { "���������","�������","�������" };
    vector<string> type_product = { "���", "������� � ������", "����", "���" };
    system("cls");
    cout << "\n\n\n\n�������� ���� ������:" << endl;
    type_chips = menu.ChooseProduct(type_product);
    system("cls");
    cout << "\n\n\n\n������:" << endl;
    user_size = menu.ChooseSize(size_price, type);
    cout << "��� ����� ������ ������ ������?" << endl;
    do {
        count = get_input<int>("��� ����� >");
        if (count < 1) {
            cout << "�� �� ������ �������� ����� ����������!\n";
        }
    } while (count < 1);

    string output = to_string(count) + " x " + type_product[type_chips - 1] + " " + type[user_size - 1] + \
        " �����: " + to_string(count) + " x " + to_string(size_price[user_size - 1]) + " = " + \
        to_string(count * size_price[user_size - 1]) + " ������\n";
    order.push_back(output);
    summa += size_price[user_size - 1] * count;

}

void print_order(int summa, const vector<string>& order) {
    if (!order.empty()) {
        cout << "�����:" << endl << endl;
        for (const auto &i: order) {
            cout << i;
        }
    }
    cout << endl << "�����: " << summa << " ������" << endl;
}


void movie_merchandaise() {
    int result_sum = 0;
    vector<string> order;
    vector<string>ProductList = {"�������� ����", "�������� �������", "�����"};
    bool next;
    system("cls");
    cout << "\n\n\n\n�� �� ������ �������� ������� ��� �������?" << endl;
    next = menu.YesOrNo();
    while (next) {
        int user_chose;
        system("cls");
        cout << "\n\n\n�������� �������:" << endl;
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
        cout << "\n\n\n\n�������� ���-�� ���?" << endl;
        next = menu.YesOrNo();
    }

    print_order(result_sum, order);
    system("pause");
    // ����� ������� ������
}


