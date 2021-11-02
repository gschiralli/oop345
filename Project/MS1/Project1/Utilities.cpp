// Name: Gianni Schiralli
// Seneca Student ID: 161166194
// Seneca email: gschiralli@myseneca.ca
// Date of completion: 
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <algorithm>
#include "Utilities.h"

namespace sdds {

	
	char Utilities::m_delimiter = ' ';

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		
		size_t found = str.find(Utilities::m_delimiter, next_pos);
		std::string token = str.substr(next_pos, found - next_pos);

		if (found == next_pos)
		{
			more = false;
			throw "ERROR! No token.";
		}
		else if(found == std::string::npos) {
			more = false;
		}
		else {
			more = true;
			next_pos = ++found;
		}
		m_widthField = std::max(token.size(), m_widthField);

		return token;

	}

	void Utilities::setDelimiter(char newDelimitier)
	{
		Utilities::m_delimiter = newDelimitier;
	}

	char Utilities::getDelimiter()
	{
		return Utilities::m_delimiter;
	}

}