//Name:Gianni Schiralli
//ID:161166194
//Email:gschiralli@myseneca.ca
//Date: 2021-09-30
#ifndef TIMED_EVENTS_H
#define TIMED_EVENTS_H

#include <iostream>
#include <chrono>
#include <string>

namespace sdds {
	const int MAX = 10;
	class TimedEvents
	{
		int numOfRecs{};
		std::chrono::steady_clock::time_point start{};
		std::chrono::steady_clock::time_point end{};
		struct {
			std::string name{};
			std::string units{};
			std::chrono::steady_clock::duration duration{};
		} event[MAX];
	public:
		void startClock();
		void stopClock();
		void addEvent(const char* m_name);
		friend std::ostream& operator<<(std::ostream& ostr, const TimedEvents& e);

	};
}
#endif // !TIMED_EVENTS_H

