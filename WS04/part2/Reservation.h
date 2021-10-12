//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-10-14
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <string>

namespace sdds {
	
	class Reservation
	{
		std::string m_id{};
		std::string m_name{};
		std::string m_email{};
		int m_noOfPeople{};
		unsigned int m_day{};
		unsigned int m_time{};
	public:
		Reservation();
		void update(int day, int time);
		Reservation(const std::string& res);

		friend std::ostream& operator <<(std::ostream& , const Reservation&);



	};
}
#endif // !SDDS_RESERVATION_H
