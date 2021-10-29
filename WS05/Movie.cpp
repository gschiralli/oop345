#include <iomanip>
#include "Movie.h"
namespace sdds {
	Movie::Movie(): m_title{},m_year{},m_description{}
	{
	}
	Movie::Movie(const std::string& strMovie): m_title{}, m_year{}, m_description{}
	{
		std::string data = strMovie;
		m_title = data.substr(0, data.find(','));
		data.erase(0, data.find(',') + 1);
		m_year = std::stoi(data.substr(0, data.find(',')));
		data.erase(0, data.find(',') + 1);
		m_description = data.substr(0);

		m_title.erase(0, m_title.find_first_not_of(' '));
		m_title.erase(m_title.find_last_not_of(' ') + 1);

		m_description.erase(0, m_description.find_first_not_of(' '));
		m_description.erase(m_description.find_last_not_of(' ') + 1);

	}
	const std::string& Movie::title() const
	{
		return m_title;
	}
	std::ostream& operator<<(std::ostream& os, const Movie& m)
	{
		os << std::setw(40) << m.m_title << " | ";
		os << std::setw(4) << m.m_year << " | ";
		os << m.m_description << std::endl;
		return os;
	}
}