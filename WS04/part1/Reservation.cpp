//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-10-14
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iomanip>
#include "Reservation.h"

namespace sdds {

	Reservation::Reservation()
	{
	}

	void Reservation::update(int day, int time)
	{
		this->m_day = day;
		this->m_time = time;

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

	std::ostream& operator<<(std::ostream& ostr, const Reservation& src)
	{
		if (src.m_time >= 6 && src.m_time <= 9)
		{
			ostr << "Reservation " << std::setw(10) << std::right << src.m_id << ": ";
			ostr << std::setw(20) << std::right << src.m_name << " ";
			ostr << std::setw(20) << std::left <<" <" + src.m_email + ">";
			ostr << "    Breakfast on day" << src.m_day << " @ " << src.m_time << ":00 for " << src.m_noOfPeople;
			ostr << (src.m_noOfPeople > 1 ? " people " : " person ") << std::endl;
		}
		else if (src.m_time >= 11 && src.m_time <= 15)
		{
			ostr << "Reservation " << std::setw(10) << std::right << src.m_id << ": "; 
			ostr << std::setw(20) << std::right << src.m_name << " ";
			ostr << std::setw(20) << std::left << " <" + src.m_email + ">";
			ostr << "    Lunch on day" << src.m_day << " @ " << src.m_time << ":00 for " << src.m_noOfPeople;
			ostr << (src.m_noOfPeople > 1 ? " people " : " person ") << std::endl;
		}
		else if (src.m_time >= 17 && src.m_time <= 21)
		{
			ostr << "Reservation " << std::setw(10) << std::right << src.m_id << ": ";
			ostr << std::setw(20) << std::right << src.m_name <<" ";
			ostr << std::setw(20) << std::left << " <" + src.m_email + ">";
			ostr << "    Dinner on day" << src.m_day << " @ " << src.m_time << ":00 for " << src.m_noOfPeople;
			ostr << (src.m_noOfPeople > 1 ? " people " : " person ") << std::endl;
		}
		else {
			ostr << "Reservation " << std::setw(10) << std::right << src.m_id << ": ";
			ostr << std::setw(20) << std::right << src.m_name << " ";
			ostr << std::setw(20) << std::left << " <" + src.m_email + ">";
			ostr << "    Drinks on day" << src.m_day << " @ " << src.m_time << ":00 for " << src.m_noOfPeople;
			ostr << (src.m_noOfPeople > 1 ? " people " : " person ") << std::endl;
		}
		
		return ostr;
		// TODO: insert return statement here
	}

}