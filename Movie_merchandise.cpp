#include <iostream>
#include <vector>
#include <string>
#include "includes.h"
#include "validInput.h"
#include "menu.h"
using namespace std;
Menu menu;
// order_cola позволяет пользователю заказать колу, выбрав размер и количество.
// Функция изменяет переменную summa, чтобы обновить общую стоимость заказа, и добавляет сведения о заказе в вектор order.
void order_cola(int& summa, vector<string>& order) {
    // Она инициализирует переменные count и user_choose для хранения количества и выбранного пользователем размера соответственно.
    int count;
    int user_choose;
    // CountOfProduction представляет общее количество доступных размеров колы.
    const int CountOfProduction = 3;
    // Массив size_price хранит цены, соответствующие каждому размеру.
    int size_price[CountOfProduction] = { 40, 75, 100 };
    // Массив type хранит строковые представления каждого размера колы.
    string type[CountOfProduction] = { "Маленькая", "Средняя", "Большая" };
    // Экран очищается с помощью system("cls"), и пользователю предлагается выбрать размер колы с помощью функции ChooseSize.
    system("cls");
    cout << "\n\n\n\nВыберите размер колы:" << endl;
    user_choose = menu.ChooseSize(size_price, type);
    // Затем пользователю будет предложено ввести количество бутылок, которые он хочет купить.
    cout << "Как много бутылок хотите купить?" << endl;
    // Функция проверяет входное количество, чтобы убедиться, что оно равно как минимум 1.
    do
    {
        count = get_input<int>("Ваш выбор >");
        if (count < 1) {
            cout << "Вы не можете заказать такое количество!\n";
        }
    } while (count < 1);
    // Детали заказа форматируются и сохраняются в строке `output`.
    string output = to_string(count) + " x " + type[user_choose - 1] + " бутылка колы: " + to_string(count) + \
        " x " + to_string(size_price[user_choose - 1]) + " = " + \
        to_string(count * size_price[user_choose - 1]) + " рублей\n";
    // Эта строка заказа помещается в вектор order, и summa общей стоимости обновляется в зависимости от выбранного размера и количества.
    order.push_back(output);
    summa += size_price[user_choose - 1] * count;


}
// order_popcorn позволяет пользователю заказать попкорн, выбрав размер и количество.
// Функция изменяет переменную `summa`, чтобы обновить общую стоимость заказа, и добавляет сведения о заказе в вектор `order`.
void order_popcorn(int& summa, vector<string>& order) {
    // Она инициализирует переменные `count` и `user_choose` для хранения количества и выбранного пользователем размера соответственно.
    int count;
    int user_choose;
    // CountOfProduction представляет общее количество доступных размеров попкорна.
    const int CountOfProduction = 3;
    // Массив size_price хранит цены, соответствующие каждому размеру.
    int size_price[CountOfProduction] = { 40, 75, 100 };
    // Массив type хранит строковые представления каждого размера попкорна.
    string type[CountOfProduction] = { "Маленькое", "Среднее", "Большое" };
    // Экран очищается с помощью system("cls"), и пользователю предлагается выбрать размер попкорна с помощью функции ChooseSize.
    system("cls");
    cout << "\n\n\n\nВыберите размер ведра попкорна:" << endl;
    user_choose = menu.ChooseSize(size_price, type);
    // Затем пользователю будет предложено ввести количество попкорна, которое он хочет купить.
    cout << "Как много попкорна хотите купить?" << endl;
    // Функция проверяет входное количество, чтобы убедиться, что оно равно как минимум 1.
    do {
        count = get_input<int>("Ваш выбор >");
        if (count < 1) {
            cout << "Вы не можете заказать такое количество!\n";
        }
    } while (count < 1);
    // Детали заказа форматируются и сохраняются в строке output.
    string output = to_string(count) + " x " + type[user_choose - 1] + " ведро попкорна: " + \
        to_string(count) + " x " + to_string(size_price[user_choose - 1]) + " = " + \
        to_string(count * size_price[user_choose - 1]) + " рублей\n";
    // Эта строка заказа помещается в вектор order, и summa общей стоимости обновляется в зависимости от выбранного размера и количества.
    order.push_back(output);
    summa += size_price[user_choose - 1] * count;

}
// order_chips позволяет пользователю заказывать чипсы, выбирая вкус, размер и количество.
// Функция изменяет переменную summa, чтобы обновить общую стоимость заказа, и добавляет сведения о заказе в вектор order.
void order_chips(int& summa, vector<string>& order) {
    // Она инициализирует переменные count, type_chips и user_size для хранения количества, выбранного варианта и размера соответственно.
    int count;
    int type_chips = 0, user_size;
    // CountOfProduction представляет общее количество доступных размеров чипсов.
    const int CountOfProduction = 3;
    // Массив size_price хранит цены, соответствующие каждому размеру чипсов.
    int size_price[CountOfProduction] = { 49, 89, 129 };
    // Массив type хранит строковые представления каждого размера чипсов.
    string type[CountOfProduction] = { "Маленькая","Средняя","Большая" };
    // Вектор type_product хранит строковые представления доступных разновидностей чипсов.
    vector<string> type_product = { "Лук", "Сметана и зелень", "Краб", "Сыр" };
    // Экран очищается с помощью system("cls"), и пользователю предлагается выбрать тип чипа с помощью функции ChooseProduct.
    system("cls");
    // После выбора варианта пользователю будет предложено выбрать вкус чипсов с помощью ChooseProduct, размер чипсов с помощью функции ChooseSize и их количество.
    cout << "\n\n\n\nВыберите вкус чипсов:" << endl;
    type_chips = menu.ChooseProduct(type_product);
    system("cls");
    cout << "\n\n\n\nРазмер:" << endl;
    user_size = menu.ChooseSize(size_price, type);
    cout << "Как много чипсов хотите купить?" << endl;
    // Функция проверяет входное количество, чтобы убедиться, что оно равно как минимум 1.
    do {
        count = get_input<int>("Ваш выбор >");
        if (count < 1) {
            cout << "Вы не можете заказать такое количество!\n";
        }
    } while (count < 1);
    // Детали заказа форматируются и сохраняются в строке output.
    string output = to_string(count) + " x " + type_product[type_chips - 1] + " " + type[user_size - 1] + \
        " чипсы: " + to_string(count) + " x " + to_string(size_price[user_size - 1]) + " = " + \
        to_string(count * size_price[user_size - 1]) + " рублей\n";
    // Эта строка заказа помещается в вектор order, и summa общей стоимости обновляется на основе выбранного варианта, размера и количества.
    order.push_back(output);
    summa += size_price[user_size - 1] * count;

}
// print_order печатает подробную информацию о заказе пользователя и общую стоимость.
// Функция принимает целое число summa, представляющее общую стоимость, и постоянную ссылку на вектор строк order, содержащий сведения о заказе.
void print_order(int summa, const vector<string>& order) {
    // Прежде чем приступить к печати, проверяется, не является ли вектор заказа пустым.
    // Если заказ не пуст, функция печатает заголовок «Заказ:», за которым следуют сведения о каждом товаре в заказе.
    if (!order.empty()) {
        cout << "Заказ:" << endl << endl;
        // Цикл перебирает каждый элемент вектора order, используя цикл for на основе диапазона.
        for (const auto& i : order) {
            cout << i;
        }
    }
    // После печати деталей заказа функция печатает общую стоимость, добавляя "Итого: " и общую стоимость в рублях.
    cout << endl << "Итого: " << summa << " рублей" << endl;
}

