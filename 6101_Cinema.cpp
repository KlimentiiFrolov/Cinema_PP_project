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
//��� ���� ����������.
#include "includes.h"
// ���������� ��� �������� �����.
#include "validInput.h"
//����
#include "menu.h"
#include "film_hall.h"
#include "saveload.h"

using namespace std;
void view_movie_schedules();
// ����� ������ ������.
bool ChoosePaymentMethod(bool);
// �������, ��� � ����������� ���������� ������� ������, ����� ����������� ���������� ������.
bool Oplata(int);
// ��������� QR-����.
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
		cout << "\n\n\n\n������ ����������?";
	} while (menu.YesOrNo());
}
void view_movie_schedules() {
	Menu menu(ROWS, COLS);
	int choice_movie; //������������� ���������� ��� ������ ������ � ��� ������ ������
	cout << "\n������ ��������� �� 01 ������: \n\n";
	for (size_t i = 0; i < listFilms.size(); ++i) {
		cout << i + 1 << ") " << listFilms[i].name << endl;
	}
	cout << endl;
	cout << "�������� �����: ";
	choice_movie = menu.ChooseFilm(listFilms);
	Film& chosen_film = listFilms[choice_movie - 1];
	cout << chosen_film.desc << endl;
	system("pause");
	system("cls");
	menu.SetCursor(24, 6);
	cout << "\n�������� �����: ";
	Hall& hall = chosen_film.halls[menu.ChooseHall(chosen_film.halls) - 1];
	system("cls");
	menu.SetCursor(24, 6);
	cout << "\n������ �������������, ������ ��� ��������� �����?";
	int choose = menu.ChooseTicket();
	system("cls");
	int TicketBills;
	string output;
	bool PayGoOn = true;
	bool back = false;
	switch (choose) { // ������� � ������ ��������.
	case(1):
		cout << "\n\n\n\n\n\n\t\t\t�������� �����(�) ��� ������������:" << endl;
		back = menu.ChoosePlaceOnCinema(hall.data, hall.rows, hall.cols, true);
		//����������� ����� �� ������
		system("cls");
		//���� �� ������������ ����� � ����
		if (!back) {
			TicketBills = menu.Bills(TicketCost);
			output = to_string(TicketBills / TicketCost) + " x " + " ����� �� �����: " + \
				to_string(TicketBills / TicketCost) + " x " + to_string(TicketCost) + " = " + \
				to_string(TicketBills) + " ������\n";
			cout << output;
			system("pause");
			back = ChoosePaymentMethod(PayGoOn);
			if (back) {
				view_movie_schedules();
			}
			PayGoOn = movie_merchandaise();
			back = ChoosePaymentMethod(PayGoOn);
			if (back) {
				view_movie_schedules();
			}
		}
		else {
			view_movie_schedules();
		}
		break;
	case(2):
		cout << "\n\n\n\n\n\n\t\t\t�������� �����(�) ��� �������:" << endl;
		back = menu.ChoosePlaceOnCinema(hall.data, hall.rows, hall.cols, false);
		//����������� ����� �� ������
		system("cls");
		if (!back) {
			TicketBills = menu.Bills(TicketCost);
			output = to_string(TicketBills / TicketCost) + " x " + " ����� �� �����: " + \
				to_string(TicketBills / TicketCost) + " x " + to_string(TicketCost) + " = " + \
				to_string(TicketBills) + " ������\n";
			cout << output;
			system("pause");
			back = ChoosePaymentMethod(PayGoOn);
			if (back) {
				view_movie_schedules();
			}
			PayGoOn = movie_merchandaise();
			back = ChoosePaymentMethod(PayGoOn);
			if (back) {
				view_movie_schedules();
			}
		}
		else {
			view_movie_schedules();
		}
		break;
	default:
		view_movie_schedules();
		break;
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
		cout << "������������ ������...";
		Sleep(1000);
		cout << "\n������ �������� ������ �������!";
		return false;
	}
	if (num == 2) {
		cout << "������������ ������...";
		Sleep(1000);
		cout << "\n������ �� ����� ������ �������!";
		return false;
	}
	if (num == 3) {
		cout << "������������ ��������� ������ ������������� QRcode...";
		Sleep(1000);
		cout << "\n��� ������������ QRcode: ";
		QRgeneration();
		return false;
	}
	return true;
}
bool ChoosePaymentMethod(bool letsPay = true) {
	bool flag = false;
	if (letsPay) {
		Menu menu;
		vector <string> PayList{"��������", "�����", "QR-code", "��������� � ����� ������"};
		do
		{
			system("cls");
			cout << "\n\n�������� ����� ������:";
			int temp = menu.ChooseProduct(PayList);
			flag = Oplata(temp);
			cout << '\n';
			system("pause");
			system("cls");
			if (!flag) {
				cout << "\n\n\n�� �������� � ������� ������? ���� ���, �� ����� ����������� ��������";
			}
		} while (!flag && !menu.YesOrNo());
	}
	return flag;
}
