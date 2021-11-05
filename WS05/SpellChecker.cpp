//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-11-05
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <fstream>
#include <iomanip>
#include <iostream>
#include "SpellChecker.h"
namespace sdds {

	SpellChecker::SpellChecker(const char* filename) :m_cnt{}
	{
		std::ifstream file(filename);
		if (!file)
		{
			throw "Bad file name!";
		}
		
		for(auto i = 0;i < SIZE && file; ++i)
		{
			std::getline(file, m_badWords[i], ' ');
			std::getline(file, m_goodWords[i], '\n');
			m_badWords[i].erase(0, m_badWords[i].find_first_not_of(' '));
			m_badWords[i].erase(m_badWords[i].find_last_not_of(' ') + 1);
			m_goodWords[i].erase(0, m_goodWords[i].find_first_not_of(' '));
			m_goodWords[i].erase(m_goodWords[i].find_last_not_of(' ') + 1);
			
		}

		file.close();

	}

	void SpellChecker::operator()(std::string& text)
	{

		std::cout << "Spellchecker Statistics" << std::endl;
		for (auto i = 0; i < SIZE; ++i)
		{
			while (text.find(m_badWords[i]) != std::string::npos)
			{
				text.replace(text.find(m_badWords[i]), m_badWords[i].size(), m_goodWords[i]);
				++m_cnt[i];
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const
	{
		for (auto i = 0; i < SIZE; ++i)
		{
			out << std::setw(15) << std::right << m_badWords[i] << ": " << m_cnt[i] << " replacements" << std::endl;
		}
	}

}