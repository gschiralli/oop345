#ifndef EVENT_H
#define EVENT_H

namespace sdds {
	extern size_t g_sysClock;
	class Event {
		char* description{nullptr};
		size_t time{0};
	public:
		Event();
		void display()const;
		void set(const char* )
			


	};
}


#endif // !EVENT_H
