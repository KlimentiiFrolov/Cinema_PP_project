// добавить общее меню
// добавить больше товаров 
// добавить функцию оплаты 



#include<iostream>
#include<vector>
#include<string>
#include "includes.h"
#include<map>

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
    int size_price[3] = { 40,75,100 };
    string type[3] = { "Small","Average","Big" };

    cout << "Select a size of cola:" << endl;
    cout << "1 - Small - " << size_price[0] << " RUB" << endl;
    cout << "2 - Average - " << size_price[1] << " RUB" << endl;
    cout << "3 - Big - " << size_price[2] << " RUB" << endl;
    user_chose = check_input("Your chose : ", 3);

    count = check_input("Count of bottles: ");

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
    user_chose = check_input("Your chose : ", 3);

    count = check_input("Count buckets of popcorn: ");

    string output = to_string(count) + " x " + type[user_chose - 1] + " Popcorn: " + to_string(count) + " x " + to_string(size_price[user_chose - 1]) + " = " + to_string(count * size_price[user_chose - 1]) + " RUB\n";
    order.push_back(output);
    summa += size_price[user_chose - 1] * count;

}



void print_order(int summa, vector<string> order) {
    if (order.size() > 0) {
        cout << "Your order:" << endl << endl;
        for (int i = 0; i < order.size(); i++) {
            cout << order[i];
        }

        cout << endl << "Total: " << summa << " RUB" << endl;
    }
}
void show_menu() {
    map < string, vector<string>> products;



}



void movie_merchandaise() {
    int result_sum = 0;
    vector<string> order;
    char next;

    cout << "Add drinks or snacks to order?" << endl << "Type Y - for Yes" << endl << "Your chose: ";
    cin >> next;

    while (next == 'Y') {
        int user_chose;
        cout << "Select a product:\n1 - Order Cola\n2 - Order Popcorn\n3 - Cancel order" << endl;
        user_chose = check_input("Your chose : ", 3);
        if (user_chose == 3) {
            break;
        }
        switch (user_chose) {
        case 1:
            order_cola(result_sum, order);
            break;
        case 2:
            order_popcorn(result_sum, order);
            break;
        }

        cout << "Add more?" << endl << "Type Y - for Yes" << endl << "Your chose: ";
        cin >> next;
    }

    print_order(result_sum, order);
    // вызов функции оплаты
}




int main() {
    movie_merchandaise();
}