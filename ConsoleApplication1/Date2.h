#pragma once
#ifndef MYDATE2_H
#define MYDATE2_H
class Date2
{
public:
	void set(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}
	int getDay() const {
		return day;
	}
	int getMonth() const {
		return month;
	}
	int getYear() const {
		return year;
	}
	private:
	int day;
	int month;
	int year;
};//don't forget the semicolon
#endif

