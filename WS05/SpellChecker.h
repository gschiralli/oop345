//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-11-05
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_SPELL_CHECKER_H
#define SDDS_SPELL_CHECKER_H
#include <string>
namespace sdds {

	const int SIZE = 6;

	class SpellChecker
	{
		std::string m_badWords[SIZE];
		std::string m_goodWords[SIZE];
		size_t m_cnt[SIZE];
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;

	};
}

#endif // !SDDS_SPELL_CHECKER_H
