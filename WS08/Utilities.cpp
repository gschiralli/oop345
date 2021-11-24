// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-11-24

#include <memory>
#include <algorithm>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		
		for (auto i = 0u; i < desc.size(); ++i) {
			for (auto j = 0u; j < price.size(); ++j)
			{
				if (desc[i].code == price[j].code) {
					Product* p_prod = new Product(desc[i].desc, price[j].price);
						p_prod->validate();
						priceList += p_prod;
						delete p_prod;
						p_prod = nullptr;
				
				}
			}
		}


		return priceList;
	}
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;

		for (auto i = 0u; i < desc.size(); ++i) {
			for (auto j = 0u; j < price.size(); ++j)
			{
				if (desc[i].code == price[j].code) {
					std::unique_ptr<Product> p_prod(new Product(desc[i].desc, price[j].price));
					p_prod->validate();
					priceList += p_prod;

				}
			}
		}

		return priceList;
	}
}