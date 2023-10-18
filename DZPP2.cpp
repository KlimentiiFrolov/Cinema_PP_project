#include <iostream>

using namespace std;

int verefecation_Purchase_of_tickets()
{
	int n;
	while (!(cin >> n) || cin.peek() != '\n' || n < 1)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "You have not entered a valid value!\n";
		cout << "Please enter a positive and integer value\n";
	}
	return n;
}
int Purchase_of_tickets()
{
	int num_of_tick;
	cout << "How many tickets does client want to purchase?\n";
	num_of_tick = verefecation_Purchase_of_tickets();
	cout << "Client has purchased " << num_of_tick << " tickets\n";
	return num_of_tick;
}
