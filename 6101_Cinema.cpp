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
//Лучше переименовать файл в .h
#include "bestinput.cpp"
//Все наши библиотеки.
#include "includes.h"
// Библиотека для проверки ввода.
#include "validInput.h"

using namespace std;

void show_cinema(char**,int,int);
bool buy_ticket(char**, int, int); //принимает зал(массив) номер ряда номер места
char** create_hall(int,int);
void view_movie_schedules();

/* От Артёма: функции для имитации оплаты и покупки */
// Перечисление различных способов оплаты.
enum Operation {
	Cash = 0,
	Card = 1,
	QRcode = 2
};
// Выбор метода оплаты.
void ChoosePaymentMethod();
// Функция, где в зависимости выбранного способа оплаты, будет происходить конкретная оплата.
bool Oplata(Operation);
// Генерация QR-кода.
string QRgeneration();

// Тип места place.first - ряд place.second - место.
typedef std::pair<int,int> place;

int score_place(int n, int m, const place& pl){
	return std::abs(pl.first-n/2) + std::abs(pl.second-m/2);
}

// Возвращает вектор с местами, где справа от них есть num мест типа type (0 - пустое).
// Места ближе к центру первее в массиве.
vector<place> find_close_seats(char** cinema, int n, int m, int num, int type = 0) {
	vector<place> places;

	for(int i = 0; i < n; i++){
		int seq = 0;
		for (int j = 0; j < m; j++) {
			if(cinema[i][j] == type){
				seq++;
				if(seq >= num)
					places.emplace_back(i, j-num+1);
			}
		}
	}

	sort(places.begin(), places.end(), [n,m](const place& a, const place& b){return score_place(n, m, a) < score_place(n, m, b) ;});

	return move(places);
}

bool h_file_save(char** arr, int n, int m, const char* filename = "cinema.dat"){
	std::ofstream f(filename, std::ios::binary | std::ios::trunc); // открыть файл в бинарном режиме и удалить содержимое
	
	if(!f.is_open())
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

bool h_file_load(char** arr, int n, int m, const char* filename = "cinema.dat"){
	std::ifstream f(filename, std::ios::binary); // открыть файл в бинарном режиме
	
	if(!f.is_open())
		return false;
	
	int fn, fm;
	// читаем размеры
	f.read(reinterpret_cast<char*>(&fn), sizeof fn);
	f.read(reinterpret_cast<char*>(&fm), sizeof fm);
	
	if(f.fail() || n != fn || m != fm)
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
	
	srand(time(nullptr));
//  setlocale(LC_ALL, "ru");
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
    char choice = 'Y';
    do {
        view_movie_schedules();
        choice = get_input<char>("Если хотите продолжить, то введите Y >");
		
		h_file_save(cinema1, ROWS, COLS);
    } while (choice == 'Y');
}
/*
 * Нужно создать массивы (векторы), где будут храниться название фильмов и их описание
 * switch (choice_movie) сменить на пробег циклом по listFilms
 * */
void view_movie_schedules() {
	int choice_movie, choice_session = 0; //Инициализация переменных для выбора фильма и для выбора сеанса
	char answer = 'B'; //Инициализируем переменную для возврата к выбору меню
    vector<vector<string>> listFilms = {{"Барби. |12+|",
                       "2023 г. Комедия/Фэнтези",
                       "США, 1 ч 54 мин",
                       "Режиссёр: Грета Гервиг",
                       "Дистрибьютор: Warner Bros. Pictures",
                       "Барби выгоняют из Барбиленда, потому что она не соответствует его нормам красоты.",
                       "Тогда она начинает новую жизнь в реальном мире, где обнаруживает, что совершенства",
                       "можно достичь только благодаря внутренней гармонии.",
                       "Сегодня есть сеансы на: ",
                       "1) 13:50"}
    }; // Массив с фильмами

	while (answer == 'B') {
        cout << "\nФильмы на 01 января: \n\n";
        for (size_t i = 0; i < listFilms.size(); ++i) {
            cout << i+1 << ") " << listFilms[i][0] << endl;
        }
        cout << endl;
        //Проверка на дурачка, совмещённая с проверкой на выбор фильма, который в прокате
        choice_movie = get_input<int>("Выберите фильм и напишете его номер >");
		while (!(1 <= choice_movie && choice_movie <= listFilms.size())) { // Проверка, что введенное значение находится в нужном диапазоне индексов списка фильмов.
			cout << "\nИзвините, но такого фильма сейчас нет в прокате :(\n";
            choice_movie = get_input<int>("Выберите фильм и напишете его номер заново >");
		}
        for (const auto& i: listFilms[choice_movie-1]) {
            cout << i << endl;
        }
        do { // Пока значение переменной не будет F или B, то будем заново запрашивать изменение переменной.
            cout << "\nХотите продолжить работу или вернуться назад?\n";
            answer = get_input<char>("Введите F - если продолжить, B - если вернуться назад >");  // Изменение переменной.
        } while (!(answer == 'F' || answer == 'B'));

        if (answer == 'F') {
            do {// Пока значение переменной не будет R, P или B, то будем заново запрашивать изменение переменной.
                cout << "\nХотите забронировать, купить или вернуться назад?\n";
                answer = get_input<char>("Введите R - если забронировать, P - если купить билет B - если вернутся назад >");
            } while (!(answer == 'R' || answer == 'P' || answer == 'B'));
            show_cinema(cinema1, 3, 10);

            switch (answer) { // Переход к другим функциям.
            case('R'):
                Ticket_reservation_or_buy(cinema1, ROWS, COLS, true);
                movie_merchandaise();
                ChoosePaymentMethod();
                break;
            case('P'):
                Ticket_reservation_or_buy(cinema1, ROWS, COLS, false);
                movie_merchandaise();
                ChoosePaymentMethod();
                break;
            }
        }
	}
}

void show_cinema(char** arr, int n, int m) {
    cout << "  "; // для форматированного вывода
    for (int j = 0; j < m; j++) {
        cout << j+1 << ' ';
    }
    cout << endl;
	for (int i = 0; i < n; i++) {
        cout << i+1 << ' ';
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

bool buy_ticket(char** arr, int n , int m) {
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
bool Oplata(Operation op) {
	if (op == Cash) {
		cout << "Производится полата...";
		Sleep(1000);
		cout << "\nОплата наличкой прошла успешно!";
		return true;
	}
    if (op == Card) {
		cout << "Производится полата...";
		Sleep(1000);
		cout << "\nОплата по карте прошла успешно!";
		return true;
	}
    if (op == QRcode) {
		cout << "Производится генерация вашего персонального QRcode...";
		Sleep(1000);
		cout << "\nВаш персональный QRcode: " << QRgeneration();
		return true;
	}
    return false;
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
			cout << "\nВыберете способ оплаты(qrcode/карта/наличные) >";
			temp = input.InputString();
			if (temp == "qrcode") { Oplata(QRcode); }
			else if (temp == "карта") { Oplata(Card); }
			else if (temp == "наличные") { Oplata(Cash); }
			else {
                cout << "Вы ввели способ оплаты, которого у нас нет! Повторите запрос";
                flag = true;}
		} while (flag);
		cout << "\nВы согласны с выбором? Если нет, мы оформим возврат(да/нет) >";
	} while (!input.YesOrNo());
}
