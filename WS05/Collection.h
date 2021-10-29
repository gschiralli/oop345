#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <string>
#include <stdexcept>
namespace sdds {
	template <typename T>
	class Collection {
		std::string m_name;
		T* m_items;
		size_t m_size;
		void(*p_func)(const Collection<T>&, const T&);
	public:
		Collection(const std::string& name) :m_name{ name }, m_items{}, m_size{}, p_func{} {}
		Collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;
		const std::string& name() const {
			return m_name; 
		}
		size_t size() const { 
			return m_size; 
		}
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			p_func = observer;
		}

		Collection<T>& operator+=(const T& item){
			
			for (auto i = 0u; i < m_size; ++i)
			{
				if (m_items[i].title() == item.title())
				{
					return *this;
				}
			}

			 T* arr = new T[m_size + 1];

			for (auto i = 0u; i < m_size; ++i)
			{
				arr[i] = m_items[i];

			}

			arr[m_size] = item;
			delete[] m_items;
			m_items = arr;
			++m_size;

			if (p_func)
			{
				p_func(*this, item);
			}

			return *this;

		}

		T& operator[](size_t idx) const {

			if (idx >= m_size)
			{
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");

			}

			return m_items[idx];
		}

		T* operator[](const std::string& title) const {

			for (auto i = 0u; i < m_size; ++i)
			{
				if (m_items[i].title() == title)
				{
					return &m_items[i];
				}
			}

			return nullptr;
		}

	};


	template<typename T>
	std::ostream& operator <<(std::ostream& os, const Collection<T>& src)
	{
		for (auto i = 0u; i < src.size(); ++i)
		{
			os << src[i];
		}

		return os;
	}




}





#endif // !SDDS_COLLECTION_H

