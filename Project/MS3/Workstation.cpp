// Name: Gianni Schiralli
// Seneca Student ID: 161166194
// Seneca email: gschiralli@myseneca.ca
// Date of completion: 2021-11-??
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Workstation.h"

namespace sdds {

	std::deque<CustomerOrder> pending, completed, incomplete;

	Workstation::Workstation(std::string& str):Station(str)
	{
	}

	void Workstation::fill(std::ostream& os)
	{
		if (!m_orders.empty())
		{
			m_orders.front().fillItem(*this, os);
		}
	}

	bool Workstation::attemptToMoveOrder()	
	{
		bool moved = false;

		if (!m_orders.empty())
		{
			if (m_orders.front().isItemFilled(getItemName()) || !getQuantity())
			{
				
				if (m_pNextStation)
				{
					*m_pNextStation += std::move(m_orders.front());
					m_orders.pop_front();
				}
				else {

					if (m_orders.front().isFilled())
					{
						completed.push_back(std::move(m_orders.front()));
						m_orders.pop_front();
					}
					else {
						incomplete.push_back(std::move(m_orders.front()));
						m_orders.pop_front();

					}
				}
				moved = true;
			}
		}

		return moved;
	}

	void Workstation::setNextStation(Workstation* station) {

		m_pNextStation = station;

	}

	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}
	void Workstation::display(std::ostream& os) const
	{
		if (m_pNextStation)
		{
			os << getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
		}
		else {
			os << getItemName() << " --> End of line" << std::endl;

		}
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
}