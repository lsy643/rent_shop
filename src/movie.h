#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <memory>
enum MovieType {CHILDREN, REGULAR, NEW_RELEASE};


class Price{
public:
    virtual MovieType getPriceCode() = 0;
    virtual double getCharge(int day_rented) = 0;
    virtual int getFrequentRenterPoints(int day_rented)
    {
        return 1;
    }
};

class ChildrensPrice: public Price{
public:
    MovieType getPriceCode(){
        return CHILDREN;
    }
    double getCharge(int day_rented)
    {
        double this_amount = 1.5;
        if(day_rented > 3)
            this_amount += double(day_rented - 3) * 1.5;
        return this_amount;
    }
};

class NewReleasePrice: public Price{
public:
    MovieType getPriceCode()
    {
        return NEW_RELEASE;
    }

    double getCharge(int day_rented)
    {
        double this_amount = double(day_rented * 3);
        return this_amount;
    }

    int getFrequentRenterPoints(int day_rented){
        if(day_rented > 1)
        {
            return 2;
        }else{
            return 1;
        }
    }
};

class RegularPrice: public Price{
public:
    MovieType getPriceCode()
    {
        return REGULAR;
    }

    double getCharge(int day_rented)
    {
        double this_amount = 2.0;
        if(day_rented > 2)
            this_amount += double(day_rented - 2) * 1.5;
        return this_amount;
    } 
};


class Movie{
public:
    Movie(std::string title, MovieType price_code);
    MovieType getPriceCode() const;
    void setPriceCode(MovieType price_code);
    std::string getTitle() const;
    bool operator==(const Movie& other_movie) const;
    double getCharge(int day_rented) const;
    int getFrequentRenterPoints(int day_rented) const;
private:
    std::string _title;
    std::shared_ptr<Price> _price;
};

#endif 
