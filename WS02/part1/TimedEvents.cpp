//Name:Gianni Schiralli
//ID:161166194
//Email:gschiralli@myseneca.ca
//Date: 2021-09-30
#include <iomanip>
#include "TimedEvents.h"
namespace sdds {
	void TimedEvents::startClock()
	{
		start = std::chrono::steady_clock::now();

	}
	void TimedEvents::stopClock()
	{
		end = std::chrono::steady_clock::now();
		
	}
	void TimedEvents::addEvent(const char* m_name)
	{
		if (numOfRecs < MAX)
		{
			event[numOfRecs].name = m_name;
			event[numOfRecs].units = "nanoseconds";
			event[numOfRecs].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
			++numOfRecs;
		}
		
	}
	std::ostream& operator<<(std::ostream& ostr, const TimedEvents& e)
	{
		ostr << "--------------------------" << std::endl;
		ostr << "Execution Times:" << std::endl;
		ostr << "--------------------------" << std::endl;
		for (auto i = 0; i < e.numOfRecs; i++)
		{
			ostr << std::setw(20) << std::left << e.event[i].name
				<< " " << std::setw(12) << std::right << e.event[i].duration.count()
				<< " " << e.event[i].units << std::endl;
		}
		ostr << "--------------------------" << std::endl;
		return ostr;


		// TODO: insert return statement here
	}
}
