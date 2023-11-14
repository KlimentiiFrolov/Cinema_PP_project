#include <iostream>
#include <vector>
#include <string>
#include "includes.h"
#include "validInput.h"
#include "menu.h"
using namespace std;
Menu menu;
// order_cola ��������� ������������ �������� ����, ������ ������ � ����������.
// ������� �������� ���������� summa, ����� �������� ����� ��������� ������, � ��������� �������� � ������ � ������ order.
void order_cola(int& summa, vector<string>& order) {
    // ��� �������������� ���������� count � user_choose ��� �������� ���������� � ���������� ������������� ������� ��������������.
    int count;
    int user_choose;
    // CountOfProduction ������������ ����� ���������� ��������� �������� ����.
    const int CountOfProduction = 3;
    // ������ size_price ������ ����, ��������������� ������� �������.
    int size_price[CountOfProduction] = { 40, 75, 100 };
    // ������ type ������ ��������� ������������� ������� ������� ����.
    string type[CountOfProduction] = { "���������", "�������", "�������" };
    // ����� ��������� � ������� system("cls"), � ������������ ������������ ������� ������ ���� � ������� ������� ChooseSize.
    system("cls");
    cout << "\n\n\n\n�������� ������ ����:" << endl;
    user_choose = menu.ChooseSize(size_price, type);
    // ����� ������������ ����� ���������� ������ ���������� �������, ������� �� ����� ������.
    cout << "��� ����� ������� ������ ������?" << endl;
    // ������� ��������� ������� ����������, ����� ���������, ��� ��� ����� ��� ������� 1.
    do
    {
        count = get_input<int>("��� ����� >");
        if (count < 1) {
            cout << "�� �� ������ �������� ����� ����������!\n";
        }
    } while (count < 1);
    // ������ ������ ������������� � ����������� � ������ `output`.
    string output = to_string(count) + " x " + type[user_choose - 1] + " ������� ����: " + to_string(count) + \
        " x " + to_string(size_price[user_choose - 1]) + " = " + \
        to_string(count * size_price[user_choose - 1]) + " ������\n";
    // ��� ������ ������ ���������� � ������ order, � summa ����� ��������� ����������� � ����������� �� ���������� ������� � ����������.
    order.push_back(output);
    summa += size_price[user_choose - 1] * count;


}
// order_popcorn ��������� ������������ �������� �������, ������ ������ � ����������.
// ������� �������� ���������� `summa`, ����� �������� ����� ��������� ������, � ��������� �������� � ������ � ������ `order`.
void order_popcorn(int& summa, vector<string>& order) {
    // ��� �������������� ���������� `count` � `user_choose` ��� �������� ���������� � ���������� ������������� ������� ��������������.
    int count;
    int user_choose;
    // CountOfProduction ������������ ����� ���������� ��������� �������� ��������.
    const int CountOfProduction = 3;
    // ������ size_price ������ ����, ��������������� ������� �������.
    int size_price[CountOfProduction] = { 40, 75, 100 };
    // ������ type ������ ��������� ������������� ������� ������� ��������.
    string type[CountOfProduction] = { "���������", "�������", "�������" };
    // ����� ��������� � ������� system("cls"), � ������������ ������������ ������� ������ �������� � ������� ������� ChooseSize.
    system("cls");
    cout << "\n\n\n\n�������� ������ ����� ��������:" << endl;
    user_choose = menu.ChooseSize(size_price, type);
    // ����� ������������ ����� ���������� ������ ���������� ��������, ������� �� ����� ������.
    cout << "��� ����� �������� ������ ������?" << endl;
    // ������� ��������� ������� ����������, ����� ���������, ��� ��� ����� ��� ������� 1.
    do {
        count = get_input<int>("��� ����� >");
        if (count < 1) {
            cout << "�� �� ������ �������� ����� ����������!\n";
        }
    } while (count < 1);
    // ������ ������ ������������� � ����������� � ������ output.
    string output = to_string(count) + " x " + type[user_choose - 1] + " ����� ��������: " + \
        to_string(count) + " x " + to_string(size_price[user_choose - 1]) + " = " + \
        to_string(count * size_price[user_choose - 1]) + " ������\n";
    // ��� ������ ������ ���������� � ������ order, � summa ����� ��������� ����������� � ����������� �� ���������� ������� � ����������.
    order.push_back(output);
    summa += size_price[user_choose - 1] * count;

}
// order_chips ��������� ������������ ���������� �����, ������� ����, ������ � ����������.
// ������� �������� ���������� summa, ����� �������� ����� ��������� ������, � ��������� �������� � ������ � ������ order.
void order_chips(int& summa, vector<string>& order) {
    // ��� �������������� ���������� count, type_chips � user_size ��� �������� ����������, ���������� �������� � ������� ��������������.
    int count;
    int type_chips = 0, user_size;
    // CountOfProduction ������������ ����� ���������� ��������� �������� ������.
    const int CountOfProduction = 3;
    // ������ size_price ������ ����, ��������������� ������� ������� ������.
    int size_price[CountOfProduction] = { 49, 89, 129 };
    // ������ type ������ ��������� ������������� ������� ������� ������.
    string type[CountOfProduction] = { "���������","�������","�������" };
    // ������ type_product ������ ��������� ������������� ��������� �������������� ������.
    vector<string> type_product = { "���", "������� � ������", "����", "���" };
    // ����� ��������� � ������� system("cls"), � ������������ ������������ ������� ��� ���� � ������� ������� ChooseProduct.
    system("cls");
    // ����� ������ �������� ������������ ����� ���������� ������� ���� ������ � ������� ChooseProduct, ������ ������ � ������� ������� ChooseSize � �� ����������.
    cout << "\n\n\n\n�������� ���� ������:" << endl;
    type_chips = menu.ChooseProduct(type_product);
    system("cls");
    cout << "\n\n\n\n������:" << endl;
    user_size = menu.ChooseSize(size_price, type);
    cout << "��� ����� ������ ������ ������?" << endl;
    // ������� ��������� ������� ����������, ����� ���������, ��� ��� ����� ��� ������� 1.
    do {
        count = get_input<int>("��� ����� >");
        if (count < 1) {
            cout << "�� �� ������ �������� ����� ����������!\n";
        }
    } while (count < 1);
    // ������ ������ ������������� � ����������� � ������ output.
    string output = to_string(count) + " x " + type_product[type_chips - 1] + " " + type[user_size - 1] + \
        " �����: " + to_string(count) + " x " + to_string(size_price[user_size - 1]) + " = " + \
        to_string(count * size_price[user_size - 1]) + " ������\n";
    // ��� ������ ������ ���������� � ������ order, � summa ����� ��������� ����������� �� ������ ���������� ��������, ������� � ����������.
    order.push_back(output);
    summa += size_price[user_size - 1] * count;

}
// print_order �������� ��������� ���������� � ������ ������������ � ����� ���������.
// ������� ��������� ����� ����� summa, �������������� ����� ���������, � ���������� ������ �� ������ ����� order, ���������� �������� � ������.
void print_order(int summa, const vector<string>& order) {
    // ������ ��� ���������� � ������, �����������, �� �������� �� ������ ������ ������.
    // ���� ����� �� ����, ������� �������� ��������� ������:�, �� ������� ������� �������� � ������ ������ � ������.
    if (!order.empty()) {
        cout << "�����:" << endl << endl;
        // ���� ���������� ������ ������� ������� order, ��������� ���� for �� ������ ���������.
        for (const auto& i : order) {
            cout << i;
        }
    }
    // ����� ������ ������� ������ ������� �������� ����� ���������, �������� "�����: " � ����� ��������� � ������.
    cout << endl << "�����: " << summa << " ������" << endl;
}

