#ifndef EVENT_H
#define EVENT_H
extern size_t g_sysClock;
namespace sdds {
	
	class Event {
		char desc[120];
		size_t time{ 0 };
	public:
		Event();
		void display()const;
		void set(const char* ch=nullptr);



	};
}


#endif // !EVENT_H
