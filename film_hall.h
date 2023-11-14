#ifndef FILM_HALL_H	
#define FILM_HALL_H

#include <vector>
#include <string>
//Структура для зала, где его полями являются время начала сеанса, количество рядов и столбцов, а также сам зал
struct Hall {
	int time;
	int rows;
	int cols;
	char** data;
};
//Структура для фильма, где есть поля - название, описание и также вектор залов для этого фильма
struct Film {
	std::string name;
	std::string desc;
	std::vector<Hall> halls;
};
//Создание зала
static Hall create_hall(int n, int m) {

	char** arr = new char* [n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = new char[m]; // 0 - свободное место, 1 - занято
		memset(arr[i], '0', m); // инициализация массива '0'
	}
	return Hall{ 0,n,m,arr };
}

#endif // !
