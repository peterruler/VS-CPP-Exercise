#pragma once
#include "Date2.h"
#include "Time.h"
class Meeting {

public: void setDate(int, int, int);

public: void setTime(int, int);

public: int getHour() {
    return t.getHour();
}

public: int getMinutes() {
    return t.getMinutes();
}

public: int getDay() {
    return dt.getDay();
}

public: int getMonth() {
    return dt.getMonth();
}

public: int getYear() {
    return dt.getYear();
}

public: void outputDate() {
    cout << "The Date is: " << getDay() << "." << getMonth() << "." << getYear() << endl;
}

public: void outputTime() {
    cout << "The Time is: " << getHour() << ":" << getMinutes() << endl;
}

private:
	Date2 dt;
    Time t;
};

void Meeting::setDate(int d, int m, int y) {
    dt.set(d, m, y);
    //error dt.month = m;
}

void Meeting::setTime(int hs, int ms) {
    t.set(hs,ms);
}