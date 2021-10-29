#include <fstream>
#include <iomanip>
#include "SpellChecker.h"
namespace sdds {

	SpellChecker::SpellChecker(const char* filename) :m_cnt{}
	{
		std::ifstream file(filename);
		if (!file)
		{
			throw "Bad file name!";
		}
		
		size_t cnt = 0u;
		do {
			std::getline(file, m_badWords[cnt], ' ');
			std::getline(file, m_goodWords[cnt], '\n');
			m_badWords[cnt].erase(0, m_badWords[cnt].find_first_not_of(' '));
			m_badWords[cnt].erase(m_badWords[cnt].find_last_not_of(' ') + 1);
			m_goodWords[cnt].erase(0, m_goodWords[cnt].find_first_not_of(' '));
			m_goodWords[cnt].erase(m_goodWords[cnt].find_last_not_of(' ') + 1);
			++cnt;

		} while (file);
		file.close();

	}

	void SpellChecker::operator()(std::string& text)
	{
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