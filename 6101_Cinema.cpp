// 6101_Cinema.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

void show_cinema(bool**,int,int);
bool buy_ticket(bool**, int, int); //принимает зал(массив) номер ряда номер места
bool** create_hall(int,int);

// тип места place.first - ряд place.second - место
typedef std::pair<int,int> place;

int score_place(int n, int m, const place& pl){
	return std::abs(pl.first-n/2) + std::abs(pl.second-m/2);
}

// возвращает вектор с местами, где справа от них есть num мест типа type (0 - пустое)
// места ближе к центру первее в массиве
std::vector<place> find_close_seats(char** cinema, int n, int m, int num, int type = 0) {
	std::vector<place> places;
	
	for(int i = 0; i < n; i++){
		int seq = 0;
		for (int j = 0; j < m; j++) {
			if(cinema[i][j] == type){
				seq++;
				if(seq >= num)
					places.emplace_back(i, j-num+1);
			}
		}
	}
	
	std::sort(places.begin(), places.end(), [n,m](const place& a, const place& b){return score_place(n, m, a) < score_place(n, m, b) ;});
	
	return std::move(places);
}

namespace tests
{
	void test_Distribution(){
		char** cinema = new char*[10];
		for (int i = 0; i < 10; i++){
			cinema[i] = new char[10]{};
			for (int j = 0; j < 10; j++) {
				cinema[i][j] = 1;
			}
		}
		
		cinema[5][4] = 0;
		cinema[5][5] = 0;
		cinema[5][6] = 0;
		
		auto res = find_close_seats(cinema, 10, 10, 3);
		
		assert(res.size() == 1);
		assert(res[0].first == 5);
		assert(res[0].second == 4);

		cinema[5][7] = 0;
		
		res = find_close_seats(cinema, 10, 10, 3);
		
		assert(res.size() == 2);
		assert(res[0].first == 5);
		assert(res[0].second == 5);
		assert(res[1].first == 5);
		assert(res[1].second == 4);
		
		cinema[5][7] = 1;
		
		cinema[4][4] = 0;
		cinema[4][5] = 0;
		cinema[4][6] = 0;
		
		res = find_close_seats(cinema, 10, 10, 3);
		
		assert(res.size() == 2);
		assert(res[0].first == 5);
		assert(res[0].second == 4);
		assert(res[1].first == 4);
		assert(res[1].second == 4);
		
		/*for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << (int)cinema[i][j] << ' ';
			}
			cout << endl;
		}*/
	}
}

int main()
{
	bool** cinema1 = create_hall(3, 10);
	show_cinema(cinema1, 3, 10);
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
