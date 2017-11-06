#include "gtest/gtest.h"
#include <string>
#include "src/movie.h"
#include "src/rental.h"
#include "src/customer.h"

TEST(MovieTest, movie_title_test) {
    Movie test_movie("Her", CHILDREN);
    EXPECT_EQ(test_movie.getTitle(), "Her");
}

TEST(MovieTest, movie_code_test) {
    Movie test_movie("Her", CHILDREN);
    EXPECT_EQ(test_movie.getPriceCode(), CHILDREN);

    test_movie.setPriceCode(REGULAR);
    EXPECT_EQ(test_movie.getPriceCode(), REGULAR);

    test_movie.setPriceCode(NEW_RELEASE);
    EXPECT_EQ(test_movie.getPriceCode(), NEW_RELEASE);
}

TEST(RentalTest, day_rented_test) {
    Movie test_movie("Her", CHILDREN);
    Rental test_rental(test_movie, 3);
    EXPECT_EQ(3, test_rental.getDayRented());
}

TEST(RentalTest, movie_test) {
    Movie test_movie("Her", CHILDREN);
    Rental test_rental(test_movie, 3);
    EXPECT_EQ(test_movie, test_rental.getMovie());
}


TEST(CustomerTest, name_test){
    Customer test_customer("Jack");
    EXPECT_EQ("Jack", test_customer.getName());
}

TEST(CustomerTest, empty_rentals_test){
    Customer test_customer("Jack");
    std::string expect_statement = "Rental Record for Jack\n";
    expect_statement += "Amount owed is " + std::to_string(0.0) + "\n";
    expect_statement += "You earned " + std::to_string(0) + " frequent renter points";
    EXPECT_EQ(expect_statement, test_customer.statement());
}

TEST(CustomerTest, one_rental_test_1){
    Customer test_customer("Jack");
    Movie test_movie("Her", NEW_RELEASE);
    Rental test_rental(test_movie, 5);
    test_customer.addRental(test_rental);

    double expect_total_amount = 15.0;
    int expect_frequent_renter_points = 2;
    std::string expect_statement = "Rental Record for Jack\n";
    expect_statement += "\tHer\t" + std::to_string(15.0) + "\n";
    expect_statement += "Amount owed is " + std::to_string(expect_total_amount) + "\n";
    expect_statement += "You earned " + std::to_string(expect_frequent_renter_points) + " frequent renter points";
    EXPECT_EQ(expect_statement, test_customer.statement());
}

TEST(CustomerTest, one_rental_test_2){
    Customer test_customer("Jack");
    Movie test_movie("Her", NEW_RELEASE);
    Rental test_rental(test_movie, 1);
    test_customer.addRental(test_rental);

    double expect_total_amount = 3.0;
    int expect_frequent_renter_points = 1;
    std::string expect_statement = "Rental Record for Jack\n";
    expect_statement += "\tHer\t" + std::to_string(3.0) + "\n";
    expect_statement += "Amount owed is " + std::to_string(expect_total_amount) + "\n";
    expect_statement += "You earned " + std::to_string(expect_frequent_renter_points) + " frequent renter points";
    EXPECT_EQ(expect_statement, test_customer.statement());
}

TEST(CustomerTest, one_rental_test_3){
    Customer test_customer("Jack");
    Movie test_movie("Her", CHILDREN);
    Rental test_rental(test_movie, 2);
    test_customer.addRental(test_rental);

    double expect_total_amount = 1.5;
    int expect_frequent_renter_points = 1;
    std::string expect_statement = "Rental Record for Jack\n";
    expect_statement += "\tHer\t" + std::to_string(1.5) + "\n";
    expect_statement += "Amount owed is " + std::to_string(expect_total_amount) + "\n";
    expect_statement += "You earned " + std::to_string(expect_frequent_renter_points) + " frequent renter points";
    EXPECT_EQ(expect_statement, test_customer.statement());
}

TEST(CustomerTest, one_rental_test_4){
    Customer test_customer("Jack");
    Movie test_movie("Her", CHILDREN);
    Rental test_rental(test_movie, 5);
    test_customer.addRental(test_rental);

    double expect_total_amount = 4.5;
    int expect_frequent_renter_points = 1;
    std::string expect_statement = "Rental Record for Jack\n";
    expect_statement += "\tHer\t" + std::to_string(4.5) + "\n";
    expect_statement += "Amount owed is " + std::to_string(expect_total_amount) + "\n";
    expect_statement += "You earned " + std::to_string(expect_frequent_renter_points) + " frequent renter points";
    EXPECT_EQ(expect_statement, test_customer.statement());
}

