#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include "film_hall.h"

//#include<fstream>
//#include <io.h>
//#include <stack>
//#include <cmath>
using namespace std;

class Menu {
    void ShowChooseHall(const vector<Hall>& listHall, int poz) const
    {
        //Функция вывода залов
        // listHall: двумерный вектор с информацией о залах
        // poz: индекс выбранного зала

        // Получаем количество элементов в списке залов
        int countOfChooses = listHall.size();
        int shift = 0;
        // Проходимся по всем фильмам в списке
        for (size_t i = 0; i < countOfChooses; i++)
        {
            // Устанавливаем позицию курсора для вывода
            SetCursor(25, 8 + i + shift);
            if (poz == i)
            {
                // Устанавливаем цвет текста в зависимости от выбранного зала
                SetColor(LightGreen, Black);
            }
            else
            {
                SetColor(White, Black);
            }
            SetCursor(22, 7 + i + shift);
            //Вывод времени сеанса 
            if (!(listHall[i].time % 60 >= 0 && 9 <= listHall[i].time % 60)) {
                cout << i + 1 << ")" << listHall[i].time/60 << ":0" << listHall[i].time % 60;
            }
            else {
                cout << i + 1 << ")" << listHall[i].time / 60 << ":" << listHall[i].time % 60;
            }
            //Вывод зала
            for (int j = 0; j < listHall[i].rows; j++)
            {
                for (int q = 0; q < listHall[i].cols; q++)
                {
                    SetCursor(25+q, 8 + i + j + shift);
                    cout << listHall[i].data[j][q] << ' ';
                }
                cout << "\n";
            }
            shift += 4;
        }
        //Сброс цвета консоли
        SetColor(White, Black);
    }
    void ShowChooseFilm(const vector<Film>& listFilms, int poz) const
    {
        // Функция для отображения выбора фильма из списка
        // listFilms: двумерный вектор с информацией о фильмах
        // poz: индекс выбранного фильма

        // Получаем количество элементов в списке фильмов
        int countOfChooses = listFilms.size();

        // Проходимся по всем фильмам в списке
        for (size_t i = 0; i < countOfChooses; i++)
        {
            // Устанавливаем позицию курсора для вывода
            SetCursor(25, 8 + i);

            // Устанавливаем цвет текста в зависимости от выбранного фильма
            if (i == poz)
            {
                SetColor(LightBlue, Black);
            }
            else
            {
                SetColor(White, Black);
            }
            // Выводим название фильма
            cout << listFilms[i].name << '\n';
        }
        // Возвращаем стандартный цвет текста
        SetColor(White, Black);
    }
    void ShowChooseTicket(int poz) const
    {
        // Функция для отображения выбора билета
        // poz: индекс выбранного билета

        // Определяем количество вариантов выбора билета
        const int countOfChooses = 3;
        // Массив строк для хранения вариантов выбора
        char menuConsis[countOfChooses][100] = { "Забронировать", "Купить", "Назад" };
        // Проходимся по всем вариантам выбора
        for (size_t i = 0; i < countOfChooses; i++)
        {
            // Устанавливаем позицию курсора для вывода
            SetCursor(25, 8 + i);
            // Устанавливаем цвет текста в зависимости от выбранного варианта
            if (i == poz)
            {
                SetColor(Magenta, Black);
            }
            else
            {
                SetColor(White, Black);
            }
            // Выводим текст варианта выбора
            cout << menuConsis[i] << '\n';
        }
        // Возвращаем стандартный цвет текста
        SetColor(White, Black);
    }
    void ShowYesOrNo(int poz) const {
        // Функция для отображения выбора "Да" или "Нет"
        // poz: индекс выбранного варианта (0 - Да, 1 - Нет)

        // Определяем количество вариантов выбора
        const int countOfChooses = 2;
        // Массив строк для хранения вариантов выбора
        char menuConsis[countOfChooses][100] = { "Да", "Нет" };
        // Проходимся по всем вариантам выбора
        for (size_t i = 0; i < countOfChooses; i++)
        {
            // Устанавливаем позицию курсора для вывода
            SetCursor(25, 8 + i);
            // Устанавливаем цвет текста в зависимости от выбора
            if (poz == i && poz == 0)
            {
                // Если выбран вариант "Да", устанавливаем голубой цвет
                SetColor(LightBlue, Black);
            }
            else if (poz == i && poz == 1)
            {
                // Если выбран вариант "Нет", устанавливаем красный цвет
                SetColor(Red, Black);
            }
            else
            {
                // В противном случае устанавливаем белый цвет
                SetColor(White, Black);
            }
            // Выводим текст варианта выбора
            cout << menuConsis[i] << '\n';
        }
        // Устанавливаем стандартный цвет текста
        SetColor(White, Black);
    }
    void ShowChooseSize(int poz, int* cost, string* type) const {
        // Функция для отображения вариантов выбора размера товаров и их стоимости
        // poz: индекс выбранного варианта
        // cost: указатель на массив стоимостей для каждого варианта
        // type: указатель на массив строк с описанием каждого варианта

        // Определяем количество вариантов выбора
        const int countOfChooses = 3;

        // Проходимся по всем вариантам выбора
        for (size_t i = 0; i < countOfChooses; i++)
        {
            // Устанавливаем позицию курсора для вывода
            SetCursor(25, 8 + i);
            // Устанавливаем цвет текста в зависимости от выбора
            if (poz == i && poz == 0)
            {
                // Если выбран первый вариант, устанавливаем светло-голубой цвет
                SetColor(LightCyan, Black);
            }
            else if (poz == i && poz == 1)
            {
                // Если выбран второй вариант, устанавливаем голубой цвет
                SetColor(LightBlue, Black);
            }
            else if (poz == i && poz == 2)
            {
                // Если выбран третий вариант, устанавливаем синий цвет
                SetColor(Blue, Black);
            }
            else
            {
                // В противном случае устанавливаем белый цвет
                SetColor(White, Black);
            }
            // Выводим текст варианта выбора, его порядковый номер и стоимость
            cout << i + 1 << " - " << type[i] << " - " << cost[i] << '\n';
        }
        // Устанавливаем стандартный цвет текста
        SetColor(White, Black);
    }
    void ShowChooseProduct(int poz, vector<string> productList) const {
        // Функция для отображения вариантов выбора продукта
        // poz: индекс выбранного варианта
        // productList: вектор строк с описанием каждого варианта продукта

        // Определяем количество вариантов выбора
        int countOfChooses = productList.size();

        // Проходимся по всем вариантам выбора
        for (size_t i = 0; i < countOfChooses; i++)
        {
            // Устанавливаем позицию курсора для вывода
            SetCursor(25, 8 + i);
            // Устанавливаем цвет текста в зависимости от выбора
            if (poz == i)
            {
                // Если выбран текущий вариант, устанавливаем светло-зеленый цвет
                SetColor(LightGreen, Black);
            }
            else
            {
                // В противном случае устанавливаем белый цвет
                SetColor(White, Black);
            }
            // Выводим текст варианта выбора и его порядковый номер
            cout << i + 1 << " - " << productList[i] << '\n';
        }
        // Устанавливаем стандартный цвет текста
        SetColor(White, Black);
    }
    void ShowChoosePlaceOnCinema(char** const hall, int const rows, int const columns, int pozX, int pozY) const {
        // Функция для отображения зала кинотеатра и выбора места
         // hall: двумерный массив, представляющий схему зала
         // rows: количество рядов в зале
         // columns: количество мест в каждом ряду
         // pozX, pozY: координаты выбранного места

         // Инициализация временной переменной
        int temp = 0;
        // Установка цвета текста на белый и фонового цвета на черный
        SetColor(White, Black);
        // Отображение номеров мест в верхней части зала
        for (int j = 0; j < columns; j++) {
            SetCursor(24 + j + temp, 7);
            temp += 2;
            cout << '|' << j + 1 << '|';
        }
        // Отображение номеров рядов по левой стороне зала
        for (size_t i = 0; i < rows; i++)
        {
            SetCursor(21, 8 + i);
            cout << '|' << i + 1 << '|';
        }
        // Отображение мест в зале и выделение выбранного места определенным цветом
        for (size_t i = 0; i <= rows+1; i++)
        {
            int shift = 0;
            for (size_t j = 0; j < columns; j++)
            {
                SetCursor(25 + j + shift, 8 + i);
                shift += 2;
                // Проверка и установление цвета для выбранного места
                if (i < rows && i == pozX && j == pozY && hall[i][j] == 'R')
                {
                    // Устанавливаем красный цвет для выбранного места, если оно забронировано
                    SetColor(Red, Black);
                }
                else if (i < rows && i == pozX && j == pozY && hall[i][j] == '1') {
                    // Устанавливаем синий цвет для выбранного места, если оно свободно
                    SetColor(Blue, Black);
                }
                else if (i == rows && i == pozX) {
                    // Устанавливаем циановый при выборе "сохранить"
                    SetColor(Cyan, Black);
                }
                else if (i == rows + 1 && i == pozX)
                {
                    // Устанавливаем красный при выборе "Вернуться в самое начало"
                    SetColor(Red, Black);
                }
                else if (i == pozX && j == pozY) {
                    //Устанавливаем светло-зелёный при выборе свободного места
                    SetColor(LightGreen, Black);
                }
                else
                {
                    //Для не выбранных элементов устанавливаем белый цвет
                    SetColor(White, Black);
                }
                // Вывод символа, представляющего место
                if (i < rows) {
                    cout << hall[i][j];
                }
                //Текст кнопки "сохранить"
                else if (i == rows) {
                    SetCursor(25, 8 + columns + 3);
                    cout << "Сохранить";
                }
                //Текст кнопки "Вернуться в самое начало"
                else if (i == rows + 1) {
                    SetCursor(25, 8 + columns + 4);
                    cout << "Вернуться в самое начало";
                }

            }

        }
        // Установка цвета текста на белый и фонового цвета на черный
        SetColor(White, Black);
    }
    void PrintCinemaHall(char** const hall, int const rows, int const columns) const {
        // Функция для печати кинозала, представленный в виде двумерного массива символов.
        // Принимает указатель на массив указателей на символы hall, а также целочисленные значения rows и columns.
        // Создается переменная temp, которая будет использоваться для создания дополнительного сдвига при печати номеров столбцов.
        int temp = 0;
        // Устанавливается белый цвет для стандартного вывода.
        SetColor(White, Black);
        // Цикл для печати номеров столбцов с дополнительным сдвигом temp для каждого столбца.
        for (int j = 0; j < columns; j++) {
            SetCursor(19 + j + temp, 3);
            temp += 2;
            cout << '|' << j + 1 << '|';
        }
        // Печать номеров строк.
        for (size_t i = 0; i < rows; i++)
        {
            SetCursor(16, 4 + i);
            cout << '|' << i + 1 << '|';
        }
        // Двойной цикл для печати зала кинотеатра. Устанавливает цвет в зависимости от значения в массиве и печатает соответствующий символ.
        for (size_t i = 0; i < rows; i++)
        {
            int shift = 0;
            for (size_t j = 0; j < columns; j++)
            {
                SetCursor(20 + j + shift, 4 + i);
                shift += 2;
                if (hall[i][j] == 'R')
                {
                    // Устанавливаем красный цвет для выбранного места, если оно забронировано
                    SetColor(Red, Black);
                }
                else if (hall[i][j] == '1') {
                    // Устанавливаем синий цвет для выбранного места, если оно свободно
                    SetColor(Blue, Black);
                }
                else
                {
                    // В противном случае устанавливаем белый цвет
                    SetColor(White, Black);
                }
                cout << hall[i][j];
            }
        }
    }
    //Имитация зала для покупки билетов
    int** ChoosePlaces;
    int rows;
    int columns;
public:
    // Enumeration Color для представления различных цветов 
    enum Color {
        Black, Blue, Green, Cyan, Red,
        Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan,
        LightRed, LightMagenta, Yellow, White
    };
    // Получаем дескриптор стандартного вывода консоли.
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    // Функция SetColor принимает два параметра: text (цвет текста) и background (цвет фона).
    // С использованием дескриптора стандартного вывода консоли (hStdOut) она устанавливает атрибуты текста
    // С помощью функции SetConsoleTextAttribute. Это позволяет изменять цвет текста и фона в консоли.
    void SetColor(Color text, Color background) const
    {
        SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
    }
    // Перечисление Direction определяет символьные константы для различных клавиш управления, таких как стрелки (Up, Left, Right, Down),
    // клавиша "Enter" (Enter), клавиша "Esc" (esc) и клавиша "Space" (space). Эти константы используются для обозначения направлений
    // и действий в программе, например, при обработке ввода пользователя для перемещения по интерфейсу или выполнения определенных операций.
    enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, esc = 27, space = 32 };
    // Функция SetCursor(int x, int y) устанавливает позицию курсора в консоли на указанные координаты (x, y).
    // Для этого создается структура COORD с соответствующими x и y, затем используется функция
    // SetConsoleCursorPosition для установки позиции курсора в консоли. Эта функция может быть
    // использована в графическом интерфейсе приложения для перемещения курсора или указания
    // места вывода информации на экране.
    void SetCursor(int x, int y) const
    {
        COORD myCoords = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
        SetConsoleCursorPosition(hStdOut, myCoords);
    }
    // Функция, позволяющая пользователю выбрать фильм из списка фильмов
    // Входные данные: listFilms — двумерный вектор, содержащий фильмы
    // Вывод: возвращает индекс выбранного фильма (индекс отсчитывается от 1)
    int ChooseFilm(const vector<Film>& listFilms)
    {
        // Инициализируем переменные для выбранного номера фильма и клавиши пользовательского ввода
        int number = 0, key;
        // Получаем общее количество фильмов в списке
        int countOfChooses = listFilms.size();
        // Устанавливаем цвет текста консоли на светло-зеленый на черном
        SetColor(LightGreen, Black);
        // Повторяем следующий блок кода, пока не будет нажата клавиша Enter
        do
        {
            // Отображение списка фильмов с выделенным текущим выбором
            ShowChooseFilm(listFilms, number);
            // Получаем код нажатой клавиши, не выводя его на экран
            key = _getch();
            // Перерисовываем список, чтобы удалить выделение из предыдущего выбора
            ShowChooseFilm(listFilms, number);
            // Обрабатываем клавишу, нажатую пользователем
            switch (key)
            {
            case Up:
                // Перемещаем выделение вверх, перенося его вниз, если оно находится вверху
                if (number == 0)number = countOfChooses - 1;
                else number--;
                break;
            case Down:
                // Перемещаем выделение вниз, перемещаясь вверх, если оно находится внизу
                if (number == countOfChooses - 1) number = 0;
                else number++;
                break;
            case Enter:
                // Выход из цикла при нажатии клавиши Enter
                break;
            }
        } while (key != Enter);
        // Сбрасываем цвет текста консоли по умолчанию и очищаем экран
        SetColor(White, Black);
        system("cls");
        // Возвращаем индекс выбранного фильма, отсчитываемый от 1
        return number + 1;
    }
    // ChooseTicket позволяет пользователю выбирать тип билета, перемещаясь по меню с помощью клавиш со стрелками.
    int ChooseTicket() {
        // Функция инициализирует переменную number для отслеживания выбора пользователя.
        int number = 0, key;
        // countOfChooses представляет общее количество доступных вариантов.
        const int countOfChooses = 3;
        // Функция входит в цикл do-while для многократного отображения меню и ожидания ввода пользователя до тех пор, пока не будет нажата клавиша Enter.
        do {
            // Внутри цикла вызывается функция ShowChooseTicket для отображения текущего состояния меню.
            ShowChooseTicket(number);
            // Получаем код нажатой клавиши, не выводя его на экран
            key = _getch();
            ShowChooseTicket(number);
            // Нажатие клавиш со стрелками (вверх и вниз) обновляет переменную number для навигации по вариантам.
            switch (key) {
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
            // При нажатии клавиши Enter цикл завершается.
        } while (key != Enter);
        // Сбрасываем цвет текста консоли по умолчанию
        SetColor(White, Black);
        system("cls");
        SetCursor(25, 8);
        return number + 1;
    }
    //  YesOrNo позволяет пользователю выбирать между вариантами «Да» и «Нет», перемещаясь по меню с помощью клавиш со стрелками.
    bool YesOrNo() {
        // Функция инициализирует переменную `number` для отслеживания выбора пользователя.
        int number = 0, key;
        // countOfChooses представляет общее количество доступных вариантов выбора, равное 2 для «Да» и «Нет».
        const int countOfChooses = 2;
        // Функция устанавливает цвет текста на светло-зеленый на черном фоне и позиционирует курсор в координатах (25, 6).
        SetColor(LightGreen, Black);
        SetCursor(25, 6);
        // Цикл do - while для многократного отображения меню и ожидания ввода пользователя до тех пор, пока не будет нажата клавиша Enter.
        do
        {
            // Внутри цикла вызывается функция Show YesOrNo для отображения текущего состояния меню.
            ShowYesOrNo(number);
            // Получаем код нажатой клавиши, не выводя его на экран
            key = _getch();
            ShowYesOrNo(number);
            // Нажатие клавиш со стрелками (вверх и вниз) обновляет переменную `number` для навигации по вариантам.
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
                // При нажатии клавиши Enter цикл завершается.
                break;
            }
        } while (key != Enter);
        // Экран очищается с помощью `system("cls")`, а цвет текста устанавливается на белый на чёрном фоне с помощью `SetColor`.
        system("cls");
        SetColor(White, Black);
        // Функция возвращает логическое значение: `true`, если пользователь выбрал "Да" (число 0) и `false`, если пользователь выбрал "Нет" (число 1).
        return (number == 0);
    }
    // ChooseSize позволяет пользователю выбирать размер из меню, где каждому размеру соответствует стоимость и тип.
    // Функция получает два массива: cost (представляющий стоимость, связанную с каждым размером) и type (представляющий тип, связанный с каждым размером).
    int ChooseSize(int* cost, string* type) {
        // Функция инициализирует переменную `number` для отслеживания выбора пользователя.
        int number = 0, key;
        // countOfChooses представляет общее количество доступных вариантов.
        const int countOfChooses = 3;
        // Цикл do - while для многократного отображения меню и ожидания ввода пользователя до тех пор, пока не будет нажата клавиша Enter.
        do
        {
            // Внутри цикла вызывается функция ShowChooseSize для отображения текущего состояния меню вместе со связанной стоимостью и типом.
            ShowChooseSize(number, cost, type);
            // Получаем код нажатой клавиши, не выводя его на экран
            key = _getch();
            ShowChooseSize(number, cost, type);
            // Нажатие клавиш со стрелками (вверх и вниз) обновляет переменную `number` для навигации по вариантам.
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
                // При нажатии клавиши Enter цикл завершается.
                break;
            }
        } while (key != Enter);
        // Цвет текста устанавливается на белый на черном фоне с помощью SetColor.
        SetColor(White, Black);
        // Функция возвращает выбранное число размера, добавляя 1 к переменной `number`.
        return number + 1;
    }
    // ChooseProduct позволяет пользователю выбирать товар из списка с помощью клавиш со стрелками.
    // Функция принимает вектор строк `productList`, представляющий доступные варианты продукта.
    int ChooseProduct(const vector<string>& productList) {
        // Функция инициализирует переменную number для отслеживания выбора пользователя и key для хранения нажатого кода клавиши.
        int number = 0, key;
        // countOfChooses установлен на размер списка продуктов, представляющий общее количество доступных вариантов выбора.
        const int countOfChooses = productList.size();
        // Функция входит в цикл do- while для многократного отображения меню и ожидания ввода пользователя до тех пор, пока не будет нажата клавиша Enter.
        do
        {
            // Внутри цикла вызывается функция ShowChooseProduct для отображения текущего состояния меню, включая список товаров.
            ShowChooseProduct(number, productList);
            // Получаем код нажатой клавиши, не выводя его на экран
            key = _getch();
            ShowChooseProduct(number, productList);
            // Нажатие клавиш со стрелками (вверх и вниз) обновляет переменную `number` для навигации по вариантам.
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
                // При нажатии клавиши Enter цикл завершается.
                break;
            }
        } while (key != Enter);
        // Цвет текста устанавливается на белый на черном фоне с помощью SetColor.
        SetColor(White, Black);
        // Функция возвращает выбранный номер товара, добавляя 1 к переменной `number`.
        return number + 1;
    }
    // ChoosePlaceOnCinema позволяет пользователю выбирать место в зале кинотеатра с помощью клавиш со стрелками.
    //Функция принимает 2D - массив символов «зал», представляющий планировку зала кинотеатра, количество «строк» ​​и «столбцов» в зале,
    // логическое `reservation`, указывающее, делает ли пользователь резервирование или нет, и параметры `X` и `Y` для указания текущей позиции, а также flag, указывающий на выбор "Вернуться к началу"
    bool ChoosePlaceOnCinema(char** const hall, int const rows, int const columns, bool const reservation, int X = 0, int Y = 0, bool back = false) {
        // Функция инициализирует переменные `numberX` и `numberY` для отслеживания выбора пользователя и `key` для хранения нажатого кода клавиши.
        int numberX = X, numberY = Y, key;
        // Константы countOfChoosesX и countOfChoosesY представляют общее количество вариантов выбора, доступных в направлениях X и Y соответственно.
        const int countOfChoosesX = rows;
        const int countOfChoosesY = columns;
        // Цвет текста устанавливается на светло-зеленый на черном фоне с помощью SetColor.
        SetColor(LightGreen, Black);
        // Цикл do- while, чтобы неоднократно отображать планировку зала и ожидать ввода пользователя до тех пор, пока не будет нажата клавиша Enter.
        do
        {
            // Внутри цикла вызывается функция ShowChoosePlaceOnCinema для отображения текущей планировки зала и текущего выбора пользователя.
            ShowChoosePlaceOnCinema(hall, rows, columns, numberX, numberY);
            // Получаем код нажатой клавиши, не выводя его на экран
            key = _getch();
            ShowChoosePlaceOnCinema(hall, rows, columns, numberX, numberY);
            // Нажатие клавиш со стрелками (вверх, вниз, влево, вправо) обновляет переменные `numberX` и `numberY` для навигации по планировке зала.
            switch (key)
            {
            case Up:
                if (numberX == 0) numberX = countOfChoosesX - 1;
                else numberX--;
                break;
            case Down:
                if (numberX == countOfChoosesX+1) numberX = 0;
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
                // При нажатии клавиши Enter цикл завершается.
                break;
            }
        } while (key != Enter);
        //Для выбора опции сохранения
        if (numberX == countOfChoosesX) {
            system("cls");
            cout << "\n\t";
            PrintCinemaHall(hall, rows, columns);
            cout << "\nВы уверены в выборе?";
            bool flag = YesOrNo();
            if (!flag) {
                //return true;
                back = ChoosePlaceOnCinema(hall, rows, columns, reservation);
            }
        }
        //Для выбора опции возвращения к началу
        else if(numberX == countOfChoosesX + 1) {
            system("cls");
            back = true;

        }
        // - В зависимости от статуса бронирования и наличия мест выбранное место отмечается символами «R», «1» или «0».
        //А также записывается в специальное поле ChoosePlaces, для указания количества билетов для покупки
        else if (hall[numberX][numberY] == '0' && reservation)
        {
            hall[numberX][numberY] = 'R';
            ChoosePlaces[numberX][numberY] = 1;
            back = ChoosePlaceOnCinema(hall, rows, columns, reservation, numberX, numberY, back);
        }
        else if (hall[numberX][numberY] == '0' && !reservation) {
            hall[numberX][numberY] = '1';
            ChoosePlaces[numberX][numberY] = 1;
            back = ChoosePlaceOnCinema(hall, rows, columns, reservation, numberX, numberY, back);
        }
        else {
            hall[numberX][numberY] = '0';
            if (ChoosePlaces[numberX][numberY] != 0) {
                ChoosePlaces[numberX][numberY] = 0;
            }
            back = ChoosePlaceOnCinema(hall, rows, columns, reservation, numberX, numberY, back);
        }
        // Затем функция сбрасывает цвет текста на белый на черном фоне, очищает экран и завершает работу.
        SetColor(White, Black);
        system("cls");
        return back;
    }
    //Возвращает счёт за билеты
    int Bills(int cost) {
        int price = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (ChoosePlaces[i][j] == 1) {
                    price += cost;
                }

            }
        }
        return price;
    }
    //Выбор зала
    int ChooseHall(const vector<Hall> &halls) {
        int number = 0, key;
        const int countOfChooses = halls.size();
        do
        {
            ShowChooseHall(halls, number);
            key = _getch();//получаем код нажатой клавиши
            ShowChooseHall(halls, number);
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
    //Констркторы, по умолчанию и с аргументами, для создания зала для покупки билетов
    Menu() {
        rows = 0;
        columns = 0;
        ChoosePlaces = new int* [rows];
        for (int i = 0; i < rows; i++)
        {
            ChoosePlaces[i] = new int[columns];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                ChoosePlaces[i][j] = 0;
            }
        }
    }
    Menu(int const rows, int const columns) {
        ChoosePlaces = new int* [rows];
        this->rows = rows;
        this->columns = columns;
        for (int i = 0; i < this->rows; i++)
        {
            ChoosePlaces[i] = new int[this->columns];
        }
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->columns; j++)
            {
                ChoosePlaces[i][j] = 0;
            }
        }
    }
    //Деструктор, очищаюший ранее выделенную память
    ~Menu(){
        for (int i = 0; i < rows; i++)
        {
            delete[]ChoosePlaces[i];
        }
        delete[]ChoosePlaces;
    }
};