#include<iostream>
using namespace std;

float order_cola() {
    int count;
    float cola_price = 100;
    cout << "How many bottles of cola do you want to buy?" << endl << "Your chose: ";
    cin >> count;
    return cola_price * count;

}
float order_popcorn() {
    int count;
    float popcorn_price = 100;
    cout << "How many buckets of popcorn do you want to order?" << endl << "Your chose: ";
    cin >> count;
    return popcorn_price * count;

}



float movie_merchandaise() {
    float result_sum = 0;
    char next;

    cout << "Would you like to purchase any drinks or snacks for the movie?" << endl << "Type Y - for Yes" << endl << "Your chose: ";
    cin >> next;

    while (next == 'Y') {
        int user_chose;
        cout << "Select a product:\n1 - Order Cola\n2 - Order popcorn" << endl << "Your chose:";
        cin >> user_chose;
        switch (user_chose) {
        case 1:
            result_sum += order_cola();
            break;
        case 2:
            result_sum += order_popcorn();
            break;
        }

        cout << "Continue ordering?" << endl << "Type Y - for Yes" << endl << "Your chose: ";
        cin >> next;
    }

    cout << "Sum of your order: " << result_sum << " RUB" << endl;
    return result_sum;
}
