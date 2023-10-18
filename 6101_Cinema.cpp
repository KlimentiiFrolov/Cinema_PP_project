//Основаная библиотека
#include <iostream>
//Библиотека для работы со строками
#include <string>
//Библиотека для работы с файлами
#include <fstream>
//Библиотека для работы с вектором
#include <vector>
//Библиотека для смены кодировки консоли
#include <Windows.h>
//Библиотека для подключения алгоритмов сортировки или рандомизации чисел
#include <algorithm>
//Библиотека Артёма, где присутсвует класс, со встроенное проверкой вводных данных
#include "bestinput.cpp"
using namespace std;

void show_cinema(bool**,int,int);
bool buy_ticket(bool**, int, int); //принимает зал(массив) номер ряда номер места
bool** create_hall(int,int);

/*От Артёма: функции для имитации оплаты и покупки*/
//Перечисление различных способов оплаты
enum Operation {
	Cash = 0,
	Card = 1,
	QRcode = 2
};
//Выбор метода оплаты
void ChoosePaymentMethod();
//Фуекция, где взависимости выбранного способа оплаты, будет происходить конкретная оплата
bool Oplata(Operation);
//Генерация QR-кода
string QRgeneration();

int main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool** cinema1 = create_hall(3, 10);
	show_cinema(cinema1, 3, 10);
	ChoosePaymentMethod();
}

void show_cinema(bool** arr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

bool** create_hall(int n, int m) {

    bool** arr = new bool* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new bool[m] {}; // 0 - свободное место, 1 - занято
	}
	return arr;
}

bool buy_ticket(bool** arr, int n , int m) {
	if (arr[n][m] == 0) {
		arr[n][m] = 1;
		return 1; // успех!!!
	}
	else {
		cout << "ну ты чего, занято же...";
		return 0; // провал((((
	}
}

string QRgeneration() {
	const int lengthOfCode = 20;
	string QR = "";
	for (int i = 0; i < lengthOfCode; i++)
	{
		QR += (char)(48 + rand() % 9);
	}
	return QR;
}
bool Oplata(Operation op) {
	if (op == Cash) {
		cout << "Производится полата...";
		Sleep(1000);
		cout << "\nОплата наличкой прошла успешно!";
		return true;
	}
	else if (op == Card) {
		cout << "Производится полата...";
		Sleep(1000);
		cout << "\nОплата по карте прошла успешно!";
		return true;
	}
	else if (op == QRcode) {
		cout << "Производится генерация вашего персонального QRcode...";
		Sleep(1000);
		cout << "\nВаш персональный QRcode: " << QRgeneration();
		return true;
	}
}
void ChoosePaymentMethod() {
	BestInput input;
	bool flag;
	do
	{
		do
		{
			flag = false;
			string temp;
			cout << "\nВыбирете способ оплаты(qrcode/карта/наличные): ";
			temp = input.InputString();
			if (temp == "qrcode") { Oplata(QRcode); }
			else if (temp == "карта") { Oplata(Card); }
			else if (temp == "наличные") { Oplata(Cash); }
			else { cout << "Вы ввели способ оплаты, которого у нас нет! Повторите запрос"; flag = true; }
		} while (flag);
		cout << "\nВы согласны с выбором? Если нет, мы оформим возврат(да/нет): ";
	} while (input.YesOrNo() == false);
}
