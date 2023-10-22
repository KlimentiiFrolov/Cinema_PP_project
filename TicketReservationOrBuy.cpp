#include <iostream>
#include "includes.h"
#include "validInput.h"
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

// Занят ли выбранный (chosenR) ряд.
bool Row_is_full(char** const hall, int const chosenR, int const columns) {
	for (int j = 0; j < columns; ++j) {
		if (hall[chosenR - 1][j] == '0') return false; // !!!!!!!!!!!!! ЕСЛИ МЫ СВОБОДНЫЕ МЕСТА ОБОЗНАЧАЕМ НЕ '0', ТО МЕНЯТЬ УСЛОВИЕ.
	}
	return true;
}
// Занят ли зал.
bool Hall_is_full(char** const hall, int const rows, int const columns) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			if (hall[i][j] == '0') return false; // !!!!!!!!!!!!! ЕСЛИ МЫ СВОБОДНЫЕ МЕСТА ОБОЗНАЧАЕМ НЕ '0', ТО МЕНЯТЬ УСЛОВИЕ.
		}
	}
	return true;
}
/* Бронирование или покупка билета.
 * Принимает ссылку на двумерный массив чаров, кол-во рядов, кол-во столбцов.
 * В процессе работы изменяется двумерный массив. */
void Ticket_reservation_or_buy(char** const hall, int const rows, int const columns, bool const reservation) {
	if (!Hall_is_full(hall, rows, columns)) { // Выполняется если в зале есть свободное место.
		char rst;
		do { // Выполняется, пока хочет пользователь + пока в зале есть свободное место.
			// Hall_preview(hall, rows, columns); - советую выводить зал каждый раз, когда предоставляется выбор места.
			int chosenR, chosenC;
            if (reservation) {
                cout << "\nКакое место и на каком ряду вы хотите забронировать?" << endl;
            }
            else {
                cout << "\nКакое место и на каком ряду вы хотите купить?" << endl;
            }
            chosenR = get_input<int>("Введите номер ряда >");
            while (!(1 <= chosenR && chosenR <= rows)) {
                chosenR = get_input<int>("Вы ввели неверный ряд, введите ещё раз >");
            }
			while (Row_is_full(hall, chosenR, columns)) { // Пока выбран заполненный ряд.
                chosenR = get_input<int>("Все места в этом ряду уже заняты, выберите другой ряд >");
			}

			chosenC = get_input<int>("Введите номер места >");
            while (!(1 <= chosenC && chosenC <= columns)) {
                chosenC = get_input<int>("Вы ввели неверное место, введите ещё раз >");
            }
			while (hall[chosenR - 1][chosenC - 1] != '0') { // Пока выбрано занятое место !!!!!!!!!!!!! ЕСЛИ МЫ СВОБОДНЫЕ МЕСТА ОБОЗНАЧАЕМ НЕ '0', ТО МЕНЯТЬ УСЛОВИЕ.
                chosenC = get_input<int>("Место под этим номером уже занято, выберите другое место >");
			}

             // Я ставлю R на места, которые забронированы. Возможно нужно сменить обозначение.
            if (reservation) {
                hall[chosenR - 1][chosenC - 1] = 'R';
                cout << "\nВы успешно забронировали место на ряду " << chosenR << " с номером " << chosenC << endl;
            }
            else {
                hall[chosenR - 1][chosenC - 1] = '1';
                cout << "\nВы успешно купили место на ряду " << chosenR << " с номером " << chosenC << endl;
            }
            show_cinema(hall, rows, columns);
			if (!Hall_is_full(hall, rows, columns)) { // Повтор запрашивается только при наличии свободного места.
                if (reservation) {
                    rst = get_input<char>("\nХотите забронировать ещё одно место? (y/n) >");
                }
                else {
                    rst = get_input<char>("\nХотите купить ещё одно место? (y/n) >");
                }
                while (!(rst == 'n' || rst == 'N' || rst == 'y' || rst == 'Y')) {
                    rst = get_input<char>("Некорректный ввод! Попробуйте ещё раз!");
                }
			}
			else {
                if (reservation) {
                    cout << "\nВ зале кончились свободные места для бронирования!";
                }
                else {
                    cout << "\nВ зале кончились свободные места для покупки!";
                }
			}
		} while (rst == 'Y' || rst == 'y');
	}
	else {
        if (reservation) {
            cout << "\nВ зале нет свободных мест для бронирования!";
        }
        else {
            cout << "\nВ зале нет свободных мест для покупки!";
        }
	}
}