#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<Windows.h>
#include<time.h>
#include<conio.h>
//#include<fstream>
//#include <io.h>
//#include <stack>
//#include <cmath>
using namespace std;



class Menu {
    void ShowChooseFilm(vector<vector<string>> listFilms, int poz)
    {
        int countOfChooses = listFilms.size();

        for (size_t i = 0; i < countOfChooses; i++)
        {
            SetCursor(25, 8 + i);
            if (i == poz)
            {
                SetColor(LightBlue, Black);
            }
            else
            {
                SetColor(White, Black);
            }
            cout << listFilms[i][0] << '\n';
        }
        SetColor(White, Black);
    }
    void ShowChooseTicket(int poz)
    {
        const int countOfChooses = 3;
        char menuConsis[countOfChooses][100] = { "�������������", "������", "�����" };

        for (size_t i = 0; i < countOfChooses; i++)
        {
            SetCursor(25, 8 + i);
            if (i == poz)
            {
                SetColor(Magenta, Black);
            }
            else
            {
                SetColor(White, Black);
            }
            cout << menuConsis[i] << '\n';
        }
        SetColor(White, Black);
    }
    void ShowYesOrNo(int poz) {
        const int countOfChooses = 2;
        char menuConsis[countOfChooses][100] = { "��", "���" };

        for (size_t i = 0; i < countOfChooses; i++)
        {
            SetCursor(25, 8 + i);
            if (poz == i && poz == 0)
            {
                SetColor(LightBlue, Black);
            }
            else if (poz == i && poz == 1)
            {
                SetColor(Red, Black);
            }
            else
            {
                SetColor(White, Black);
            }
            cout << menuConsis[i] << '\n';
        }
        SetColor(White, Black);
    }
    void ShowChooseSize(int poz, int* cost, string* type) {
        const int countOfChooses = 3;

        for (size_t i = 0; i < countOfChooses; i++)
        {
            SetCursor(25, 8 + i);
            if (poz == i && poz == 0)
            {
                SetColor(LightCyan, Black);
            }
            else if (poz == i && poz == 1)
            {
                SetColor(LightBlue, Black);
            }
            else if (poz == i && poz == 2)
            {
                SetColor(Blue, Black);
            }
            else
            {
                SetColor(White, Black);
            }
            cout << i+1 << " - " << type[i] << " - " << cost[i] << '\n';
        }
        SetColor(White, Black);
    }
    void ShowChooseProduct(int poz, vector<string> produstList) {
        int countOfChooses = produstList.size();

        for (size_t i = 0; i < countOfChooses; i++)
        {
            SetCursor(25, 8 + i);
            if (poz == i)
            {
                SetColor(LightGreen, Black);
            }
            else
            {
                SetColor(White, Black);
            }
            cout << i + 1 << " - " << produstList[i] << '\n';
        }
        SetColor(White, Black);
    }
    void ShowChoosePlaceOnCinema(char** const hall, int const rows, int const columns, int pozX,int pozY) {
        int temp = 0;
        SetColor(White, Black);
        for (int j = 0; j < columns; j++) {
            SetCursor(24 + j+temp, 7);
            temp += 2;
            cout << '|' << j + 1 << '|';
        }
        for (size_t i = 0; i < rows; i++)
        {
            SetCursor(21, 8 + i);
            cout << '|' << i + 1 << '|';
        }
        for (size_t i = 0; i < rows; i++)
        {
            int shift = 0;
            for (size_t j = 0; j < columns; j++)
            {
                SetCursor(25 + j + shift, 8 + i);
                shift += 2;
                if (i == pozX && j == pozY && hall[i][j] == 'R')
                {
                    SetColor(Red, Black);
                }
                else if (i == pozX && j == pozY && hall[i][j] == '1') {
                    SetColor(Blue, Black);
                }
                
                else if (pozX == rows) {
                    SetColor(Cyan, Black);
                }
                else if (i == pozX && j == pozY) {
                    SetColor(LightGreen, Black);
                }
                else
                {
                    SetColor(White, Black);
                }
                cout << hall[i][j];
                SetCursor(25, 8 + columns + 3);
                cout << "���������";
            }

        }
        SetColor(White, Black);
    }
    void PrintCinemaFall(char** const hall, int const rows, int const columns) {
        int temp = 0;
        SetColor(White, Black);
        for (int j = 0; j < columns; j++) {
            SetCursor(19 + j + temp, 3);
            temp += 2;
            cout << '|' << j + 1 << '|';
        }
        for (size_t i = 0; i < rows; i++)
        {
            SetCursor(16, 4 + i);
            cout << '|' << i + 1 << '|';
        }
        for (size_t i = 0; i < rows; i++)
        {
            int shift = 0;
            for (size_t j = 0; j < columns; j++)
            {
                SetCursor(20 + j + shift, 4 + i);
                shift += 2;
                if (hall[i][j] == 'R')
                {
                    SetColor(Red, Black);
                }
                else if (hall[i][j] == '1') {
                    SetColor(Blue, Black);
                }
                else
                {
                    SetColor(White, Black);
                }
                cout << hall[i][j];
            }
        }
    }
public:
    enum Color {
        Black, Blue, Green, Cyan, Red,
        Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan,
        LightRed, LightMagenta, Yellow, White
    };
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    void SetColor(Color text, Color background)
    {
        SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
    }
    enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, esc = 27, space = 32 };
    void SetCursor(int x, int y)
    {
        COORD myCoords = { x,y };
        SetConsoleCursorPosition(hStdOut, myCoords);
    }
    int ChooseFilm(vector<vector<string>> listFilms)
    {
        int number = 0, key;
        int countOfChooses = listFilms.size();
        SetColor(LightGreen, Black);
        do
        {
            ShowChooseFilm(listFilms, number);
            key = _getch();//�������� ��� ������� �������
            ShowChooseFilm(listFilms, number);
            switch (key)
            {
            case Up:
                if (number == 0)number = countOfChooses - 1;
                else number--;
                break;
            case Down:
                if (number == countOfChooses - 1) number = 0;
                else number++;
                break;
            case Enter:
                break;
            }
        } while (key != Enter);
        SetColor(White, Black);
        system("cls");
        return number + 1;
    }
    char ChooseTicket()
    {
        int number = 0, key;
        const int countOfChooses = 3;
        do
        {
            ShowChooseTicket(number);
            key = _getch();//�������� ��� ������� �������
            ShowChooseTicket(number);
            switch (key)
            {
            case Up:
                if (number == 0)number = countOfChooses - 1;
                else number--;
                break;
            case Down:
                if (number == countOfChooses - 1) number = 0;
                else number++;
                break;
            case Enter:
                break;
            }
        } while (key != Enter);
        SetColor(White, Black);
        switch (number)
        {
        case 0:
            system("cls");
            SetCursor(25, 8);
            return 'R';
            break;
        case 1:
            system("cls");
            SetCursor(25, 8);
            return 'P';
            break;
        case 2:
            system("cls");
            SetCursor(25, 8);
            return 'B';
            break;
        }
    }
    bool YesOrNo() {
        int number = 0, key;
        const int countOfChooses = 2;
        SetColor(LightGreen, Black);
        SetCursor(25, 6);
        do
        {
            ShowYesOrNo(number);
            key = _getch();//�������� ��� ������� �������
            ShowYesOrNo(number);
            switch (key)
            {
            case Up:
                if (number == 0)number = countOfChooses - 1;
                else number--;
                break;
            case Down:
                if (number == countOfChooses - 1) number = 0;
                else number++;
                break;
            case Enter:
                break;
            }
        } while (key != Enter);
        system("cls");
        SetColor(White, Black);
        return (number == 0) ? true : false;
    }
    int ChooseSize(int* cost, string* type) {
        int number = 0, key;
        const int countOfChooses = 3;
        do
        {
            ShowChooseSize(number, cost, type);
            key = _getch();//�������� ��� ������� �������
            ShowChooseSize(number, cost, type);
            switch (key)
            {
            case Up:
                if (number == 0)number = countOfChooses - 1;
                else number--;
                break;
            case Down:
                if (number == countOfChooses - 1) number = 0;
                else number++;
                break;
            case Enter:
                break;
            }
        } while (key != Enter);
        SetColor(White, Black);
        return number + 1;
    }
    int ChooseProduct(vector<string> produstList) {
        int number = 0, key;
        const int countOfChooses = produstList.size();
        do
        {
            ShowChooseProduct(number, produstList);
            key = _getch();//�������� ��� ������� �������
            ShowChooseProduct(number, produstList);
            switch (key)
            {
            case Up:
                if (number == 0)number = countOfChooses - 1;
                else number--;
                break;
            case Down:
                if (number == countOfChooses - 1) number = 0;
                else number++;
                break;
            case Enter:
                break;
            }
        } while (key != Enter);
        SetColor(White, Black);
        return number + 1;
    }
    void ChoosePlaceOnCinema(char** const hall, int const rows, int const columns, bool const reservation, int X=0, int Y=0) {
        int numberX = X, numberY = Y, key;
        const int countOfChoosesX = rows;
        const int countOfChoosesY = columns;
        SetColor(LightGreen, Black);
        do
        {
            ShowChoosePlaceOnCinema(hall, rows, columns, numberX, numberY);
            key = _getch();//�������� ��� ������� �������
            ShowChoosePlaceOnCinema(hall, rows, columns, numberX, numberY);
            switch (key)
            {
            case Up:
                if (numberX == 0) numberX = countOfChoosesX - 1;
                else numberX--;
                break;
            case Down:
                if (numberX == countOfChoosesX) numberX = 0;
                else numberX++;
                break;
            case Left:
                if (numberY == 0) numberY = countOfChoosesY - 1;
                else numberY--;
                break;
            case Right:
                if (numberY == countOfChoosesY - 1) numberY = 0;
                else numberY++;
                break;
            case Enter:
                break;
            }
        } while (key != Enter);
        if (numberX == rows) {
            system("cls");
            cout << "\n\t";
            PrintCinemaFall(hall, rows, columns);
            cout << "\n�� ������� � ������?";
            bool flag = YesOrNo();
            if (!flag) {
                //return true;
                ChoosePlaceOnCinema(hall, rows, columns, reservation);
            }
        }
        else if (hall[numberX][numberY] == '0' && reservation)
        {
            hall[numberX][numberY] = 'R';
            ChoosePlaceOnCinema(hall, rows, columns, reservation, numberX, numberY);
        }
        else if (hall[numberX][numberY] == '0' && !reservation) {
            hall[numberX][numberY] = '1';
            ChoosePlaceOnCinema(hall, rows, columns, reservation, numberX, numberY);
        }
        else {
            hall[numberX][numberY] = '0';
            ChoosePlaceOnCinema(hall, rows, columns, reservation, numberX, numberY);
        }
        SetColor(White, Black);
        system("cls");
        //return false;
    }
};