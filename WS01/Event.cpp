#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Event.h"



size_t g_sysClock = 0;
namespace sdds {
	sdds::Event::Event() :time{0}
	{
		desc[0] = '\0';
	}
	void sdds::Event::display() const
	{
		static int counter = 1;
		int hh, mm, ss = 0;
		hh = time / 3600;
		mm = (time / 60) % 60;
		ss = time % 60;
		if (desc[0] == '\0')
		{
			std::cout.width(2);
			std::cout << counter;
			std::cout << ". | No event |" << std::endl;

		}
		else {
			std::cout.width(2);
			std::cout << counter;
			std::cout<< ". ";
			std::cout.width(2);
			std::cout.fill(0);
			std::cout << hh << ":";
			std::cout.width(2);
			std::cout.fill(0);
			std::cout << mm << ":";
			std::cout.width(2);
			std::cout.fill(0);
			std::cout << ss << "=> " << desc << std::endl;

		}

		counter++;

	}

	void sdds::Event::set(const char* ch)
	{
		if (ch) {
			strncpy(desc, ch, 120);
		}
		else
		{
			time = 0;
			desc[0] = '\0';
		}
	}
}