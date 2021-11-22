//Name: Gianni Schiralli
// Seneca Student ID: 161166194
// Seneca email: gschiralli@myseneca.ca
// Date of completion: 2021-11-08
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me. 

#include <iomanip>
#include "Station.h"
#include "Utilities.h"

namespace sdds {

	size_t Station::m_widthField = 0u;
	int Station::id_generator = 0;

	Station::Station(const std::string& str)
	{
		m_id = ++Station::id_generator;
		Utilities util;
		size_t next_pos = 0u;
		bool more{};

		try {
			m_name = util.extractToken(str, next_pos, more);
			m_nextNum = std::stoi(util.extractToken(str, next_pos, more));
			m_noStock = std::stoi(util.extractToken(str, next_pos, more));
			Station::m_widthField = std::max(Station::m_widthField, util.getFieldWidth());
			m_description = util.extractToken(str, next_pos, more);
		}
		catch (const char* err)
		{
			std::cout << err << std::endl;
		}

	}

	const std::string& Station::getItemName() const
	{
		return m_name;
	}

	size_t Station::getNextSerialNumber()
	{
		return m_nextNum++;
	}

	size_t Station::getQuantity() const
	{
		return m_noStock;
	}

	void Station::updateQuantity()
	{
		if (m_noStock > 0u)
			--m_noStock;
	}

	void Station::display(std::ostream& os, bool full) const
	{
	
			os << "[" <<std::setfill('0')<< std::setw(3) << std::right << m_id << "] ";
			os << "Item: " << std::setfill(' ') << std::left << std::setw(Station::m_widthField) << m_name;
			os << " [" << std::setfill('0') << std::setw(6) << std::right << m_nextNum << "]";
		
		if(full) {
			os << " Quantity: " << std::setfill(' ') << std::setw(Station::m_widthField) << std::left <<m_noStock;
			os << " Description: " << m_description;
		}

		os << std::endl;

	}

}