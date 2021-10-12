//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-10-14
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include<iostream>
#include<utility>
#include "ConfirmationSender.h"

namespace sdds {

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool flag = false;

		for (auto i = 0; i < cnt; ++i)
		{
			if (this->p_res[i] == &res)
			{
				flag = true;
			}
		}

		if (!flag)
		{
			const Reservation** tmp{};
			tmp = new const Reservation * [cnt + 1];


			for (auto i = 0; i < cnt; ++i)
			{
				tmp[i] = this->p_res[i];
			}

			tmp[cnt] = &res;
			++cnt;
			delete[] this->p_res;
			this->p_res = tmp;

		}
		return *this;


	
	}

	ConfirmationSender::ConfirmationSender() :p_res{ nullptr }, cnt{0}
	{
	}


	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		bool flag = false;
		int idx = 0;
		for (auto i = 0; i < cnt; ++i)
		{
			if (this->p_res[i] == &res)
			{
				idx = i;
				flag = true;
				this->p_res[i] = nullptr;
			}
		}

		if (flag)
		{
			const Reservation** tmp{};
			int j = 0;

			--cnt;

			tmp = new const Reservation * [cnt];

			

			for (auto i = 0; i < cnt; ++i) {

				if (i == idx)
				{
					++j;

				}
					tmp[i] = this->p_res[j];
					++j;
				
			}
			delete[] this->p_res;
			this->p_res = tmp;

		}
		return *this;

	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src)
	{
		*this = src;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) noexcept
	{
		*this = std::move(src);
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src)
	{
		if (this != &src)
		{
			this->cnt = src.cnt;
			delete[] p_res;
			this->p_res = { nullptr };
			if (src.p_res)
			{
				this->p_res = new const Reservation * [cnt];

				for (auto i = 0; i < cnt; ++i)
				{
					this->p_res[i] = src.p_res[i];
				}

			}

		}
		return *this;
		
	}

	ConfirmationSender::~ConfirmationSender()
	{
		delete[] p_res;
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) noexcept
	{
		if (this != &src)
		{
			delete[] p_res;
			this->p_res = src.p_res;
			src.p_res = nullptr;
			this->cnt = src.cnt;
			src.cnt = { 0 };
		}
		return *this;
	}

	

	

	std::ostream& operator<<(std::ostream& ostr, const ConfirmationSender& src)
	{
		ostr << "--------------------------" << std::endl;
		ostr << "Confirmations to Send" << std::endl;
		ostr << "--------------------------" << std::endl;
		if (src.cnt)
		{
			for (auto i = 0; i < src.cnt; ++i)
			{
				ostr << *src.p_res[i];
			}
		}
		else {
			ostr << "There are no confirmations to send!" << std::endl;
		}
		ostr << "--------------------------" << std::endl;


		return ostr;

	}

}