//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-11-05
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <string>
#include <iostream>
namespace sdds
{
	class Movie
	{
		std::string m_title;
		size_t m_year;
		std::string m_description;
	public:
		Movie();
		Movie(const std::string& strMovie);
		const std::string& title() const;
		template<typename T>
		void fixSpelling(T& spellChecker);

		friend std::ostream& operator <<(std::ostream&, const Movie&);
	};

	template<typename T>
	inline void Movie::fixSpelling(T& spellChecker)
	{
		spellChecker(m_title);
		spellChecker(m_description);
	}

}
#endif // !SDDS_MOVIE_H
