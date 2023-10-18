//��������� ����������
#include <iostream>
//���������� ��� ������ �� ��������
#include <string>
using namespace std;
/*����: ��� ������� � ����� ������� �����,
 ������� ����� �������������� ��� ��������� �������� ������
*/
class BestInput {
	string EraseNulls(string num) {
		int poz1 = -1;
		//����� �� ������� ����, �� ��� �������� �� �������
		int pozRem = 0;
		//������ ���� �� ����������� ������
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
			//���� ��������� �� ����� ��� ������� 0
			poz = num.find_first_of("0,.", poz - 1);
			//���� ������� �������
			if (poz != num.npos)
			{
				//������� ������� ������ �� �������� �������
				num.erase(poz, 1);
			}
		} while (poz != num.npos);//���� �� ����� npos (������, ��� ������ � ������ �� ������)
		//���������� ���� �� �������, ���� �� �� ����� ���
		if (num[pozRem] == '~')
		{
			num[pozRem] = '0';
		}
		return num;
	}
	string ReplaceDotToComma(string str) {
		//�������������� �������
		int poz = -1;
		do
		{
			//���� ��������� ����� �����
			poz = str.find('.', poz + 1);
			//���� ������� �������
			if (poz != str.npos)
			{
				//������� ����� �� �������� �������
				str.erase(poz, 1);
				//��������� ������� �� �������� �������
				str.insert(poz, 1, ',');
			}
			//str.npos - ���������, ������������ -1
		} while (poz != str.npos);//���� �� ����� npos (������, ��� ������ � ������ �� ������)
		return str;
	}
	string ReplaceCommaToDot(string str) {
		//�������������� �������
		int poz = -1;
		do
		{
			//���� ��������� ����� �����
			poz = str.find(',', poz + 1);
			//���� ������� �������
			if (poz != str.npos)
			{
				//������� ����� �� �������� �������
				str.erase(poz, 1);
				//��������� ������� �� �������� �������
				str.insert(poz, 1, '.');
			}
			//str.npos - ���������, ������������ -1
		} while (poz != str.npos);//���� �� ����� npos (������, ��� ������ � ������ �� ������)
		return str;
	}
public:
	double InputDouble() {
		string str;
		bool flag = true;
		double num;
		do {
			//���� ������� stod ������� ����������, �� ������ ���������� ���������, ������������ ������, ��� ������ �����������
			//� �������� ������ �����
			try {
				//���� ����� ��� ������
				getline(cin, str);
				//������ ����� �� ������� ��� ��������� (������� �� setlocale()) ��� ����������� ����������� � double
				//str = ReplaceDotToComma(str); //���� �������������� ���� ��������� setlocale()
				str = ReplaceCommaToDot(str);	//���� �������������� �� ���� ��������� setlocale()
				//����������� string � double
				num = stod(str);
				flag = false;
				//stod ����������� ������� ����� �����, ������ ����������� ����������, ������� ������ �������������� ��������
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
				//������� stoi ���������� ����� � ������ ����� �������� �������� � ������
				//������� �������� � ��������� ��������� ����� ���������� �� �����
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
		//������ ����
		do
		{
			getline(cin, tryagain);
			if (tryagain == "��" || tryagain == "���" || tryagain == "yes" || tryagain == "no") {
				flag = false;
			}
			else {
				cout << "\n����������� �������! ������� (��/���): ";
			}
		} while (flag);
		return (tryagain == "��" || tryagain == "yes") ? true : false;
	}
};