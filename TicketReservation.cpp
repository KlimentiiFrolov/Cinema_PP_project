﻿#include <iostream>
using namespace std;

//void Hall_preview(char** hall, int rows, int columns)
//{
//	for (int i = 0; i < rows; ++i) {
//		for (int j = 0; j < columns; ++j)
//		{
//			cout << hall[i][j] << ' ';
//		}
//		cout << endl;
//	}
//}

// Занят ли выбранный (chosenR) ряд
bool Row_is_full(char** const hall, int const chosenR, int const columns)
{
	for (int j = 0; j < columns; ++j)
	{
		if (hall[chosenR - 1][j] == '0') return 0; // !!!!!!!!!!!!! ЕСЛИ МЫ СВОБОДНЫЕ МЕСТА ОБОЗНАЧАЕМ НЕ '0', ТО МЕНЯТЬ УСЛОВИЕ
	}
	return 1;
}
// Занят ли зал
bool Hall_is_full(char** const hall, int const rows, int const columns)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			if (hall[i][j] == '0') return 0; // !!!!!!!!!!!!! ЕСЛИ МЫ СВОБОДНЫЕ МЕСТА ОБОЗНАЧАЕМ НЕ '0', ТО МЕНЯТЬ УСЛОВИЕ
		}
	}
	return 1;
}
// Бронирование билета
void Ticket_reservation(char** const hall, int const rows, int const columns) // Принимает ссылку на двумерный массив чаров, кол-во рядов, кол-во столбцов
																			  // В процессе работы изменяется двумерный массив
{
	if (!Hall_is_full(hall, rows, columns)) // Выполняется если в зале есть свободное место
	{
		string rst;
		do // Выполняется, пока хочет пользователь + пока в зале есть свободное место
		{
			// Hall_preview(hall, rows, columns); - советую выводить зал каждый раз, когда предоставляется выбор места
			int chosenR, chosenC;

			cout << "\nКакое место и на каком ряду вы хотите забронировать?\nВведите номер ряда >";
			cin >> chosenR;
			while (Row_is_full(hall, chosenR, columns)) // Пока выбран заполненный ряд
			{
				cout << "Все места в этом ряду уже заняты, выберите другой ряд >";
				cin >> chosenR;
			}

			cout << "Введите номер места >";
			cin >> chosenC;
			while (hall[chosenR - 1][chosenC - 1] != '0') // Пока выбрано занятое место   !!!!!!!!!!!!! ЕСЛИ МЫ СВОБОДНЫЕ МЕСТА ОБОЗНАЧАЕМ НЕ '0', ТО МЕНЯТЬ УСЛОВИЕ
			{
				cout << "Место под этим номером уже занято, выберите другое место >";
				cin >> chosenC;
			}

			hall[chosenR - 1][chosenC - 1] = 'Б'; // Я ставлю Б на места, которые забронированны. Возможно нужно сменить обозначение
			cout << "\nВы успешно забронировали место на ряду " << chosenR << " с номером " << chosenC;

			rst = "N";
			if (!Hall_is_full(hall, rows, columns)) // Повтор запрашивается только при наличии свободного места
			{
				cout << "\nХотите забронировать ещё одно место? (y/n) >";
				cin >> rst;
			}
			else
			{
				cout << "\nВ зале кончились свободные места для бронирвания!";
			}
		} while (rst == "Y" || rst == "y");
	}
	else
	{
		cout << "\nВ зале нет свободных мест для бронирования!";
	}
	return;
}