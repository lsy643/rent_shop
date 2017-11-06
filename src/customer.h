#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "rental.h"

class Customer{
public:
    Customer(std::string name);
    void addRental(Rental rental);
    std::string getName();
    std::string statement();
private:
    double getTotalAmount();
    int getTotalFrequentRenterPoints();
    std::string _name;
    std::vector<Rental> _rentals;
};

#endif
