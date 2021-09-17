#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Event.h"



size_t g_sysClock = 0;
namespace sdds {
	sdds::Event::Event() :desc{nullptr},time { 0 }
	{
		
	}
	Event::Event(const Event& right)
	{
		operator=(right);
	}
	Event& Event::operator=(const Event& right)
	{
		if (this != &right)
		{
			time = right.time;
			delete[] desc;
			desc = nullptr;
			if (right.desc)
			{
				desc = new char[strlen(right.desc) + 1];
				strcpy(desc, right.desc);

			}


		}
		return *this;
		// TODO: insert return statement here
	}
	void sdds::Event::display() const
	{
		static int counter = 1;
		
		std::cout << std::setw(2) <<std::setfill(' ') << counter <<". ";
		if (!desc) {
			std::cout << "| No event |" << std::endl;
		}
		else {
			std::cout << std::setw(2) << std::setfill('0') << (time / 3600) << ":" << std::setw(2) << (time / 60) % 60 << ":" << std::setw(2) << time % 60 << " => " << desc << std::endl;

		}

		counter++;

	}

	void sdds::Event::set(const char* ch)
	{
		delete[] desc;

		if(ch && ch[0] != '\0')
		{
			desc = new char[strlen(ch) + 1];
			strcpy(desc, ch);
			time = g_sysClock;
			
		}
		else {
			desc = nullptr;
			time = 0;
		}
	}
	Event::~Event()
	{
		delete[] desc;
	}
}