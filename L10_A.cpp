/*
    Programmer: Ryan Posey
    Assignment: L10.A
    Purpose: Practice using classes
    Due date: 9/25/2025
*/

#include <iostream>
#include <iomanip>

using namespace std;

class personType { 
    public:
        std::string first_name_;
        std::string last_name_;
        std::string address_;
        double height_inches_{};
        std::string date_of_birth_;  
        char gender_{}; 

        void print() const;
        bool equals(const personType& other) const;
};

void personType::print() const { // Stretch 2 (Formatted output)
    std::cout <<  left << setw(20) << " | Name: " << left << this->first_name_ << " " << this->last_name_ << endl
        << left << setw(20) << " | Address: " << left << this->address_ << endl
        << left << setw(20) << " | Height: " << left << std::fixed << std::setprecision(1) << this->height_inches_ << " in" << endl
        << left << setw(20) << " | DOB: " << left << this->date_of_birth_ << endl
        << left << setw(20) << " | Gender: " << left << this->gender_ << endl;
}

bool personType::equals(const personType& other) const {
    // Circuited comparison
    if (this->first_name_ != other.first_name_) {
        return false;
    }

    if (this->last_name_ != other.last_name_) {
        return false;
    }

    if (this->address_ != other.address_) {
        return false;
    }

    if (this->height_inches_ != other.height_inches_)  {
        return false;
    }

    if (this->date_of_birth_ != other.date_of_birth_) {
        return false;
    }

    if (
        static_cast<unsigned char>(tolower(this->gender_)) != // Case insensitive
        static_cast<unsigned char>(tolower(other.gender_))
    ) {
        return false;
    }

    return true;
}

int main() {

    // Init members

    personType p1{
        "Sabrina",
        "Morales",
        "662 S. Southhampton Avenue Vista, CA 92083",
        51.2,
        "24 July 2017",
        'F'
    };

    personType p2{
        "Elle",
        "Macdonald",
        "84 Green Drive Tracy, CA 95376",
        52.3,
        "17 September 2014",
        'F'
    };

    personType p3{
        "Hannah",
        "Finley",
        "8253 Linda Dr. Laguna Niguel, CA 92677",
        49.8,
        "13 September 2012",
        'F'
    };

    personType p4{
        "Arabella",
        "Walter",
        "7593 Wood St. Fountain Valley, CA 92708",
        54.1,
        "27 April 2010",
        'F'
    };

    personType p5{
        "Kye",
        "Baird",
        "8316 Lafayette Ave. North Hills, CA 91343",
        55.8,
        "28 November 2008",
        'F'
    };

    // Stretch 1 (Heading)
    cout << left << setw(10) << setfill('-') << "" << " # personType class # " << left << setw(10) << setfill('-') << "" << endl;

    cout << setfill(' ');

    // Print personType member data

    p1.print(), p2.print(), p3.print(), p4.print(), p5.print();

    // Compare personType members

    cout << boolalpha;
    cout << left << setw(20) << "equals(p1, p2) = " << left << p1.equals(p2) << endl;
    cout << left << setw(20) << "equals(p3, p4) = " << left << p3.equals(p4) << endl;
    cout << left << setw(20) << "equals(p3, p3) = " << left << p3.equals(p3) << endl;
}