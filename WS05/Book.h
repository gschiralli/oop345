//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-10-28
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-11-05
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include<iostream>
#include <string>
namespace sdds {
	
	class Book
	{
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year;
		double m_price;
		std::string m_description;
		void parseFile(std::string& src, std::string& dest, bool end = false);
		void trim(std::string& str);
		
	public:
		Book();
		Book(const std::string& strBook);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		template<typename T>
		void fixSpelling(T& spellChecker);


		friend std::ostream& operator<<(std::ostream& os, const Book& src);
		

	};
	template<typename T>
	inline void Book::fixSpelling(T& spellChecker)
	{
		spellChecker(m_description);
	}
}

#endif // !SDDS_BOOK_H
