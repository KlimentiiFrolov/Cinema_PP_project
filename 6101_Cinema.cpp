#include <cassert>
#include <algorithm>
#include <vector>
//�������� ����������.
#include <iostream>
//���������� ��� ������ �� ��������.
#include <string>
//���������� ��� ������ � �������.
#include <fstream>
//���������� ��� ������ � ��������.
#include <vector>
//���������� ��� ����� ��������� �������.
#include <Windows.h>
//���������� ��� ����������� ���������� ���������� ��� ������������ �����.
#include <ctime>
//���������� �����, ��� ������������ �����, �� ���������� ��������� ������� ������.
#include "bestinput.h"
//��� ���� ����������.
#include "includes.h"
// ���������� ��� �������� �����.
#include "validInput.h"
//����
#include "menu.h"

using namespace std;

void show_cinema(char**, int, int);
bool buy_ticket(char**, int, int); //��������� ���(������) ����� ���� ����� �����
char** create_hall(int, int);
void view_movie_schedules();

/* �� �����: ������� ��� �������� ������ � ������� */
// ������������ ��������� �������� ������.
//enum Operation {
//	Cash = 0,
//	Card = 1,
//	QRcode = 2
//};
// ����� ������ ������.
void ChoosePaymentMethod();
// �������, ��� � ����������� ���������� ������� ������, ����� ����������� ���������� ������.
bool Oplata(int);
// ��������� QR-����.
string QRgeneration();

// ��� ����� place.first - ��� place.second - �����.
typedef std::pair<int, int> place;

int score_place(int n, int m, const place& pl) {
	return std::abs(pl.first - n / 2) + std::abs(pl.second - m / 2);
}

// ���������� ������ � �������, ��� ������ �� ��� ���� num ���� ���� type (0 - ������).
// ����� ����� � ������ ������ � �������.
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
	std::ofstream f(filename, std::ios::binary | std::ios::trunc); // ������� ���� � �������� ������ � ������� ����������

	if (!f.is_open())
		return false;

	// ��������� �������
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
	std::ifstream f(filename, std::ios::binary); // ������� ���� � �������� ������

	if (!f.is_open())
		return false;

	int fn, fm;
	// ������ �������
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
		cout << "\n\n\n\n������ ����������?";
	} while (menu.YesOrNo());
}
/*
 * ����� ������� ������� (�������), ��� ����� ��������� �������� ������� � �� ��������
 * switch (choice_movie) ������� �� ������ ������ �� listFilms
 * */
void view_movie_schedules() {
	Menu menu;
	int choice_movie; //������������� ���������� ��� ������ ������ � ��� ������ ������
	bool answer = false; //�������������� ���������� ��� �������� � ������ ����
	//��� �������� ����, ��� ����� ���� ����������, ���� ���� ��������� �������
	vector<vector<string>> listFilms = { {"�����. |12+|",
					   "2023 �. �������/�������",
					   "���, 1 � 54 ���",
					   "�������: ����� ������",
					   "������������: Warner Bros. Pictures",
					   "����� �������� �� ����������, ������ ��� ��� �� ������������� ��� ������ �������.",
					   "����� ��� �������� ����� ����� � �������� ����, ��� ������������, ��� ������������",
					   "����� ������� ������ ��������� ���������� ��������.",
					   "������� ���� ������ ��: ",
					   "1) 13:50"},
						{"������� ���. |18+|",
					   "2002 �. �����/������/����������",
					   "���/��������, 1 � 40 ���",
					   "�������: ��� �.�.��������",
					   "������������: Sony Pictures Releasing",
					   "� ���������� ��������� ����������� ������� ��-��� �������� ���������� ����� � ���������",
					   "���������� ����� ����� � ����������� �����. ���������� ������ �� ����� ��� ��������, �����",
					   "������� ���� ����������� ����������� ����� �����.",
					   "������� ���� ������ ��: ",
					   "1) 16:50"},
	}; // ������ � ��������

	while (!answer) {
		cout << "\n������ ��������� �� 01 ������: \n\n";
		for (size_t i = 0; i < listFilms.size(); ++i) {
			cout << i + 1 << ") " << listFilms[i][0] << endl;
		}
		cout << endl;
		cout << "�������� �����: ";
		choice_movie = menu.ChooseFilm(listFilms);
		for (const auto& i : listFilms[choice_movie - 1]) {
			cout << i << endl;
		}
		system("pause");
		system("cls");
		menu.SetCursor(24, 6);
		cout << "������ ���������� ������?";
		answer = menu.YesOrNo();
		system("cls");
		if (answer) {
			menu.SetCursor(24, 6);
			cout << "\n������ �������������, ������ ��� ��������� �����?";
			char choose = menu.ChooseTicket();
			system("cls");
			switch (choose) { // ������� � ������ ��������.
                case('R'):
                    cout << "\n\n\n\n\n\n\t\t\t�������� �����(�) ��� ������������:" << endl;
                    menu.ChoosePlaceOnCinema(cinema1, ROWS, COLS, true);
                    movie_merchandaise();
                    ChoosePaymentMethod();
                    break;
                case('P'):
                    cout << "\n\n\n\n\n\n\t\t\t�������� �����(�) ��� �������:" << endl;
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
	cout << "  "; // ��� ���������������� ������
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
		arr[i] = new char[m]; // 0 - ��������� �����, 1 - ������
		memset(arr[i], '0', m); // ������������� ������� '0'
	}
	return arr;
}

bool buy_ticket(char** arr, int n, int m) {
	if (arr[n][m] == '0') {
		arr[n][m] = '1';
		return true; // �����!!!
	}
	else {
		cout << "�� �� ����, ������ ��...";
		return false; // ������((((
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
		cout << "������������ ������...";
		Sleep(1000);
		cout << "\n������ �������� ������ �������!";
		return true;
	}
	if (num == 2) {
		cout << "������������ ������...";
		Sleep(1000);
		cout << "\n������ �� ����� ������ �������!";
		return true;
	}
	if (num == 3) {
		cout << "������������ ��������� ������ ������������� QRcode...";
		Sleep(1000);
		cout << "\n��� ������������ QRcode: " << QRgeneration();
		return true;
	}
	return false;
}
void ChoosePaymentMethod() {
	bool flag;
	Menu menu;
	vector <string> PayList{"��������","�����","QR-code"};
	do
	{
		system("cls");
		cout << "\n\n�������� ����� ������:";
		int temp = menu.ChooseProduct(PayList);
		Oplata(temp);
		cout << '\n';
		system("pause");
		system("cls");
		cout << "\n\n\n�� �������� � ������� ������? ���� ���, �� ����� ����������� ��������";
	} while (!menu.YesOrNo());
}
