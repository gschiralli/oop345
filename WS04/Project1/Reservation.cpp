#include "Reservation.h"

namespace sdds {

	Reservation::Reservation()
	{
	}

	void Reservation::update(int day, int time)
	{
		m_day = day;
		m_time = time;

	}

	Reservation::Reservation(const std::string& res)
	{
		std::string val = res;
		std::string id, name, email;


		id = val.substr(0, val.find(':'));
		val.erase(0, val.find(':') + 1);
		
		name = val.substr(0, val.find(','));
		val.erase(0, val.find(',') + 1);
		
		email = val.substr(0, val.find(','));
		val.erase(0, val.find(',') + 1);
		
		this->m_noOfPeople = std::stoi(val.substr(0, val.find(',')));
		val.erase(0, val.find(',') + 1);
	
		this->m_day = std::stoi(val.substr(0, val.find(',')));
		val.erase(0, val.find(',') + 1);

		this->m_time = std::stoi(val.substr(0, val.find(',')));

		id.erase(0, id.find_first_not_of(' '));
		id.erase(id.find_last_not_of(' ') + 1);
		
		name.erase(0, name.find_first_not_of(' '));
		name.erase(name.find_last_not_of(' ') + 1);
		
		email.erase(0, email.find_first_not_of(' '));
		email.erase(email.find_last_not_of(' ') + 1);
		
		this->m_id = id;
		this->m_name = name;
		this->m_email = email;

	}

}