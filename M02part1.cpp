#File-Name: M02part1.cpp
#Author: Ilyas Khamliche
#Date:11/6/2023
#Purpose: allow the user to enter the date between the years of 1900 and 2020
#include <iostream>
#include <stdexcept>

class Date {
private:
    int month;
    int day;
    int year;

public:
    Date(int m, int d, int y) {
        if (m < 1 || m > 12) {
            throw std::invalid_argument("Invalid Value - There are only 12 months in the year");
        }
        if (d < 1 || d > 31) {
            throw std::invalid_argument("Invalid Value - Day must be between 1 and 31");
        }
        if (y < 1900 || y > 2020) {
            throw std::invalid_argument("Invalid Value - Year must be between 1900 and 2020");
        }
        month = m;
        day = d;
        year = y;
    }

    void setMonth(int m) {
        if (m < 1 || m > 12) {
            throw std::invalid_argument("Invalid Value - There are only 12 months in the year");
        }
        month = m;
    }

    void setDay(int d) {
        if (d < 1 || d > 31) {
            throw std::invalid_argument("Invalid Value - Day must be between 1 and 31");
        }
        day = d;
    }

    void setYear(int y) {
        if (y < 1900 || y > 2020) {
            throw std::invalid_argument("Invalid Value - Year must be between 1900 and 2020");
        }
        year = y;
    }

    std::string toString() {
        std::string months[] = {
            "January", "February", "March", "April",
            "May", "June", "July", "August",
            "September", "October", "November", "December"
        };

        return months[month - 1] + " " + std::to_string(day) + ", " + std::to_string(year);
    }
};

int main() {
    int month, day, year;
    try {
        std::cout << "Enter the initial date (month day year): ";
        std::cin >> month >> day >> year;
        Date date(month, day, year);
        std::cout << "Initial Date: " << date.toString() << std::endl;

        std::cout << "Enter a new month: ";
        std::cin >> month;
        date.setMonth(month);

        std::cout << "Enter a new day: ";
        std::cin >> day;
        date.setDay(day);

        std::cout << "Enter a new year: ";
        std::cin >> year;
        date.setYear(year);

        std::cout << "Updated Date: " << date.toString() << std::endl;
    } catch (std::invalid_argument &ex) {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}
