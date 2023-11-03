#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;


int check_correct(int limit) {
	int number;
	cin >> number;

	if (number > limit || number < 0) {
		cout << "������" << endl;
	}

	return number;
}

void read_review() {

	ifstream inFile("review.txt");

	vector<string> all_review;

	string line;

	while (getline(inFile, line)) {
		all_review.push_back(line);
	}

	char next_step;

	cout << "� ����� " << all_review.size() << " �������\n������� ����� ������ ������� ������ ��������� ��� 0 - ��� ������ �� ������ ������" << endl;
	int user_chose;
	user_chose = check_correct(all_review.size());


	if (user_chose == 0) {
		return;
	}

	while (true)
	{


		if (user_chose == 0) {
			return;
		}


		cout << all_review[user_chose - 1] << endl;

		cout << "���������� ������?\n������� ����� ������� ������ ��� 0 - ��� ������ �� ������ ������" << endl;
		cout << "�����: ";
		user_chose = check_correct(all_review.size());

	}
	inFile.close();
}
void write_review() {
	ofstream outFile("review.txt", ios::app);

	int user_chose;
	cout << "�������� ����� �����?\n1 - ��������\n2 - ������\n�����:";
	user_chose = check_correct(2);
	if (user_chose == 2) {
		return;
	}

	while (user_chose == 1) {
		string line;
		cout << "��� �����: ";
		cin >> line;
		outFile << line << endl;;



		user_chose = check_correct(2);
	}
	outFile.close();

}

int guest_book() {
	setlocale(LC_ALL, "Russian");

	string input;

	string line;
	char ch;
	int user_chose;
	do {
		cout << "��������� ��� �������� �����?\n1 - ���������\n2 - ��������\n3 - ������\n�����: ";
		cin >> user_chose;
		switch (user_chose)
		{
		case 1:
			read_review();
			break;

		case 2:
			write_review();
			break;
		case 3:
			break;
		}

	} while (user_chose != 3);
}