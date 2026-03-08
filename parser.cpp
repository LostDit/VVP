#include "parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

static std::string replaceCommaWithDot(const std::string& str) {
    std::string result = str;
    std::replace(result.begin(), result.end(), ',', '.');
    return result;
}

std::vector<Manga> Parser::read(const std::string& filename) {
    std::vector<Manga> result;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл " << filename << std::endl;
        return result;
    }

    std::string line;
    int lineNumber = 0;

    while (std::getline(file, line)) {
        ++lineNumber;
        if (line.empty()) continue;

        if (lineNumber == 1 || lineNumber == 2) continue;

        if (line.find("Манга") != std::string::npos && line.find("Жанр") != std::string::npos) {
            continue;
        }

        std::stringstream ss(line);
        std::string cell;

        std::string title, genre, prodStatus, transStatus;
        std::string yearStr, chaptersStr, ratingStr;

        std::getline(ss, title, ';');
        std::getline(ss, genre, ';');
        std::getline(ss, prodStatus, ';');
        std::getline(ss, transStatus, ';');
        std::getline(ss, yearStr, ';');
        std::getline(ss, chaptersStr, ';');
        std::getline(ss, ratingStr, ';');

        int year = 0;
        int chapters = 0;
        double rating = 0.0;

        try {
            year = std::stoi(yearStr);
            chapters = std::stoi(chaptersStr);
            rating = std::stod(replaceCommaWithDot(ratingStr));
        } catch (const std::exception& e) {
            std::cerr << "Ошибка преобразования в строке " << lineNumber << ": " << e.what() << std::endl;
            continue;
        }

        result.emplace_back(title, genre, prodStatus, transStatus, year, chapters, rating);
    }

    file.close();
    return result;
}

void Parser::write(const std::vector<Manga>& mangas, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось создать файл " << filename << std::endl;
        return;
    }

    file << "Манга;Жанр;Статус производства;Статус перевода;Год выпуска;Главы;Средняя оценка\n";

    for (const auto& m : mangas) {
        file << m.getTitle() << ';'
             << m.getGenre() << ';'
             << m.getProdStatus() << ';'
             << m.getTransStatus() << ';'
             << m.getYear() << ';'
             << m.getChapters() << ';';

        std::string ratingStr = std::to_string(m.getRating());
        std::replace(ratingStr.begin(), ratingStr.end(), '.', ',');
        file << ratingStr << '\n';
    }

    file.close();
    std::cout << "Данные успешно записаны в файл " << filename << std::endl;
}