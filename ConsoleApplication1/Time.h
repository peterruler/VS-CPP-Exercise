#pragma once
class Time {
public: void set(int hs, int ms) {
	hours = hs;
	minutes = ms;
}
	  int getHour() const {
		  return hours;
	  }
	  int getMinutes() const {
		  return minutes;
	  }
private:
	int hours;
	int minutes;
};