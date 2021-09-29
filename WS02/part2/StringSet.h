//Name:Gianni Schiralli
//ID:161166194
//Email:gschiralli@myseneca.ca
//Date: 2021-09-30
#ifndef STRING_SET_H
#define STRING_SET_H
#include <string>

namespace sdds {
	class StringSet
	{
		std::string* strings{ nullptr };
		int cnt{ 0 };
	public:
		StringSet();
		StringSet(const char* str);
		StringSet(const StringSet&);
		StringSet(StringSet&&);
		~StringSet();
		size_t size();
		StringSet& operator=(StringSet&&);
		StringSet& operator=(const StringSet&);
		std::string operator[](size_t num);

	};
}

#endif // !STRING_SET_H

