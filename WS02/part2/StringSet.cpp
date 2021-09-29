//Name:Gianni Schiralli
//ID:161166194
//Email:gschiralli@myseneca.ca
//Date: 2021-09-30
#include <iostream>
#include <fstream>
#include <utility>
#include "StringSet.h"

namespace sdds {
	StringSet::StringSet() 
	{

	}
	StringSet::StringSet(const char* str)
	{
		std::string temp;
		std::ifstream fin(str);
		if (fin.is_open())
		{

			while (!fin.eof())
			{
				std::getline(fin, temp, ' ');
				++cnt;
			}

			fin.clear();
			fin.close();
			fin.open(str);
			strings = new std::string[cnt];
			for (auto i = 0; i < cnt; i++)
			{
				std::getline(fin, strings[i], ' ');

			}
			fin.close();
		}

	}
	StringSet::StringSet(const StringSet& cp)
	{
		operator=(cp);
	}
	StringSet::StringSet(StringSet&& src)
	{
		*this = std::move(src);
	}
	StringSet::~StringSet()
	{
		delete[] strings;
	}
	size_t StringSet::size()
	{

		return cnt;
	}
	StringSet& StringSet::operator=(StringSet&& src)
	{
		if (this != &src)
		{
			delete[] strings; 
			strings = src.strings; 
			src.strings = nullptr; 
			
			cnt = src.cnt;

			src.cnt = 0;
		}
		return *this;
		// TODO: insert return statement here
	}
	StringSet& StringSet::operator=(const StringSet& cp)
	{
		if (this != &cp)
		{

			cnt = cp.cnt;

			delete[] strings;

			strings = nullptr;

			if (cp.strings)
			{
				strings = new std::string[cnt];

				for (auto i = 0; i < cnt; i++)
				{
					strings[i] = cp.strings[i];
				}
			}
			
		}
		return *this;
		// TODO: insert return statement here
	}
	std::string StringSet::operator[](size_t num)
	{
		return num < size() ? strings[num] : "";
	}
}