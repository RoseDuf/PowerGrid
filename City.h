
#ifndef CITY_HPP_
#define CITY_HPP_

#include<iostream>
#include<cstdlib>

class City {

public:
	City(int cityNumber, std::string cityName, string cityColor);
	City(std::string cityName, std::string cityColor);
	std::string getCityName();
	void setCityName(std::string cityName);
	std::string getCityColor();
    void setCityColor(std::string cityColor);	
	int getCityNumber();
	void setCityNumber(std::string cityNumber);

private:
	int cityNumber;
	std::string cityName;
	std::string cityColor;

};

#endif
