//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-11-08
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Racecar.h"

namespace sdds {





	Racecar::Racecar(std::istream& in):Car(in)
	{
		std::string boosterBonus;

		std::getline(in, boosterBonus, '\n');

		m_booster = std::stod(boosterBonus);



	}

	void Racecar::display(std::ostream& os) const
	{
		Car::display(os);
		os << "*";
	}

	double Racecar::topSpeed() const
	{
		return m_booster ? Car::topSpeed() * (1 + m_booster) : Car::topSpeed();
	}

}