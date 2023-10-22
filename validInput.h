//
// Created by nikit on 22.10.2023.
//

#ifndef CINEMA_PP_PROJECT_VALIDINPUT_H
#define CINEMA_PP_PROJECT_VALIDINPUT_H

#include <iostream>
#include <sstream>
#include <limits>

template <typename T>
T get_input(const std::string& prompt) {
    std::string input;
    T value;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        std::stringstream ss(input);
        if (ss >> value && ss.peek() == -1) { // ss.eof
            return value;
        }
        std::cout << "Ошибка ввода! Пожалуйста, попробуйте снова!\n";
    }
}
#endif //CINEMA_PP_PROJECT_VALIDINPUT_H
