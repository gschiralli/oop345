//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-10-14
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_CONFIRMATION_SENDER
#define SDDS_CONFIRMATION_SENDER
#include <iostream>
#include "Reservation.h"

namespace sdds {
	class ConfirmationSender
	{
		const Reservation** p_res; 
		int cnt;
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender&);
		ConfirmationSender(ConfirmationSender&&)noexcept;
		~ConfirmationSender();

		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);

		ConfirmationSender& operator=(const ConfirmationSender&);
		ConfirmationSender& operator=(ConfirmationSender&&)noexcept;
		
		friend std::ostream& operator<<(std::ostream& ostr, const ConfirmationSender&);


	};
}

#endif // !SDDS_CONFIRMATION_SENDER
