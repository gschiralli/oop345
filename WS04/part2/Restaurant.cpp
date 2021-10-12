//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-10-14
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <utility>
#include "Restaurant.h"
namespace sdds {
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) :num{ cnt }
	{
		this->res = new Reservation[cnt];

		for (size_t i = 0; i < cnt; ++i) 
		{
		
			this->res[i] = *reservations[i];
		}

		
	}

	Restaurant::~Restaurant()
	{
		delete[] res;
	}

	Restaurant::Restaurant(const Restaurant& src)
	{
		*this = src;
	}

	Restaurant::Restaurant(Restaurant&& src) noexcept
	{
		*this = std::move(src);
	}

	Restaurant& Restaurant::operator=(const Restaurant& src)
	{
		if (this != &src)
		{
			this->num = src.num;
			delete[] res;
			this->res = nullptr;
			if (src.res){
				this->res = new Reservation[num];
				for (size_t i = 0; i < num; ++i)
				{
					this->res[i] = src.res[i];

				}

			}

		}
		return *this;
		
	}

	Restaurant& Restaurant::operator=(Restaurant&& src) noexcept
	{
		if (this != &src)
		{
			delete[] res;
			this->res = src.res;
			this->num = src.num;
			src.res = nullptr;
			src.num = 0;

		}
		return *this;
		
	}

	size_t Restaurant::size() const
	{
		return num;
	}
	std::ostream& operator<<(std::ostream& ostr, const Restaurant& src)
	{
		static size_t cnt = 0;

		ostr << "--------------------------" << std::endl;
		ostr << "Fancy restaurant " << "(" << ++cnt << ")" << std::endl;
		ostr << "--------------------------" << std::endl;

		if (src.res)
		{
			for(size_t i = 0; i < src.size();++i)
			ostr << src.res[i];
		}
		else {
			ostr << "This restaraunt is empty!" << std::endl;
		}
		ostr << "--------------------------" << std::endl;

		return ostr;

		// TODO: insert return statement here
	}
}