//Основаная библиотека
#include <iostream>
#include <cassert>
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
//Библиотека Артёма, где присутствует класс, со встроенное проверкой вводных данных
#include "bestinput.cpp"
using namespace std;

void show_cinema(bool**,int,int);
bool buy_ticket(bool**, int, int); //принимает зал(массив) номер ряда номер места
bool** create_hall(int,int);
void view_movie_schedules();

/*От Артёма: функции для имитации оплаты и покупки*/
//Перечисление различных способов оплаты
enum Operation {
	Cash = 0,
	Card = 1,
	QRcode = 2
};
//Выбор метода оплаты
void ChoosePaymentMethod();
//Функция, где в зависимости выбранного способа оплаты, будет происходить конкретная оплата
bool Oplata(Operation);
//Генерация QR-кода
string QRgeneration();

// тип места place.first - ряд place.second - место
typedef std::pair<int,int> place;

int score_place(int n, int m, const place& pl){
	return std::abs(pl.first-n/2) + std::abs(pl.second-m/2);
}

// возвращает вектор с местами, где справа от них есть num мест типа type (0 - пустое)
// места ближе к центру первее в массиве
std::vector<place> find_close_seats(char** cinema, int n, int m, int num, int type = 0) {
	std::vector<place> places;

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

	std::sort(places.begin(), places.end(), [n,m](const place& a, const place& b){return score_place(n, m, a) < score_place(n, m, b) ;});

	return std::move(places);
}

namespace tests
{
	void test_Distribution(){
		char** cinema = new char*[10];
		for (int i = 0; i < 10; i++){
			cinema[i] = new char[10]{};
			for (int j = 0; j < 10; j++) {
				cinema[i][j] = 1;
			}
		}

		cinema[5][4] = 0;
		cinema[5][5] = 0;
		cinema[5][6] = 0;

		auto res = find_close_seats(cinema, 10, 10, 3);

		assert(res.size() == 1);
		assert(res[0].first == 5);
		assert(res[0].second == 4);

		cinema[5][7] = 0;

		res = find_close_seats(cinema, 10, 10, 3);

		assert(res.size() == 2);
		assert(res[0].first == 5);
		assert(res[0].second == 5);
		assert(res[1].first == 5);
		assert(res[1].second == 4);

		cinema[5][7] = 1;

		cinema[4][4] = 0;
		cinema[4][5] = 0;
		cinema[4][6] = 0;

		res = find_close_seats(cinema, 10, 10, 3);

		assert(res.size() == 2);
		assert(res[0].first == 5);
		assert(res[0].second == 4);
		assert(res[1].first == 4);
		assert(res[1].second == 4);

		/*for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << (int)cinema[i][j] << ' ';
			}
			cout << endl;
		}*/
	}
}

int main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool** cinema1 = create_hall(3, 10);
	show_cinema(cinema1, 3, 10);
	ChoosePaymentMethod();
}

void view_movie_schedules() {
	int choice_movie = 0, choice_session = 0; //Инициалиация переменных для выбора фильма и для выбора сеанса
	char answer = 'B'; //Инициализируем переменную для возврата к выбору меню

	while (answer == 'B') {
		cout << "\nФильмы на 01 января: \n\n"
			<< "1) Барби\n\n"
			<< "Выберите фильм и напишете его номер: ";

		while (!(cin >> choice_movie) || (cin.peek() != '\n') || !(choice_movie == 1)) { //Проверка на дурачка, совмещённая с проверкой на выбор фильма, который в прокате
			cin.clear();
			while (cin.get() != '\n');
			cout << "\nИзвините, но такого фильма сейчас нет в прокате :(\n"
				<< "Выберите фильм и напишете его номер заново: ";
		}

		switch (choice_movie) {
		case 1:

			cout << "\nБарби. |12+|\n"
				<< "2023 г. Комедия/Фэнтези\n"
				<< "США, 1 ч 54 мин\n"
				<< "Режиссёр: Грета Гервиг\n"
				<< "Дистрибьютор: Warner Bros. Pictures\n"
				<< "Барби выгоняют из Барбиленда, потому что она не соответствует его нормам красоты.\n"
				<< "Тогда она начинает новую жизнь в реальном мире, где обнаруживает, что совершенства\n"
				<< "можно достичь только благодаря внутренней гармонии.\n\n"
				<< "Сегодня есть сеансы на: \n"
				<< "1) 13:50\n\n";

			do { //Пока значение переменной не будет F или B, то будем заново запрашивать изменение переменной
				cout << "\nХотите продолжить работу или вернуться назад?\n"
					<< "Введите F - если продолжить, B - если вернуться назад: ";
				cin >> answer; //Изменение переменной
			} while ((answer != 'F') && (answer != 'B'));

			if (answer == 'F') {
				do {//Пока значение переменной не будет R, P или B, то будем заново запрашивать изменение переменной
					cout << "\nХотите забронировать, купить или вернуться назад?\n"
						<< "Введите R - если забронировать, P - если купить билет B - если вернутся назад :";
					cin >> answer;
				}while ((answer != 'R') && (answer != 'P') && (answer != 'B'));

				switch (answer) { //Переход к другим функциям
				case('R'):
					//Переход на функцию брони
					break;
				case('P'):
					//Переход на функцию покупки
					break;
				}
			}
			break;
		}
	}
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
