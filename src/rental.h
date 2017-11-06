#ifndef RENTAL_H
#define RENTAL_H
#include "movie.h"
class Rental{
public:
    Rental(Movie movie, int day_rented);
    const Movie& getMovie() const;
    int getDayRented() const;
    double getCharge() const;
    int getFrequentRenterPoints() const;
private:
    Movie _movie;
    int _day_rented;
};

#endif