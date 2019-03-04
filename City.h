
#ifndef CITY_HPP_
#define CITY_HPP_

#include<iostream>
#include<cstdlib>

class City {

public:
	City();
	City(std::string cityName, std::string cityColor);
	std::string getCityName();
	void setCityName(std::string cityName);
	std::string getCityColor();
    void setCityColor(std::string cityColor);

private:
	std::string cityName;
	std::string cityColor;

};

#endif
