#include "customer.h"
#include "movie.h"

Customer::Customer(std::string name)
{
    _name = name;
}

void Customer::addRental(Rental rental)
{
    _rentals.push_back(rental);
}

std::string Customer::getName()
{
    return _name;
}

double Customer::getTotalAmount()
{
    double total_amount = 0.0;
    for(Rental& this_rental: _rentals)
    {
        total_amount += this_rental.getCharge();
    }
    return total_amount;
}

int Customer::getTotalFrequentRenterPoints()
{
    int frequent_renter_points = 0;
    for(Rental& this_rental: _rentals)
    {
        frequent_renter_points += this_rental.getFrequentRenterPoints();
    }
    return frequent_renter_points;
}


std::string Customer::statement()
{
    std::string result = "Rental Record for " + getName() + "\n";
    for(Rental& this_rental: _rentals)
    {
        result += "\t" + this_rental.getMovie().getTitle() + "\t" 
            + std::to_string(this_rental.getCharge()) + "\n";
    }
    result += "Amount owed is " + std::to_string(getTotalAmount()) + "\n";
    result += "You earned " + std::to_string(getTotalFrequentRenterPoints()) + " frequent renter points";
    return result;
}