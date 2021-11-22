// Name: Gianni Schiralli
// Seneca Student ID: 161166194
// Seneca email: gschiralli@myseneca.ca
// Date of completion: 2021-11-??
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_WORK_STATION_H
#define SDDS_WORK_STATION_H

#include <deque>


#include "Station.h"
#include "CustomerOrder.h"

namespace sdds {

	extern std::deque<CustomerOrder> pending, completed, incomplete;

	class Workstation : public Station
	{
		std::deque<CustomerOrder> m_orders{};
		Workstation* m_pNextStation{};

	public:
		Workstation(std::string& str);

		Workstation(const Workstation&) = delete;
		Workstation(Workstation&&) = delete;

		Workstation& operator=(Workstation&&) = delete;
		Workstation& operator=(const Workstation&) = delete;

		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station = nullptr);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);




	};
}

#endif // !SDDS_WORK_STATION_H
