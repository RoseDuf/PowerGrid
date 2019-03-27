#include<iostream>
#include<cstdlib>
#include "City.h"
using namespace std;

City::City() {
	cityNumber = 0;
	cityName = "No Name";
	cityColor = "BLANK";
    powered = false;
}

City::City(int cityno, string cn, string cc) {
	cityNumber = cityno;
	cityName = cn;
	cityColor = cc;
    powered = false;
}

void City::setPoweredState(bool set)
{
    powered = set;
}

bool City::getPoweredState()
{
    return powered;
}

int City::getCityNumber() {
	return cityNumber;
}

void City::setCityNumber(int cityno) {
	cityNumber = cityno;
}

string City::getCityName() {
	return cityName;
}

void City::setCityName(string cn) {
	cityName = cn;
}

string City::getCityColor() {
	return cityColor;
}

void City::setCityColor(string cc) {
	cityColor = cc;
}
