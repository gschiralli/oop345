//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-10-01
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_SET_SUMMABLE_H
#define SDDS_SET_SUMMABLE_H
#include <string>
#include "Set.h"

namespace sdds {

	template <int N, typename T>
	class SetSummable : public Set<N, T>
	{
	public:
		T accumulate(const std::string & filter) const {

			T acc(filter);
			for (auto i = 0; i < N; i++)
			{
				if (acc.isCompatibleWith(this->get(i)))
				{
					acc += this->get(i);

				}

			}
			return acc;
		
		}




	};













}












#endif // !SDDS_SET_SUMMABLE_H
