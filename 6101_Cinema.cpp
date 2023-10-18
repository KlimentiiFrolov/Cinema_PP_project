﻿// 6101_Cinema.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void show_cinema(bool**,int,int);
bool buy_ticket(bool**, int, int); //принимает зал(массив) номер ряда номер места
bool** create_hall(int,int);
int view_movie_schedules(); //Возвращает какой фильм и какой сеанс выбрал пользователь

int main()
{
	bool** cinema1 = create_hall(3, 10);
	show_cinema(cinema1, 3, 10);
}

int view_movie_schedules() {
	int choice_movie = 0, choice_session = 0; //Инициалиация переменных для выбора фильма и для выбора сеанса

	cout << "Фильмы на 01 января: \n\n"
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
			<< "1) 13:50\n\n"
			<< "Выберите сеанс и напишите его номер: ";

		while (!(cin >> choice_session) || (cin.peek() != '\n') || !(choice_session == 1)) { //Проверка на дурачка, совмещённая с проверкой на выбор сенса, который существует
			cin.clear();
			while (cin.get() != '\n');
			cout << "\nИзвините, но данного сеанса не существует :(\n"
				<< "Выберите сеанс и напишите его номер заново: ";
		}
		break;
	}
	return choice_movie, choice_session; //!!!Не знаю как осуществить возврат этих двух переменных!!!
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

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
