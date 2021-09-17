#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Event.h"



size_t g_sysClock = 0;
namespace sdds {
	sdds::Event::Event() :time { 0 }
	{
		desc[0] = '\0';
		
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
		

		if(ch && ch[0] != '\0')
		{
			
			strncpy(desc, ch, 120);
			time = g_sysClock;
			
		}
		else {
			desc[0] = '\0';
			time = 0;
		}
	}
	Event::~Event()
	{
		
	}
}