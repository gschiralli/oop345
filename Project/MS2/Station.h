// Seneca Student ID: 161166194
// Seneca email: gschiralli@myseneca.ca
// Date of completion: 2021-11-08
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me. 

#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include<string>
#include <iostream>
namespace sdds {

	class Station
	{
		int m_id;
		std::string m_name;
		std::string m_description;
		size_t m_nextNum;
		size_t m_noStock;

		static size_t m_widthField;
		static int id_generator;

	public:
		Station(const std::string&);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;

	};
}
#endif // !SDDS_STATION_H