// movie_merchandaise осуществляет заказ товаров из фильмов, таких как напитки и закуски
bool movie_merchandaise() {
    // Она инициализирует переменные result_sum для хранения общей стоимости, order для хранения деталей заказа и ProductList для хранения доступных продуктов.
    int result_sum = 0;
    vector<string> order;
    vector<string>ProductList = { "Заказать колу", "Заказать попкорн", "Чипсы" };
    system("cls");
    // Пользователю предлагается выбрать, хочет ли он заказать напитки или закуски, используя метод YesOrNo.
    cout << "\n\n\n\nВы бы хотели заказать напитки или закуски?" << endl;
    bool next = menu.YesOrNo();
    if (!next) {
        return false;
    }
    // Функция входит в цикл while, позволяя пользователю продолжать делать заказ, пока он не решит этого не делать.
    while (next) {
        int user_chose;
        system("cls");
        // Внутри цикла пользователю предлагается выбрать продукт из меню с помощью метода ChooseProduct.
        cout << "\n\n\nВыберите продукт:" << endl;
        user_chose = menu.ChooseProduct(ProductList);
        // В зависимости от выбора пользователя вызывается соответствующая функция заказа (`order_cola`, `order_popcorn` или `order_chips`) для обработки конкретного продукта.
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
        // После каждого заказа пользователя спрашивают, хочет ли он заказать что-нибудь еще.
        cout << "\n\n\n\nЗаказать что-то ещё?" << endl;
        next = menu.YesOrNo();
    }
    // Как только пользователь завершает заказ, функция вызывает print_order, чтобы отобразить окончательные детали заказа и общую стоимость.
    print_order(result_sum, order);
    system("pause");
    // вызов функции оплаты
    return true;
}


