#include <iostream>
#include <vector>
#include "../Manga.h"
#include "../parser.h"

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    //Указал прямой путь, можно просто указать manga.csv
    std::string inputFile = "C:\\Users\\maksi\\CLionProjects\\IntrodTTProf\\manga.csv";
    std::string outputFile = "manga_output.csv";

    // Чтение данных из CSV
    std::vector<Manga> mangas = Parser::read(inputFile);

    if (mangas.empty()) {
        std::cerr << "Не удалось прочитать данные или файл пуст." << std::endl;
        return 1;
    }

    // Вывод прочитанных данных на экран для проверки
    std::cout << "Прочитано " << mangas.size() << " записей:\n";
    for (const auto& m : mangas) {
        std::cout << "Название: " << m.getTitle()
                  << ", Жанр: " << m.getGenre()
                  << ", Статус производства: " << m.getProdStatus()
                  << ", Статус перевода: " << m.getTransStatus()
                  << ", Год: " << m.getYear()
                  << ", Глав: " << m.getChapters()
                  << ", Оценка: " << m.getRating() << std::endl;
    }

    // Запись данных в новый CSV-файл
    Parser::write(mangas, outputFile);

    return 0;
}