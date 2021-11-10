// Seneca Student ID: 161166194
// Seneca email: gschiralli@myseneca.ca
// Date of completion: 2021-11-10
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me. 

#ifndef SDDS_CUSTOMER_ORDER
#define SDDS_CUSTOMER_ORDER
#include <string>
#include "Station.h"

namespace sdds {

	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder
	{
		std::string m_name = {};
		std::string m_product = {};
		size_t m_cntItem = {};
		Item** m_lstItem = nullptr;

		static size_t m_widthField;

	public:
		CustomerOrder();
		CustomerOrder(const std::string& str);
		CustomerOrder(const CustomerOrder& src);
		CustomerOrder(CustomerOrder&& src) noexcept;
		~CustomerOrder();
		
		CustomerOrder& operator=(const CustomerOrder&) = delete;
		CustomerOrder& operator=(CustomerOrder&& src) noexcept;

		bool isFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;


	};
}

#endif // !SDDS_CUSTOM_ORDER
