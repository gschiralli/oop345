// Seneca Student ID: 161166194
// Seneca email: gschiralli@myseneca.ca
// Date of completion: 2021-11-10
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me. 

#include <utility>
#include <algorithm>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"
namespace sdds {

	size_t CustomerOrder::m_widthField = 0u;

	CustomerOrder::CustomerOrder() :m_name{}, m_product{}, m_cntItem{}, m_lstItem{}
	{
	}

	CustomerOrder::CustomerOrder(const std::string& str) : m_name{}, m_product{}, m_cntItem{}, m_lstItem{}
	{
		Utilities util;

		size_t next_pos{ 0u };
		bool more{ true };

		m_name = util.extractToken(str, next_pos, more);
		m_product = util.extractToken(str, next_pos, more);

		//Get current position of where to start for items
		size_t curr_pos = next_pos;

		//Count how many items
		while (more)
		{
			util.extractToken(str, next_pos, more);
			++m_cntItem;
		}

		m_lstItem = new Item * [m_cntItem];

		more = true;
		
		for (auto i = 0u; i < m_cntItem; ++i) {
			m_lstItem[i] = new Item(util.extractToken(str, curr_pos, more));
		}

		CustomerOrder::m_widthField = std::max(CustomerOrder::m_widthField, util.getFieldWidth());

	}

	CustomerOrder::CustomerOrder(const CustomerOrder& src)
	{
		throw "ERROR: Cannot make copies";
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
	{
		*this = std::move(src);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
	{
		if (this != &src)
		{
			if (m_lstItem) {
				for (auto i = 0u; i < m_cntItem; ++i)
					delete m_lstItem[i];
			}

			delete[] m_lstItem;

			m_lstItem = src.m_lstItem;
			src.m_lstItem = nullptr;

			m_name = src.m_name;
			m_product = src.m_product;
			m_cntItem = src.m_cntItem;

			src.m_name = {};
			src.m_product = {};
			src.m_cntItem = {};
		}
		return *this;
	}

	bool CustomerOrder::isFilled() const
	{
		bool res = std::all_of(m_lstItem, m_lstItem + m_cntItem, [](const Item* item) {
			return item->m_isFilled;
			});
		
		return res;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool res{true};
		std::for_each(m_lstItem, m_lstItem + m_cntItem, [itemName, &res](const Item* item) {

			if (item->m_itemName == itemName && !item->m_isFilled)
				res = false;
			});

		return res;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		for (auto i = 0u; i < m_cntItem; ++i)
		{
			if (station.getItemName() == m_lstItem[i]->m_itemName)
			{

				if (station.getQuantity() > 0)
				{
					station.updateQuantity();
					
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;

					os  << std::right << "    Filled " << m_name <<", " << m_product <<" [" << station.getItemName() <<"]" << std::endl;
				}
				else {
					os << std::right << "     Unable to fill " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << std::endl;

				}

			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << std::endl;
			
		for (auto i = 0u; i < m_cntItem; ++i)
		{
			os << "[" << std::setw(6) << std::right << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
			os << std::setw(CustomerOrder::m_widthField) << std::left << std::setfill(' ') << m_lstItem[i]->m_itemName << " - ";
			os << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;

		}
	}

	CustomerOrder::~CustomerOrder()
	{
		for (auto i = 0u; i < m_cntItem; ++i)
			delete m_lstItem[i];

		delete[] m_lstItem;
	}





}