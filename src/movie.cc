#include "movie.h"

Movie::Movie(std::string title, MovieType price_code){
    _title = title;
    setPriceCode(price_code);
}

MovieType Movie::getPriceCode() const
{
    return _price->getPriceCode();
}

void Movie::setPriceCode(MovieType price_code)
{
    switch(price_code){
        case CHILDREN:
            _price = std::make_shared<ChildrensPrice>();
            break;
        case REGULAR:
            _price = std::make_shared<RegularPrice>();
            break;
        case NEW_RELEASE:
            _price = std::make_shared<NewReleasePrice>();
            break;
        default:
            break;
    }
}

std::string Movie::getTitle() const
{
    return _title;
}

double Movie::getCharge(int day_rented) const
{
    return _price->getCharge(day_rented);
}

int Movie::getFrequentRenterPoints(int day_rented) const
{
    return _price->getFrequentRenterPoints(day_rented);
}

bool Movie::operator==(const Movie& other_movie) const
{
    if(getPriceCode() == other_movie.getPriceCode()){
        if(getTitle() == other_movie.getTitle())
        {
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}