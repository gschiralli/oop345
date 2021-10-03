//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-10-01
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include<iostream>

namespace sdds {

	template<typename V, typename K>

	class Pair {
		V m_value;
		K m_key;
	public:
		Pair() :m_value{}, m_key{} {

		};
		Pair(const K& key, const V& value)
		{
			m_key = key;
			m_value = value;
		}
		const V& value() const {
			return m_value;
		}
		
		const K& key() const {
			return m_key;
		}
		
		virtual void display(std::ostream& ostr) const {

			ostr << m_key << " : " << m_value << std::endl;
		}
	
	};

	template<typename V, typename K>
	std::ostream& operator<<(std::ostream& ostr, const Pair<V, K>& pair) {
		pair.display(ostr);
		return ostr;

	}




}


#endif // !SDDS_PAIR_H

