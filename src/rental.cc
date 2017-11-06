#include "rental.h"

Rental::Rental(Movie movie, int day_rented)
    :_movie(movie)
{
    _day_rented = day_rented;
}

const Movie& Rental::getMovie() const
{
    return _movie;
}

int Rental::getDayRented() const
{
    return _day_rented;
}

int Rental::getFrequentRenterPoints() const
{
    return _movie.getFrequentRenterPoints(_day_rented);
}

double Rental::getCharge() const
{
    return _movie.getCharge(_day_rented);
}