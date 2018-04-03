#include <iostream>
using namespace std;

class Date {
public:
  Date(int y, int m, int d);
  //~Date();

  void nextDay();
  void previousDay();
  bool equal(Date other);
  void show();
private:
  int year;
  int month;
  int day;
};

int main() {
  Date today(2018,3,20);
  Date day(2018,3,20);
  day.show();
  for(int i=0;i<30;i++)
    day.nextDay();
  day.show();
  for(int i=0;i<30;i++)
    day.previousDay();
  day.show();
  if(day.equal(today))
    printf("Very Good!\n");
  else
    printf("Very Bad!\n");
  return 0;
}

Date::Date(int y, int m, int d){
	year = y;
	month = m;
	day = d;
}

void Date::previousDay(){
	if (day == 1){
	        switch(month){
	            case 3:{
	            	month--;
	            	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
						day = 29;
					else 
						day = 28;
	            }
	            case 1:{
	            	day = 31;
	            	month = 12;
	            	year--;
					break;
				}
	            case 2:
	            case 4:
	            case 8:
	            case 9:
	            case 11:{
	                    day = 31;
	                    month--;
	                    break;
	                }
	            case 5:
	            case 7:
	            case 10:
	            case 12:{
	                    day = 30;
	                    month--;
	                    break;
	                }
	        }
	}
	else day--;
}
void Date::nextDay(){
	day++;
	int  leapyear = 0;
	if (day >= 28){
	    if(month == 2 && ((year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0)) leapyear = 1;
	        switch(month){
	            case 2:{
	                if((leapyear == 0 && day == 29) || (leapyear == 1 && day == 30)){
	                    day = 1;
	                    month++;
	                }
	            }
	            case 1:
	            case 3:
	            case 5:
	            case 7:
	            case 8:
	            case 10:
	            case 12:{
	                    if (day == 32){
	                        day = 1;
	                        if(month != 12) month++;
	                        else{
	                            month = 1;
	                            year++;
	                        }
	                    }
	                    break;
	                }
	            case 4:
	            case 6:
	            case 9:
	            case 11:{
	                    if (day == 31){
	                        day = 1;
	                        month++;
	                    }
	                    break;
	                }
	        }
	}
}

	
bool Date::equal(Date other){
	if(day == other.day && month == other.month && year == other.year)
		return true;
	return false;
}
void Date::show() {
  cout<<"日期："<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
}


