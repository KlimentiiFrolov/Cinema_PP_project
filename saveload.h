#pragma once
#include "film_hall.h"

#include <fstream>
#include <string>
#include <regex>

static void skipwhtiespaces(std::ifstream& file) {
	int c;
	while ((c = file.peek()) != EOF && isspace(c)) {
		file.get();
	}
}

const std::regex size_regex("(\\d+) (\\d+)");
const std::regex time_regex("(\\d+)\\:(\\d+)");

static std::vector<Film> loadFilms(const char* filename) {
	std::ifstream file(filename);
	if (!file.is_open())
		throw std::runtime_error("файл не найден");

	std::vector<Film> films;

	do {
		skipwhtiespaces(file);

		std::string name;
		getline(file, name);

		skipwhtiespaces(file);
		std:string desc;
		{
			int c;
			while ((c = file.peek()) != EOF && c != '~') {
				file.get();
				desc.push_back(c);
			}
		}

		if (file.get() != '~') {
			throw std::runtime_error("ошибка в описании фильма: нет закрывающего символа");
		}

		skipwhtiespaces(file);

		std::string line;
		getline(file, line);
		std::smatch sm;
		if (!std::regex_match(line, sm, size_regex)) {
			throw std::runtime_error("ошибка в задании размеров зала");
		}

		int rows = std::stol(sm[1]);
		int cols = std::stol(sm[2]);

		Film film = { name, desc, std::vector<Hall>() };

		bool cont = true;
		skipwhtiespaces(file);

		std::streampos old;
		while (cont && (file.peek() != EOF)) {
			old = file.tellg();
			getline(file, line);

			if (std::regex_match(line, sm, time_regex)) {
				int hrs = std::stol(sm[1]);
				int mns = std::stol(sm[2]);

				Hall hl = create_hall(rows, cols);
				hl.time = hrs * 60 + mns;

				for (int i = 0; i < rows; i++) {
					for (int j = 0; j < cols; j++) {
						hl.data[i][j] = file.get();
						skipwhtiespaces(file);
					}
				}

				film.halls.push_back(hl);
			}
			else {
				cont = false;
			}
		}

		if (film.halls.size() == 0) {
			throw std::runtime_error("у фильма 0 залов");
		}

		file.seekg(old);
		skipwhtiespaces(file);

		films.push_back(film);
	} while (file.peek() != EOF);

	return films;
}

static void saveFilms(const std::vector<Film>& films, const char* filename) {
	std::ofstream file(filename, std::ios::trunc);
	if (!file.is_open())
		return;

	for (auto& f : films) {
		file << f.name << std::endl << std::endl;
		file << f.desc << "~" << std::endl << std::endl;

		file << f.halls[0].rows << ' ' << f.halls[0].cols << std::endl << std::endl;

		for (auto& h : f.halls) {
			file << h.time / 60 << ':' << h.time % 60 << std::endl;
			for (int i = 0; i < h.rows; i++) {
				for (int j = 0; j < h.cols; j++) {
					file.put(h.data[i][j]);
				}
				file << std::endl;
			}
			file << std::endl;
		}

		file << std::endl;
	}
}