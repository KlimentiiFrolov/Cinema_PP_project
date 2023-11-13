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
#include "bestinput.h"
//Все наши библиотеки.
#include "includes.h"
// Библиотека для проверки ввода.
#include "validInput.h"
//Меню
#include "menu.h"

#include "film_hall.h"
#include "saveload.h"
#include "Overview.h"

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
	//Для создания меню, мне нужно было протестить, если есть несколько фильмов
	/*vector<vector<string>> listFilms = {{"Барби. |12+|",
					   "2023 г. Комедия/Фэнтези",
					   "США, 1 ч 54 мин",
					   "Режиссёр: Грета Гервиг",
					   "Дистрибьютор: Warner Bros. Pictures",
					   "Барби выгоняют из Барбиленда, потому что она не соответствует его нормам красоты.",
					   "Тогда она начинает новую жизнь в реальном мире, где обнаруживает, что совершенства",
					   "можно достичь только благодаря внутренней гармонии.",
					   "Сегодня есть сеансы на: ",
					   "1) 13:50"},
						{"Обитель зла. |18+|",
					   "2002 г. Ужасы/Боевик/Фантастика",
					   "США/Германия, 1 ч 40 мин",
					   "Режиссёр: Пол У.С.Андерсон",
					   "Дистрибьютор: Sony Pictures Releasing",
					   "В гигантской подземной лаборатории выходит из-под контроля опаснейший вирус и мгновенно",
					   "превращает своих жертв в прожорливых зомби. Достаточно одного их укуса или царапины, чтобы",
					   "человек стал обезумевшим пожирателем живой плоти.",
					   "Сегодня есть сеансы на: ",
					   "1) 16:50"},
						{"Бабушка легкого поведения. |16+|",
						"2017 г. Комедия ",
						"Россия, 1 ч 26 мин",
						"Режиссер: Марюс Вайсберг",
						"Дистрибьютор: КароПрокат",
						"Мастер перевоплощений Саня по прозвищу Трансформер провернул кучу афер, точь-в-точь изображая десятки персонажей.",
						"Но в этот раз он украл не у тех… Теперь у парня на хвосте очень плохие люди с пистолетами.",
						"Саня решает залечь на дно в доме престарелых в образе пожилой тети.И когда ему казалось, что он попал в безвыходную ситуацию,",
						"новый поворот судьбы дарит ему любовь и надежду превратиться в приличного человека.",
						"Сегодня есть сеансы на: ",
						"1) 20:00",
						"2) 22:00"},
						{"Легенда №17. |6+|",
						"2012 г. Биография/Спорт/Драма",
						"Россия, 2 ч 14 мин",
						"Режиссер: Николай Лебедев",
						"Дистрибьютор: Централ Партнершип",
						"2 сентября 1972 года. Монреаль. Хоккейная сборная СССР с разгромным счетом 7:3 победила канадских профессионалов из НХЛ в стартовом матче эпохальной Суперсерии СССР-Канада.",
						"Это была не просто игра, это была битва за свою страну, которая перевернула мировое представление о хоккее.",
						"Теперь весь мир знал его просто по номеру «17». Валерий Харламов, забивший в том матче 2 шайбы мгновенно взлетел на вершину славы.",
						"Сбылась его мечта –упорство, спортивный талант и суровые уроки великого тренера Анатолия Тарасова сделали из «номера 17» легенду мирового хоккея.",
						"Сегодня есть сеансы на: ",
						"1) 8:00",
						"2) 11:00"},

	}; // Массив с фильмами*/

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
		Hall& hall = chosen_film.halls[0];

		system("pause");
		system("cls");
		menu.SetCursor(24, 6);
		cout << "Хотите продолжить работу?";
		answer = menu.YesOrNo();
		system("cls");
		if (answer) {
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
				//ChoosePaymentMethod(PayGoOn);
				//PayGoOn = movie_merchandaise();
				//ChoosePaymentMethod(PayGoOn);
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

//void show_cinema(char** arr, int n, int m) {
//	cout << "  "; // для форматированного вывода
//	for (int j = 0; j < m; j++) {
//		cout << j + 1 << ' ';
//	}
//	cout << endl;
//	for (int i = 0; i < n; i++) {
//		cout << i + 1 << ' ';
//		for (int j = 0; j < m; j++) {
//			cout << arr[i][j] << ' ';
//		}
//		cout << endl;
//	}
//}
//
//bool buy_ticket(char** arr, int n, int m) {
//	if (arr[n][m] == '0') {
//		arr[n][m] = '1';
//		return true; // успех!!!
//	}
//	else {
//		cout << "ну ты чего, занято же...";
//		return false; // провал((((
//	}
//}
// мертвый код

string QRgeneration() {
	const int lengthOfCode = 20;
	string QR = "";
	for (int i = 0; i < lengthOfCode; i++)
	{
		QR += (char)(48 + rand() % 9);
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
		cout << "\nВаш персональный QRcode: " << QRgeneration();
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
