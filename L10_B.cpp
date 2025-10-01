/*
    Programmer: Ryan Posey
    Assignment: L10.B
    Purpose: Practice using getters & setters
    Due date: 9/30/2025
*/

#include <iostream>
#include <iomanip>
#include <cstdint>

using namespace std;

class personType { 
        std::string first_name_;
        std::string last_name_;
        std::string address_;
        double height_inches_{};
        std::string date_of_birth_;  
        char gender_{}; 
        uint8_t age_;

    public:

        void print() const;
        bool equals(const personType& other) const;

        // Setters

        void setFirstName(string firstName) {
            first_name_ = firstName;
        }

        void setLastName(string lastName) {
            last_name_ = lastName;
        }

        void setAddress(string address) {
            address_ = address;
        }

        void setHeight(double height) {
            if (height < 0 || height > 120) {
                height = 0;
            }

            height_inches_ = height;
        }

        void setDOB(string DOB) {
            date_of_birth_ = DOB;
        }

        void setGender(char gender) {
            gender_ = gender;
        }

        void setAge(uint8_t age) {
            if (age < 0 || age > 999) {
                age = 0;
            }

            age_ = age;
        }

        // Getters

        string getFirstName() const { return first_name_; }
        string getLastName() const { return last_name_; }
        string getAddress() const { return address_; }
        double getHeight() const { return height_inches_; }
        string getDOB() const { return date_of_birth_; }
        char getGender() const { return gender_; }
        uint8_t getAge() const { return age_; }
};

void personType::print() const { // Stretch 2 (Formatted output)
    std::cout <<  left << setw(20) << " | Name: " << left << this->getFirstName() << " " << this->getLastName() << endl
        << left << setw(20) << " | Address: " << left << this->getAddress() << endl
        << left << setw(20) << " | Height: " << left << std::fixed << std::setprecision(1) << this->getHeight() << " in" << endl
        << left << setw(20) << " | DOB: " << left << this->getDOB() << endl
        << left << setw(20) << " | Gender: " << left << this->getGender() << endl;
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

    personType p1{};

    p1.setFirstName("Sabrina");
    p1.setLastName("Morales");
    p1.setAddress("662 S. Southhampton Avenue Vista, CA 92083");
    p1.setHeight(51.2);
    p1.setDOB("24 July 2017");
    p1.setGender('F');
    p1.setAge(20);

    personType p2{};

    p2.setFirstName("Elle");
    p2.setLastName("Macdonald");
    p2.setAddress("84 Green Drive Tracy, CA 95376");
    p2.setHeight(52.3);
    p2.setDOB("17 September 2014");
    p2.setGender('F');
    p2.setAge(20);

    personType p3{};

    p3.setFirstName("Hannah");
    p3.setLastName("Finley");
    p3.setAddress("8253 Linda Dr. Laguna Niguel, CA 92677");
    p3.setHeight(49.8);
    p3.setDOB("13 September 2012");
    p3.setGender('F');
    p3.setAge(20);

    personType p4{};

    p4.setFirstName("Arabella");
    p4.setLastName("Walter");
    p4.setAddress("7593 Wood St. Fountain Valley, CA 92708");
    p4.setHeight(54.1);
    p4.setDOB("27 April 2010");
    p4.setGender('F');
    p4.setAge(20);

    personType p5{};

    p5.setFirstName("Kye");
    p5.setLastName("Baird");
    p5.setAddress("8316 Lafayette Ave. North Hills, CA 91343");
    p5.setHeight(55.8);
    p5.setDOB("28 November 2008");
    p5.setGender('F');
    p5.setAge(20);

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