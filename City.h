#include<iostream>
#include<cstdlib>
using namespace std;

#ifndef CITY_HPP_
#define CITY_HPP_

class City {

public:
	City();
	City(string cityName, string cityColor);
	string getCityName();
	void setCityName(string cityName);
	string getCityColor();
	void setCityColor(string cityColor);

private:
	std::string cityName;
	std::string cityColor;

};

#endif