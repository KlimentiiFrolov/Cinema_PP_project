// �������� �������� ������� ������.
// �������� ����� ����.
// �������� ������ �������.
// �������� ������� ������.
// ��������� �����.


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
    string type[CountOfProdustion] = { "���������","�������","�������" };
    system("cls");
    cout << "\n\n\n\n�������� ������ ����:" << endl;
    user_choose = menu.ChooseSize(size_price, type);
    /*cout << "1 - ��������� - " << size_price[0] << " ���" << endl;
    cout << "2 - ������� - " << size_price[1] << " ���" << endl;
    cout << "3 - ������� - " << size_price[2] << " ���" << endl;
    cout << "��� ����� > ";
    cin >> user_chose;*/

    cout << "��� ����� ������� ������ ������?" << endl;
    do
    {
        count = get_input<int>("��� ����� > ");
        if (count < 1) {
            cout << "�� �� ������ �������� ����� ����������!\n";
        }
    } while (count < 1);

    string output = to_string(count) + " x " + type[user_choose - 1] + " ������� ����: " + to_string(count) + " x " + to_string(size_price[user_choose - 1]) + " = " + to_string(count * size_price[user_choose - 1]) + " ���\n";
    order.push_back(output);
    summa += size_price[user_choose - 1] * count;


}
void order_popcorn(int& summa, vector<string>& order) {
    int count;
    int user_choose;
    const int CountOfProdustion = 3;
    int size_price[CountOfProdustion] = { 40,75,100 };
    string type[CountOfProdustion] = { "���������","�������","�������" };
    system("cls");
    cout << "\n\n\n\n�������� ������ ����� ��������:" << endl;
    user_choose = menu.ChooseSize(size_price, type);
    /*cout << "1 - ��������� - " << size_price[0] << " ���" << endl;
    cout << "2 - ������� - " << size_price[1] << " ���" << endl;
    cout << "3 - ������� - " << size_price[2] << " ���" << endl;
    cout << "��� ����� > ";
    cin >> user_chose;*/

    cout << "��� ����� �������� ������ ������?" << endl;
    do
    {
        count = get_input<int>("��� ����� > ");
        if (count < 1) {
            cout << "�� �� ������ �������� ����� ����������!\n";
        }
    } while (count < 1);

    string output = to_string(count) + " x " + type[user_choose - 1] + " ����� ��������: " + to_string(count) + " x " + to_string(size_price[user_choose - 1]) + " = " + to_string(count * size_price[user_choose - 1]) + " ���\n";
    order.push_back(output);
    summa += size_price[user_choose - 1] * count;

}



void print_order(int summa, const vector<string>& order) {
    cout << "��� �����:" << endl << endl;
    for (const auto& i : order) {
        cout << i;
    }

    cout << endl << "�����: " << summa << " RUB" << endl;
}


void movie_merchandaise() {
    int result_sum = 0;
    vector<string> order;
    vector<string>ProductList = {"�������� ����", "�������� �������"};
    bool next;
    system("cls");
    cout << "\n\n\n\n�� �� ������ �������� ������� ��� �������?" << endl;
    next = menu.YesOrNo();
    while (next == true) {
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
        }
        system("cls");
        cout << "\n\n\n\n�������� ���-�� ���?" << endl;
        next = menu.YesOrNo();
    }

    print_order(result_sum, order);
    system("pause");
    // ����� ������� ������
}


