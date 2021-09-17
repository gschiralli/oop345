
#ifndef EVENT_H
#define EVENT_H


extern size_t g_sysClock;

namespace sdds {
	
	class Event {
		char* desc{ nullptr };
		size_t time{ 0 };
	public:
		Event();
		Event(const Event& right);
		Event& operator =(const Event& right);
		void display()const;
		void set(const char* ch=nullptr);
		~Event();


	};
}


#endif // !EVENT_H
