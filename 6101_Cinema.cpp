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

using namespace std;

void show_cinema(char**, int, int);
bool buy_ticket(char**, int, int); //принимает зал(массив) номер ряда номер места
char** create_hall(int, int);
void view_movie_schedules();

/* От Артёма: функции для имитации оплаты и покупки */
// Перечисление различных способов оплаты.
//enum Operation {
//	Cash = 0,
//	Card = 1,
//	QRcode = 2
//};
// Выбор метода оплаты.
void ChoosePaymentMethod();
// Функция, где в зависимости выбранного способа оплаты, будет происходить конкретная оплата.
bool Oplata(int);
// Генерация QR-кода.
string QRgeneration();

// Тип места place.first - ряд place.second - место.
typedef std::pair<int, int> place;

int score_place(int n, int m, const place& pl) {
	return std::abs(pl.first - n / 2) + std::abs(pl.second - m / 2);
}

// Возвращает вектор с местами, где справа от них есть num мест типа type (0 - пустое).
// Места ближе к центру первее в массиве.
vector<place> find_close_seats(char** cinema, int n, int m, int num, int type = 0) {
	vector<place> places;

	for (int i = 0; i < n; i++) {
		int seq = 0;
		for (int j = 0; j < m; j++) {
			if (cinema[i][j] == type) {
				seq++;
				if (seq >= num)
					places.emplace_back(i, j - num + 1);
			}
		}
	}

	sort(places.begin(), places.end(), [n, m](const place& a, const place& b) {return score_place(n, m, a) < score_place(n, m, b); });

	return move(places);
}

bool h_file_save(char** arr, int n, int m, const char* filename = "cinema.dat") {
	std::ofstream f(filename, std::ios::binary | std::ios::trunc); // открыть файл в бинарном режиме и удалить содержимое

	if (!f.is_open())
		return false;

	// сохраняем размеры
	f.write(reinterpret_cast<char*>(&n), sizeof n);
	f.write(reinterpret_cast<char*>(&m), sizeof m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			f.put(arr[i][j]);
		}
	}

	return true;
}

bool h_file_load(char** arr, int n, int m, const char* filename = "cinema.dat") {
	std::ifstream f(filename, std::ios::binary); // открыть файл в бинарном режиме

	if (!f.is_open())
		return false;

	int fn, fm;
	// читаем размеры
	f.read(reinterpret_cast<char*>(&fn), sizeof fn);
	f.read(reinterpret_cast<char*>(&fm), sizeof fm);

	if (f.fail() || n != fn || m != fm)
		return false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = f.get();
		}
	}

	return true;
}

int const ROWS = 3;
int const COLS = 10;
char** cinema1 = nullptr;
int main() {
	cinema1 = create_hall(ROWS, COLS);
	h_file_load(cinema1, ROWS, COLS);
	Menu menu;
	srand(time(nullptr));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	do {
		system("cls");
		view_movie_schedules();
		h_file_save(cinema1, ROWS, COLS);
		system("cls");
		cout << "\n\n\n\nХотите продолжить?";
	} while (menu.YesOrNo());
}
/*
 * Нужно создать массивы (векторы), где будут храниться название фильмов и их описание
 * switch (choice_movie) сменить на пробег циклом по listFilms
 * */
void view_movie_schedules() {
	Menu menu;
	int choice_movie; //Инициализация переменных для выбора фильма и для выбора сеанса
	bool answer = false; //Инициализируем переменную для возврата к выбору меню
	//Для создания меню, мне нужно было протестить, если есть несколько фильмов
	vector<vector<string>> listFilms = { {"Барби. |12+|",
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
	}; // Массив с фильмами

	while (!answer) {
		cout << "\nФильмы доступные на 01 января: \n\n";
		for (size_t i = 0; i < listFilms.size(); ++i) {
			cout << i + 1 << ") " << listFilms[i][0] << endl;
		}
		cout << endl;
		cout << "Выберите фильм: ";
		choice_movie = menu.ChooseFilm(listFilms);
		for (const auto& i : listFilms[choice_movie - 1]) {
			cout << i << endl;
		}
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
			switch (choose) { // Переход к другим функциям.
                case('R'):
                    cout << "\n\n\n\n\n\n\t\t\tВыберите Место(а) для бронирования:" << endl;
                    menu.ChoosePlaceOnCinema(cinema1, ROWS, COLS, true);
                    movie_merchandaise();
                    ChoosePaymentMethod();
                    break;
                case('P'):
                    cout << "\n\n\n\n\n\n\t\t\tВыберите Место(а) для покупки:" << endl;
                    menu.ChoosePlaceOnCinema(cinema1, ROWS, COLS, false);
                    movie_merchandaise();
                    ChoosePaymentMethod();
                    break;
                default:
                    view_movie_schedules();
                    break;
			}
		}
	}
}

void show_cinema(char** arr, int n, int m) {
	cout << "  "; // для форматированного вывода
	for (int j = 0; j < m; j++) {
		cout << j + 1 << ' ';
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ' ';
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

char** create_hall(int n, int m) {

	char** arr = new char* [n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = new char[m]; // 0 - свободное место, 1 - занято
		memset(arr[i], '0', m); // инициализация массива '0'
	}
	return arr;
}

bool buy_ticket(char** arr, int n, int m) {
	if (arr[n][m] == '0') {
		arr[n][m] = '1';
		return true; // успех!!!
	}
	else {
		cout << "ну ты чего, занято же...";
		return false; // провал((((
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
void ChoosePaymentMethod() {
	bool flag;
	Menu menu;
	vector <string> PayList{"Наличные","Карта","QR-code"};
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
