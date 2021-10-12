//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-10-14
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include "Reservation.h"
namespace sdds {
	class Restaurant
	{
		Reservation* res = nullptr;
		size_t num = 0u;
	public:
		Restaurant(const Reservation* reservations[], size_t cnt);
		~Restaurant();
		Restaurant(const Restaurant&);
		Restaurant(Restaurant&&) noexcept;
		Restaurant& operator=(const Restaurant&);
		Restaurant& operator=(Restaurant&&) noexcept;
		size_t size() const;

		friend std::ostream& operator <<(std::ostream&, const Restaurant&);
	};
}
#endif // !RESTAURANT_H
