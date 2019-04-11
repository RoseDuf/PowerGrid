#ifndef CITY_HPP_
#define CITY_HPP_

#include<iostream>
#include<cstdlib>
#include <string>

class City {

public:

    City();
	City(int cityno, std::string cn, std::string cc);
	City(int cityNumber, std::string cityName, std::string cityColor, bool a);
	~City();
	std::string getCityName() const;
	void setCityName(std::string cityName);
	std::string getCityColor();
	void setCityColor(std::string cityColor);
	int getCityNumber() const;
	void setCityNumber(int cityNumber);
	bool isAvailable();
	void setAvailable(bool available);

	void setPoweredState(bool set);
	bool getPoweredState() const;

	//to sort Cities by their number
	static bool compare(const City a, const City b) {
		return a.cityNumber < b.cityNumber;
	}

private:
	int cityNumber;
	std::string cityName;
	std::string cityColor;
	bool available;

	bool powered;
};

#endif
