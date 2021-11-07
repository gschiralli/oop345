//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-11-08
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_RACE_CAR_H
#define SDDS_RACE_CAR_H

#include "Car.h"

namespace sdds {
    class Racecar :
        public Car
    {
        double m_booster;
    public:
        Racecar(std::istream& in);
        void display(std::ostream& os)const override;
        double topSpeed() const override;


    };
}

#endif // !SDDS_RACE_CAR_H