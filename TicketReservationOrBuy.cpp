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

// ����� �� ��������� (chosenR) ���.
bool Row_is_full(char** const hall, int const chosenR, int const columns) {
    for (int j = 0; j < columns; ++j) {
        if (hall[chosenR - 1][j] == '0') return false; // !!!!!!!!!!!!! ���� �� ��������� ����� ���������� �� '0', �� ������ �������.
    }
    return true;
}
// ����� �� ���.
bool Hall_is_full(char** const hall, int const rows, int const columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (hall[i][j] == '0') return false; // !!!!!!!!!!!!! ���� �� ��������� ����� ���������� �� '0', �� ������ �������.
        }
    }
    return true;
}
/* ������������ ��� ������� ������.
 * ��������� ������ �� ��������� ������ �����, ���-�� �����, ���-�� ��������.
 * � �������� ������ ���������� ��������� ������. */
void Ticket_reservation_or_buy(char** const hall, int const rows, int const columns, bool const reservation) {
    if (!Hall_is_full(hall, rows, columns)) { // ����������� ���� � ���� ���� ��������� �����.
        char rst;
        do { // �����������, ���� ����� ������������ + ���� � ���� ���� ��������� �����.
            // Hall_preview(hall, rows, columns); - ������� �������� ��� ������ ���, ����� ��������������� ����� �����.
            int chosenR, chosenC;
            if (reservation) {
                cout << "\n����� ����� � �� ����� ���� �� ������ �������������?" << endl;
            }
            else {
                cout << "\n����� ����� � �� ����� ���� �� ������ ������?" << endl;
            }
            chosenR = get_input<int>("������� ����� ���� >");
            while (!(1 <= chosenR && chosenR <= rows)) {
                chosenR = get_input<int>("�� ����� �������� ���, ������� ��� ��� >");
            }
            while (Row_is_full(hall, chosenR, columns)) { // ���� ������ ����������� ���.
                chosenR = get_input<int>("��� ����� � ���� ���� ��� ������, �������� ������ ��� >");
            }

            chosenC = get_input<int>("������� ����� ����� >");
            while (!(1 <= chosenC && chosenC <= columns)) {
                chosenC = get_input<int>("�� ����� �������� �����, ������� ��� ��� >");
            }
            while (hall[chosenR - 1][chosenC - 1] != '0') { // ���� ������� ������� ����� !!!!!!!!!!!!! ���� �� ��������� ����� ���������� �� '0', �� ������ �������.
                chosenC = get_input<int>("����� ��� ���� ������� ��� ������, �������� ������ ����� >");
            }

            // � ������ R �� �����, ������� �������������. �������� ����� ������� �����������.
            if (reservation) {
                hall[chosenR - 1][chosenC - 1] = 'R';
                cout << "\n�� ������� ������������� ����� �� ���� " << chosenR << " � ������� " << chosenC << endl;
            }
            else {
                hall[chosenR - 1][chosenC - 1] = '1';
                cout << "\n�� ������� ������ ����� �� ���� " << chosenR << " � ������� " << chosenC << endl;
            }
            show_cinema(hall, rows, columns);
            if (!Hall_is_full(hall, rows, columns)) { // ������ ������������� ������ ��� ������� ���������� �����.
                if (reservation) {
                    rst = get_input<char>("\n������ ������������� ��� ���� �����? (y/n) >");
                }
                else {
                    rst = get_input<char>("\n������ ������ ��� ���� �����? (y/n) >");
                }
                while (!(rst == 'n' || rst == 'N' || rst == 'y' || rst == 'Y')) {
                    rst = get_input<char>("������������ ����! ���������� ��� ���!");
                }
            }
            else {
                if (reservation) {
                    cout << "\n� ���� ��������� ��������� ����� ��� ������������!";
                }
                else {
                    cout << "\n� ���� ��������� ��������� ����� ��� �������!";
                }
            }
        } while (rst == 'Y' || rst == 'y');
    }
    else {
        if (reservation) {
            cout << "\n� ���� ��� ��������� ���� ��� ������������!";
        }
        else {
            cout << "\n� ���� ��� ��������� ���� ��� �������!";
        }
    }
}