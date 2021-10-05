#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H


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
