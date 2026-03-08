#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include "Manga.h"

class Parser {
public:
    // Чтение из CSV-файла и возврат вектора объектов Manga
    static std::vector<Manga> read(const std::string& filename);

    // Запись вектора объектов Manga в CSV-файл
    static void write(const std::vector<Manga>& mangas, const std::string& filename);
};

#endif