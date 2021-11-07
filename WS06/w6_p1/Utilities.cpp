//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-11-08
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"
namespace sdds {


	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* p_vehicle = nullptr;

		std::string str;

		std::stringstream ss;

		std::getline(in, str);

		str.erase(0, str.find_first_not_of(' '));
		
		ss << str;

		if (!str.empty())
		{
			if (str[0] == 'c' || str[0] == 'C') {
				p_vehicle = new Car(ss);
				return p_vehicle;
			}
			else if (str[0] == 'r' || str[0] == 'R')
			{
				p_vehicle = new Racecar(ss);
				return p_vehicle;
			}
			else {
				std::string err = "Unrecognized record type: [";
				err += str[0];
				err += ']';
				throw err;

			}
		}
		return p_vehicle;
	}

}