TEST(CustomerTest, one_rental_test_5){
    Customer test_customer("Jack");
    Movie test_movie("Her", REGULAR);
    Rental test_rental(test_movie, 1);
    test_customer.addRental(test_rental);

    double expect_total_amount = 2.0;
    int expect_frequent_renter_points = 1;
    std::string expect_statement = "Rental Record for Jack\n";
    expect_statement += "\tHer\t" + std::to_string(2.0) + "\n";
    expect_statement += "Amount owed is " + std::to_string(expect_total_amount) + "\n";
    expect_statement += "You earned " + std::to_string(expect_frequent_renter_points) + " frequent renter points";
    EXPECT_EQ(expect_statement, test_customer.statement());
}

TEST(CustomerTest, one_rental_test_6){
    Customer test_customer("Jack");
    Movie test_movie("Her", REGULAR);
    Rental test_rental(test_movie, 6);
    test_customer.addRental(test_rental);

    double expect_total_amount = 8.0;
    int expect_frequent_renter_points = 1;
    std::string expect_statement = "Rental Record for Jack\n";
    expect_statement += "\tHer\t" + std::to_string(8.0) + "\n";
    expect_statement += "Amount owed is " + std::to_string(expect_total_amount) + "\n";
    expect_statement += "You earned " + std::to_string(expect_frequent_renter_points) + " frequent renter points";
    EXPECT_EQ(expect_statement, test_customer.statement());
}

TEST(CustomerTest, three_rentals_test_1){
    Customer test_customer("Jack");

    Movie test_movie_1("Her", REGULAR);
    Rental test_rental_1(test_movie_1, 6);
    test_customer.addRental(test_rental_1);
    
    Movie test_movie_2("Her", CHILDREN);
    Rental test_rental_2(test_movie_2, 5);
    test_customer.addRental(test_rental_2);

    Movie test_movie_3("Her", NEW_RELEASE);
    Rental test_rental_3(test_movie_3, 5);
    test_customer.addRental(test_rental_3);

    double expect_total_amount = 8.0 + 4.5 + 15.0;
    int expect_frequent_renter_points = 1 + 1 + 2;
    std::string expect_statement = "Rental Record for Jack\n";
    expect_statement += "\tHer\t" + std::to_string(8.0) + "\n";
    expect_statement += "\tHer\t" + std::to_string(4.5) + "\n";
    expect_statement += "\tHer\t" + std::to_string(15.0) + "\n";
    expect_statement += "Amount owed is " + std::to_string(expect_total_amount) + "\n";
    expect_statement += "You earned " + std::to_string(expect_frequent_renter_points) + " frequent renter points";
    EXPECT_EQ(expect_statement, test_customer.statement());
}

TEST(CustomerTest, three_rentals_test_2){
    Customer test_customer("Jack");

    Movie test_movie_1("Her", REGULAR);
    Rental test_rental_1(test_movie_1, 1);
    test_customer.addRental(test_rental_1);
    
    Movie test_movie_2("Her", CHILDREN);
    Rental test_rental_2(test_movie_2, 1);
    test_customer.addRental(test_rental_2);

    Movie test_movie_3("Her", NEW_RELEASE);
    Rental test_rental_3(test_movie_3, 1);
    test_customer.addRental(test_rental_3);

    double expect_total_amount = 2.0 + 1.5 + 3.0;
    int expect_frequent_renter_points = 1 + 1 + 1;
    std::string expect_statement = "Rental Record for Jack\n";
    expect_statement += "\tHer\t" + std::to_string(2.0) + "\n";
    expect_statement += "\tHer\t" + std::to_string(1.5) + "\n";
    expect_statement += "\tHer\t" + std::to_string(3.0) + "\n";
    expect_statement += "Amount owed is " + std::to_string(expect_total_amount) + "\n";
    expect_statement += "You earned " + std::to_string(expect_frequent_renter_points) + " frequent renter points";
    EXPECT_EQ(expect_statement, test_customer.statement());
}