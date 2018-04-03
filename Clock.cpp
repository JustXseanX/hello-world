#include <iostream>
#include <time.h>
#include <iomanip>


using namespace std;

class Clock {
	public:
		Clock();
		//~Clock();
		
		void tick();
		void adjust(int, int, int);
		void show();
	private:
		int h, m, s;
};

int main() {
  Clock ck;
  ck.tick();
  ck.show();
  ck.adjust(16,45,00);
  ck.show();
  return 0;
}

Clock::Clock(){
	time_t timep;
    struct tm *p;
    time(&timep);
    timep += 8 * 3600; //+8h
    p = gmtime(&timep);
    
	h = p->tm_hour;
	m = p->tm_min;
	s = p->tm_sec;
}

void Clock::tick(){
	s++;
	if (s == 60){
		s = 0;
		m++;
		if (m == 60){
			m = 0;
			h++;
			if (h == 24) h = 0;
		}
	}
}

void Clock::adjust(int hour, int minute, int second){
	h = hour;
	m = minute;
	s = second;
}
void Clock::show(){
	cout<<setfill('0')<<"当前时间："<<setw(2)<<h<<":"<<setw(2)<<m<<":"<<setw(2)<<s<<endl;
}

