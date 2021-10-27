//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-10-28
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iomanip>
#include "Book.h"
namespace sdds {
	Book::Book() :m_author{}, m_title{}, m_country{}, m_year{}, m_price{}, m_description{}
	{
	}

	const std::string& Book::title() const
	{
		return m_title;
	}
	const std::string& Book::country() const
	{
		return m_country;
	}
	const size_t& Book::year() const
	{
		return m_year;
	}
	Book::Book(const std::string& strBook):m_author{}, m_title{}, m_country{}, m_year{}, m_price{}, m_description{}
	{
		std::string str = strBook;
		parseFile(str, m_author);
		parseFile(str, m_title);
		parseFile(str, m_country);
		m_price = std::stod(str.substr(0, str.find(',')));
		str.erase(0, str.find(',') + 1);
		m_year = std::stoi(str.substr(0, str.find(',')));
		str.erase(0, str.find(',') + 1);
		parseFile(str, m_description, true);
		trim(m_author);
		trim(m_title);
		trim(m_country);
		trim(m_description);
	}
	double& Book::price()
	{
		return m_price;
	}

	void Book::trim(std::string& str)
	{
		str.erase(0, str.find_first_not_of(' '));
		str.erase(str.find_last_not_of(' ') + 1);
	}

	void Book::parseFile(std::string& src, std::string& dest, bool end)
	{
		if (!end)
		{
			dest = src.substr(0, src.find(','));
			src.erase(0, src.find(',') + 1);
		}
		else {
			dest = src.substr(0);
		}
	}

	std::ostream& operator<<(std::ostream& os, const Book& src)
	{
		os << std::setw(20) << src.m_author << " | ";
		os << std::setw(22) << src.m_title << " | ";
		os << std::setw(5) << src.m_country << " | ";
		os << std::setw(4) << src.m_year << " | ";
		os << std::setw(6) << std::fixed << std::setprecision(2) << src.m_price << " | ";
		os << src.m_description << std::endl;
		return os;

	}

}