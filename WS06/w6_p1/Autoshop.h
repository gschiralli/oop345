//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-11-08
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_AUTO_SHOP_H
#define SDDS_AUTO_SHOP_H
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {
	class Autoshop
	{
		std::vector <Vehicle* > m_vehicles;
	public:
		~Autoshop();
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& os) const;

		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
		
			for (auto i = m_vehicles.begin(); i != m_vehicles.end(); ++i)
			{
				if (test(*i))
				{
					vehicles.push_back(*i);
				}

			}

		}

	};


}
#endif // !SDDS_AUTO_SHOP_H