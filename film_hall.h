#ifndef FILM_HALL_H	
#define FILM_HALL_H

#include <vector>
#include <string>
//��������� ��� ����, ��� ��� ������ �������� ����� ������ ������, ���������� ����� � ��������, � ����� ��� ���
struct Hall {
	int time;
	int rows;
	int cols;
	char** data;
};
//��������� ��� ������, ��� ���� ���� - ��������, �������� � ����� ������ ����� ��� ����� ������
struct Film {
	std::string name;
	std::string desc;
	std::vector<Hall> halls;
};
//�������� ����
static Hall create_hall(int n, int m) {

	char** arr = new char* [n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = new char[m]; // 0 - ��������� �����, 1 - ������
		memset(arr[i], '0', m); // ������������� ������� '0'
	}
	return Hall{ 0,n,m,arr };
}

#endif // !
