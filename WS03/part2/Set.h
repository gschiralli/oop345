//Name: Gianni Schiralli
//ID: 161166194
//Email: gschiralli@myseneca.ca
//Date: 2021-10-01
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_SET_H
#define SDDS_SET_H


namespace sdds {

	template <int N, typename T>
	class Set {

		T arr[N];
		size_t count{0};
	public:
		size_t size() const {
			return count;
		}
		const T& get(size_t idx) const {
			return arr[idx];
		}
		void operator +=(const T& item){
			if (count < N)
			{
				arr[count] = item;
				++count;
			}
		}

	};


}
#endif // !SDDS_SET_H
