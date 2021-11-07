//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-11-08
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <string>
#include "Vehicle.h"

namespace sdds{

class Car :   public Vehicle{



		std::string m_maker;
		char m_condition;
		double m_topSpeed;
		void trim(std::string& str);

	public:
		Car();
		Car(std::istream& fin);
		std::string condition() const override;
		double topSpeed() const override;
		void display(std::ostream& os) const override;

};

}

#endif // !SDDS_CAR_H

