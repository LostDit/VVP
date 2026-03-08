#ifndef MANGA_H
#define MANGA_H

#include <string>

class Manga {

private:
    std::string title;
    std::string genre;
    std::string prodStatus;
    std::string transStatus;
    int year;
    int chapters;
    double rating;

public:
    // Конструкторы
    Manga();
    Manga(const std::string& title, const std::string& genre, const std::string& prodStatus,
          const std::string& transStatus, int year, int chapters, double rating);

    // Геттеры
    std::string getTitle() const;
    std::string getGenre() const;
    std::string getProdStatus() const;
    std::string getTransStatus() const;
    int getYear() const;
    int getChapters() const;
    double getRating() const;

    // Сеттеры
    void setTitle(const std::string& title);
    void setGenre(const std::string& genre);
    void setProdStatus(const std::string& prodStatus);
    void setTransStatus(const std::string& transStatus);
    void setYear(int year);
    void setChapters(int chapters);
    void setRating(double rating);
};

#endif