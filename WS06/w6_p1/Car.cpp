//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-11-08
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <exception>
#include <iomanip>
#include "Car.h"
namespace sdds {
	void Car::trim(std::string& str)
	{
		str.erase(0, str.find_first_not_of(' '));
		str.erase(str.find_last_not_of(' ') + 1);
	}
	Car::Car() :m_maker{}, m_condition{}, m_topSpeed{}
	{
	}

	Car::Car(std::istream& fin) : m_maker{}, m_condition{}, m_topSpeed{}
	{
		std::string tag, condition, topSpeed;

		std::getline(fin, tag, ',');
		std::getline(fin, m_maker, ',');
		std::getline(fin, condition, ',');
		std::getline(fin, topSpeed, ',');

		trim(tag);
		trim(m_maker);
		trim(condition);
		trim(topSpeed);

		if (condition.empty() || condition[0] == ' ')
			m_condition = 'n';

		else if (condition[0] == 'n' || condition[0] == 'u' || condition[0] == 'b')
			m_condition = condition[0];

		else
			throw "Invalid record!";

		try {
			m_topSpeed = std::stod(topSpeed);
		}
		catch (std::exception& e)
		{
			throw "Invalid record!";
		}
			
		
	}

	std::string Car::condition() const
	{

		if (m_condition == 'n')
			return "new";
		else if (m_condition == 'u')
			return "used";
		else
			return "broken";
	}

	double Car::topSpeed() const
	{
		return m_topSpeed;
	}

	void Car::display(std::ostream& os) const
	{

		os << "| " << std::setw(10) << std::right << m_maker <<" | ";
		os << std::setw(6) << std::left << condition() << " | ";
		os << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |";
		

	}


}