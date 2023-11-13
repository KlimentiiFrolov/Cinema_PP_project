#include <iostream>
//Библиотека для работы со строками
#include <string>
#include "includes.h"

using namespace std;
/*Артём: для удобства я решил сделать класс,
 который будет использоваться для валидации мусорных данных
*/
class BestInput {
	string EraseNulls(string num) {
		int poz1 = -1;
		//Чтобы не стереть ноль, мы его запомним на позиции
		int pozRem = 0;
		//Замена нуля на посторонний символ
		do
		{
			poz1 = num.find(",", poz1 + 1);
			if (poz1 != num.npos)
			{
				if (num[poz1 - 1] == '0')
				{
					pozRem = poz1 - 1;
					num[pozRem] = '~';
				}
			}
		} while (poz1 != num.npos);//num.npos = -1
		int poz = num.length();
		do
		{
			//Ищет вхождение до точки или запятой 0
			poz = num.find_first_of("0,.", poz - 1);
			//Если позиция найдена
			if (poz != num.npos)
			{
				//Стираем элемент строки на указаной позиции
				num.erase(poz, 1);
			}
		} while (poz != num.npos);//пока не вернёт npos (значит, что символ в строке не найден)
		//Возвращаем ноль на позицию, если он до этого был
		if (num[pozRem] == '~')
		{
			num[pozRem] = '0';
		}
		return num;
	}
	string ReplaceDotToComma(string str) {
		//Инициализируем позицию
		int poz = -1;
		do
		{
			//Ищет вхождение знака точки
			poz = str.find('.', poz + 1);
			//Если позиция найдена
			if (poz != str.npos)
			{
				//Стираем точку на указаной позиции
				str.erase(poz, 1);
				//Вставляем запятую на указаной позиции
				str.insert(poz, 1, ',');
			}
			//str.npos - константа, возвращающая -1
		} while (poz != str.npos);//пока не вернёт npos (значит, что символ в строке не найден)
		return str;
	}
	string ReplaceCommaToDot(string str) {
		//Инициализируем позицию
		int poz = -1;
		do
		{
			//Ищет вхождение знака точки
			poz = str.find(',', poz + 1);
			//Если позиция найдена
			if (poz != str.npos)
			{
				//Стираем точку на указаной позиции
				str.erase(poz, 1);
				//Вставляем запятую на указаной позиции
				str.insert(poz, 1, '.');
			}
			//str.npos - константа, возвращающая -1
		} while (poz != str.npos);//пока не вернёт npos (значит, что символ в строке не найден)
		return str;
	}
public:
	double InputDouble() {
		string str;
		bool flag = true;
		double num;
		do {
			//Если функция stod поймает исключение, то вместо прерывания программы, пользователю скажут, что данные некорректны
			//И попросят ввести снова
			try {
				//Ввод числа как строки
				getline(cin, str);
				//Замена точек на запятые или наоборот (зависит от setlocale()) для дальнейшей конвертации в double
				//str = ReplaceDotToComma(str); //Если местоположение было изменено setlocale()
				str = ReplaceCommaToDot(str);	//Если местоположение не было изменено setlocale()
				//Конвертация string в double
				num = stod(str);
				flag = false;
				//stod отбрасывает символы после чисел, вместо выкидывания исключения, поэтому делаем дополнительную проверку
				if ((EraseNulls(to_string(num)).compare(str) != 0)) {
					cout << "Incorrect input, enter a satisfactory value: ";
					flag = true;
				}
			}
			catch (...)
			{
				cout << "Incorrect input, enter a satisfactory value: ";
			}
		} while (flag);
		return num;
	}
	int InputInt() {
		string str;
		bool flag = true;
		int number;
		do {
			try {
				getline(cin, str);
				number = stoi(str.c_str());
				flag = false;
				//Функция stoi игнорирует точки и символы после числовых значений в строке
				//Поэтому числовое и строковое значения могут отличаться по длине
				if (to_string(number).compare(str) != 0) {
					cout << "Incorrect input, enter an integer: ";
					flag = true;
				}
			}
			catch (...)
			{
				cout << "Incorrect input, enter a satisfactory value: ";
			}
		} while (flag);
		return number;
	}
	string InputString() {
		string str;
		getline(cin, str);
		return str;
	}
	char InputChar() {
		char ch;
		bool flag = true;
		do
		{
			string str;
			getline(cin, str);
			if (str.length() == 1) {
				flag = false;
				ch = str[0];
			}
			else {
				cout << "Enter character: ";
			}
		} while (flag);

		return ch;
	}
	bool YesOrNo() {
		bool flag = true;
		string tryagain;
		//Повтор игры
		do
		{
			getline(cin, tryagain);
			if (tryagain == "да" || tryagain == "нет" || tryagain == "yes" || tryagain == "no") {
				flag = false;
			}
			else {
				cout << "\nНеизвестная команда! Введите (да/нет): ";
			}
		} while (flag);
		return (tryagain == "да" || tryagain == "yes") ? true : false;
	}
};