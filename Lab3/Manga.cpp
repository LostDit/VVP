#include "../Manga.h"

Manga::Manga() : title(""), genre(""), prodStatus(""), transStatus(""), year(0), chapters(0), rating(0.0) {}

Manga::Manga(const std::string& title, const std::string& genre, const std::string& prodStatus,
             const std::string& transStatus, int year, int chapters, double rating)
    : title(title), genre(genre), prodStatus(prodStatus), transStatus(transStatus),
      year(year), chapters(chapters), rating(rating) {}

std::string Manga::getTitle() const { return title; }
std::string Manga::getGenre() const { return genre; }
std::string Manga::getProdStatus() const { return prodStatus; }
std::string Manga::getTransStatus() const { return transStatus; }
int Manga::getYear() const { return year; }
int Manga::getChapters() const { return chapters; }
double Manga::getRating() const { return rating; }

void Manga::setTitle(const std::string& t) { title = t; }
void Manga::setGenre(const std::string& g) { genre = g; }
void Manga::setProdStatus(const std::string& ps) { prodStatus = ps; }
void Manga::setTransStatus(const std::string& ts) { transStatus = ts; }
void Manga::setYear(int y) { year = y; }
void Manga::setChapters(int ch) { chapters = ch; }
void Manga::setRating(double r) { rating = r; }