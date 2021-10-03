//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-10-01
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
 #ifndef SDDS_PAIR_SUMMABLE_H
#define SDDS_PAIR_SUMMABLE_H
#include <iostream>
#include<string>
#include "Pair.h"

namespace sdds {

	template <typename V, typename K>
	class PairSummable : public Pair<V, K>
	{
		static V inital;
		static size_t width;
	public:
		PairSummable(){}
		PairSummable(const K& key, const V& value = inital):Pair<V,K>(key,value)
		{
			if (key.size() > width)
			{
				width = key.size();
			}
		}
		bool isCompatibleWith(const PairSummable<V,K>& b)
		{
			return this->key() == b.key();
		}

		PairSummable& operator+=(const PairSummable<V,K>& p)
		{
			
			*this = PairSummable(this->key(), this->value() + p.value());
			return *this;

		}
		void display(std::ostream& ostr) const override {
		
			ostr.setf(std::ios::left);
			ostr.width(width);
			Pair<V, K>::display(ostr);
			ostr.unsetf(std::ios::left);
		}
 

	};

	template<typename V, typename K>
	size_t PairSummable<V, K>::width{0};
	
	template<typename V, typename K>
	V PairSummable<V, K>::inital{};

	template<> 
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable& b)
	{
		
		if (this->value() != "") 	*this = PairSummable(this->key(), this->value() + ", " + b.value());
		
		else *this = PairSummable(this->key(), this->value() + b.value());
		
		return *this;
	}
	

	


}



#endif // !SDDS_PAIR_SUMMABLE_H

