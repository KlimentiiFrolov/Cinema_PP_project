
#ifndef CINEMA_PP_PROJECT_INCLUDES_H
#define CINEMA_PP_PROJECT_INCLUDES_H

#include <vector>

// TicketReservation.cpp
bool Row_is_full(char** const hall, int const chosenR, int const columns);
bool Hall_is_full(char** const hall, int const rows, int const columns);
void Ticket_reservation(char** const hall, int const rows, int const columns);

// Movie_merchandise.cpp
void order_cola(int& summa, std::vector<std::string>& order);
void order_popcorn(int& summa, std::vector<std::string>& order);
void print_order(int summa, std::vector<std::string> order);
void movie_merchandaise();

// DZPP2.cpp
int verefecation_Purchase_of_tickets();
int Purchase_of_tickets();

// bestinput.cpp
// нужно было делать по-другому, если сделать так придется переписывать весь bestinput.cpp
/*class BestInput{
	std::string EraseNulls(std::string num);
	std::string ReplaceDotToComma(std::string str);
	std::string ReplaceCommaToDot(std::string str);
public:
	double InputDouble();
	int InputInt();
	std::string InputString();
	char InputChar();
	bool YesOrNo();
};*/

#endif //CINEMA_PP_PROJECT_INCLUDES_H
