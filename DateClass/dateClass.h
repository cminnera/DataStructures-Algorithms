// file cDate.h
#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;

class cDate{
	struct tm date;
public:
	cDate(){
		const time_t currentTime = time(0);   // get time now
		int err = localtime_s(&date, &currentTime);
	}
	cDate(struct tm& dt) :date(dt){}
	struct tm& value(){ return date; }
	void operator++(){
		date.tm_mday++;
		mktime(&date);  // Normalize the date
	}
friend
	ostream& operator<<(ostream& os, cDate& dt){
		os << (dt.date.tm_mon + 1) << '/' << dt.date.tm_mday << '/'
			<< (dt.date.tm_year + 1900);
		return os;
	}
};
