#ifndef CITY_HPP_
#define CITY_HPP_

#include<iostream>
#include<cstdlib>
#include <string>

class City {

public:

    City();
	City(int cityNumber, std::string cityName, std::string cityColor);
	City(std::string cityName, std::string cityColor);
	std::string getCityName();
	void setCityName(std::string cityName);
	std::string getCityColor();
	void setCityColor(std::string cityColor);
	int getCityNumber();
	void setCityNumber(int cityNumber);
    
    void setPoweredState(bool set);
    bool getPoweredState();

private:
	int cityNumber;
	std::string cityName;
	std::string cityColor;
    
    bool powered;
};

#endif