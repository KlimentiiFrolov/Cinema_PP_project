

#ifndef CINEMA_PP_PROJECT_INCLUDES_H
#define CINEMA_PP_PROJECT_INCLUDES_H
// Функции для бронирования.
void Ticket_reservation_or_buy(char** hall, int rows, int columns, bool reservation);
void movie_merchandaise();
void show_cinema(char**,int,int);
template <typename T>
T get_input(const std::string& prompt);

#endif //CINEMA_PP_PROJECT_INCLUDES_H
