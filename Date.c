#include<stdio.h>

struct Date {
  int year;
  int month;
  int day;
};
void previous_day(struct Date *day){
	if ((*day).day == 1){
	        switch((*day).month){
	            case 3:{
	            	(*day).month--;
	            	if(((*day).year % 4 == 0 && (*day).year % 100 != 0) || (*day).year % 400 == 0)
						(*day).day = 29;
					else 
						(*day).day = 28;
	            }
	            case 1:{
	            	(*day).day = 31;
	            	(*day).month = 12;
	            	(*day).year--;
					break;
				}
	            case 2:
	            case 4:
	            case 8:
	            case 9:
	            case 11:{
	                    (*day).day = 31;
	                    (*day).month--;
	                    break;
	                }
	            case 5:
	            case 7:
	            case 10:
	            case 12:{
	                    (*day).day = 30;
	                    (*day).month--;
	                    break;
	                }
	        }
	}
	else (*day).day--;
}
void next_day(struct Date *day){
	(*day).day++;
	int  leapyear = 0;
	if ((*day).day >= 28){
	    if((*day).month == 2 && (((*day).year % 4 == 0 && (*day).year % 100 != 0 ) || (*day).year % 400 == 0)) leapyear = 1;
	        switch((*day).month){
	            case 2:{
	                if((leapyear == 0 && (*day).day == 29) || (leapyear == 1 && (*day).day == 30)){
	                    (*day).day = 1;
	                    (*day).month++;
	                }
	            }
	            case 1:
	            case 3:
	            case 5:
	            case 7:
	            case 8:
	            case 10:
	            case 12:{
	                    if ((*day).day == 32){
	                        (*day).day = 1;
	                        if((*day).month != 12) (*day).month++;
	                        else{
	                            (*day).month = 1;
	                            (*day).year++;
	                        }
	                    }
	                    break;
	                }
	            case 4:
	            case 6:
	            case 9:
	            case 11:{
	                    if ((*day).day == 31){
	                        (*day).day = 1;
	                        (*day).month++;
	                    }
	                    break;
	                }
	        }
	}
}
int equal(struct Date one, struct Date day){
	if(one.day == day.day && one.month == day.month && one.year == day.year)
		return 1;
	return 0;
}
void show(struct Date day) {
  printf("日期：%d年%d月%d日\n", day.year, day.month, day.day);
}
int main() {
  struct Date today = {2018,3,20};
  struct Date day = {2018,3,20};
  show(day);
  for(int i=0;i<30;i++)
    next_day(&day);
  show(day);
  for(int i=0;i<30;i++)
    previous_day(&day);
  show(day);
  if(equal(today, day))
    printf("Very Good!\n");
  else
    printf("Very Bad!\n");
  return 0;
}
