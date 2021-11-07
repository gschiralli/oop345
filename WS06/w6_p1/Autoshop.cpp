//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-11-08
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Autoshop.h"

namespace sdds {
	Autoshop::~Autoshop()
	{
		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); ++i)
			delete *i;
	}
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(std::ostream& os) const
	{
		os << "--------------------------------\n";
		os << "| Cars in the autoshop!        |\n";
		os << "--------------------------------\n";

		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); ++i)
		{
			(*i)->display(os);
			os << std::endl;
		}
		os << "--------------------------------\n";

	}



}