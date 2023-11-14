

#ifndef CINEMA_PP_PROJECT_INCLUDES_H
#define CINEMA_PP_PROJECT_INCLUDES_H

#include <vector>

// Movie_merchandise.cpp
void order_cola(int& summa, std::vector<std::string>& order);
void order_popcorn(int& summa, std::vector<std::string>& order);
void print_order(int summa, const std::vector<std::string>& order);
bool movie_merchandaise();

// DZPP2.cpp
int verefecation_Purchase_of_tickets();
int Purchase_of_tickets();

#endif //CINEMA_PP_PROJECT_INCLUDES_H
