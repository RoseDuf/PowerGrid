#include<iostream>
#include<cstdlib>
using namespace std;

#ifndef CITY_HPP_
#define CITY_HPP_

class City {

public:
	City();
	City(int cityNumber, string cityName, string cityColor);
	int getCityNumber();
	void setCityNumber(string cityNumber);
	string getCityName();
	void setCityName(string cityName);
	string getCityColor();
	void setCityColor(string cityColor);

private:
	int cityNumber;
	std::string cityName;
	std::string cityColor;

};

#endif