// movie_merchandaise ������������ ����� ������� �� �������, ����� ��� ������� � �������
bool movie_merchandaise() {
    // ��� �������������� ���������� result_sum ��� �������� ����� ���������, order ��� �������� ������� ������ � ProductList ��� �������� ��������� ���������.
    int result_sum = 0;
    vector<string> order;
    vector<string>ProductList = { "�������� ����", "�������� �������", "�����" };
    system("cls");
    // ������������ ������������ �������, ����� �� �� �������� ������� ��� �������, ��������� ����� YesOrNo.
    cout << "\n\n\n\n�� �� ������ �������� ������� ��� �������?" << endl;
    bool next = menu.YesOrNo();
    if (!next) {
        return false;
    }
    // ������� ������ � ���� while, �������� ������������ ���������� ������ �����, ���� �� �� ����� ����� �� ������.
    while (next) {
        int user_chose;
        system("cls");
        // ������ ����� ������������ ������������ ������� ������� �� ���� � ������� ������ ChooseProduct.
        cout << "\n\n\n�������� �������:" << endl;
        user_chose = menu.ChooseProduct(ProductList);
        // � ����������� �� ������ ������������ ���������� ��������������� ������� ������ (`order_cola`, `order_popcorn` ��� `order_chips`) ��� ��������� ����������� ��������.
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
        // ����� ������� ������ ������������ ����������, ����� �� �� �������� ���-������ ���.
        cout << "\n\n\n\n�������� ���-�� ���?" << endl;
        next = menu.YesOrNo();
    }
    // ��� ������ ������������ ��������� �����, ������� �������� print_order, ����� ���������� ������������� ������ ������ � ����� ���������.
    print_order(result_sum, order);
    system("pause");
    // ����� ������� ������
    return true;
}


