#include <cassert>
#include <algorithm>
#include <vector>
//Основная библиотека.
#include <iostream>
//Библиотека для работы со строками.
#include <string>
//Библиотека для работы с файлами.
#include <fstream>
//Библиотека для работы с вектором.
#include <vector>
//Библиотека для смены кодировки консоли.
#include <Windows.h>
//Библиотека для подключения алгоритмов сортировки или рандомизации чисел.
#include <ctime>
//Библиотека Артёма, где присутствует класс, со встроенное проверкой вводных данных.
//Все наши библиотеки.
#include "includes.h"
// Библиотека для проверки ввода.
#include "validInput.h"
//Меню
#include "menu.h"

#include "film_hall.h"
#include "saveload.h"

using namespace std;

//void show_cinema(char**, int, int);
//bool buy_ticket(char**, int, int); //принимает зал(массив) номер ряда номер места
//функции не используются, предлагаю удалить

void view_movie_schedules();
// Выбор метода оплаты.
void ChoosePaymentMethod(bool);
// Функция, где в зависимости выбранного способа оплаты, будет происходить конкретная оплата.
bool Oplata(int);
// Генерация QR-кода.
string QRgeneration();


int const ROWS = 3;
int const COLS = 10;
int const TicketCost = 350;
static vector<Film> listFilms;
int main() {
	Menu menu;
	srand(time(nullptr));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try {
		listFilms = loadFilms("films.txt");
	}
	catch (std::runtime_error& e) {
		cout << e.what();
		return 1;
	}

	do {
		system("cls");
		view_movie_schedules();
		saveFilms(listFilms, "films.txt");
		system("cls");
		cout << "\n\n\n\nХотите продолжить?";
	} while (menu.YesOrNo());
}
/*
 * Нужно создать массивы (векторы), где будут храниться название фильмов и их описание
 * switch (choice_movie) сменить на пробег циклом по listFilms
 * */
void view_movie_schedules() {
	Menu menu(ROWS, COLS);
	int choice_movie; //Инициализация переменных для выбора фильма и для выбора сеанса
	bool answer = false; //Инициализируем переменную для возврата к выбору меню
	while (!answer) {
		cout << "\nФильмы доступные на 01 января: \n\n";
		for (size_t i = 0; i < listFilms.size(); ++i) {
			cout << i + 1 << ") " << listFilms[i].name << endl;
		}
		cout << endl;
		cout << "Выберите фильм: ";
		choice_movie = menu.ChooseFilm(listFilms);
		/*for (const auto& i : listFilms[choice_movie - 1]) {
			cout << i << endl;
		}*/
		Film& chosen_film = listFilms[choice_movie - 1];
		cout << chosen_film.desc << endl;

		// Артем, сделай выбор холла

		system("pause");
		system("cls");
		menu.SetCursor(24, 6);
		cout << "Хотите продолжить работу?";
		answer = menu.YesOrNo();
		system("cls");
		if (answer) {
			menu.SetCursor(24, 6);
			cout << "\nВыберите зал: ";
			Hall& hall = chosen_film.halls[menu.ChooseHall(chosen_film.halls)-1];
			system("cls");
			menu.SetCursor(24, 6);
			cout << "\nХотите забронировать, купить или вернуться назад?";
			char choose = menu.ChooseTicket();
			system("cls");
			int TicketBills;
			string output;
			bool PayGoOn = true;

			switch (choose) { // Переход к другим функциям.
			case('R'):
				cout << "\n\n\n\n\n\n\t\t\tВыберите Место(а) для бронирования:" << endl;
				menu.ChoosePlaceOnCinema(hall.data, hall.rows, hall.cols, true);
				//ВЫставление счёта за билеты
				system("cls");
				TicketBills = menu.Bills(TicketCost);
				output = to_string(TicketBills / TicketCost) + " x " + " билет на фильм: " + \
					to_string(TicketBills / TicketCost) + " x " + to_string(TicketCost) + " = " + \
					to_string(TicketBills) + " рублей\n";
				cout << output;
				system("pause");
				ChoosePaymentMethod(PayGoOn);
				PayGoOn = movie_merchandaise();
				ChoosePaymentMethod(PayGoOn);
				break;
			case('P'):
				cout << "\n\n\n\n\n\n\t\t\tВыберите Место(а) для покупки:" << endl;
				menu.ChoosePlaceOnCinema(hall.data, hall.rows, hall.cols, false);
				//ВЫставление счёта за билеты
				system("cls");
				TicketBills = menu.Bills(TicketCost);
				output = to_string(TicketBills / TicketCost) + " x " + " билет на фильм: " + \
					to_string(TicketBills / TicketCost) + " x " + to_string(TicketCost) + " = " + \
					to_string(TicketBills) + " рублей\n";
				cout << output;
				system("pause");
				ChoosePaymentMethod(PayGoOn);
				PayGoOn = movie_merchandaise();
				ChoosePaymentMethod(PayGoOn);
				break;
			default:
				view_movie_schedules();
				break;
			}
		}
	}
}

string QRgeneration() {
	const int lengthOfCode = 5;
	string QR = "";
	for (int i = 0; i < lengthOfCode*lengthOfCode; i++)
	{
		QR += to_string(0 + rand() % 2);
	}
	for (int i = 0; i < lengthOfCode * lengthOfCode; i++)
	{
		if (i % lengthOfCode == 0) {
			cout << '\n';
		}
		cout << QR[i];
	}
	return QR;
}
bool Oplata(int num) {
	if (num == 1) {
		cout << "Производится оплата...";
		Sleep(1000);
		cout << "\nОплата наличкой прошла успешно!";
		return true;
	}
	if (num == 2) {
		cout << "Производится полата...";
		Sleep(1000);
		cout << "\nОплата по карте прошла успешно!";
		return true;
	}
	if (num == 3) {
		cout << "Производится генерация вашего персонального QRcode...";
		Sleep(1000);
		cout << "\nВаш персональный QRcode: ";
		QRgeneration();
		return true;
	}
	return false;
}
void ChoosePaymentMethod(bool letsPay = true) {
	if (letsPay) {
		bool flag;
		Menu menu;
		vector <string> PayList{"Наличные", "Карта", "QR-code"};
		do
		{
			system("cls");
			cout << "\n\nВыберите метод оплаты:";
			int temp = menu.ChooseProduct(PayList);
			Oplata(temp);
			cout << '\n';
			system("pause");
			system("cls");
			cout << "\n\n\nВы согласны с выбором оплаты? Если нет, мы вернём затраченные средства";
		} while (!menu.YesOrNo());
	}
}
