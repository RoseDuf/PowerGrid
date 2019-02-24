#include<iostream>
#include<cstdlib>
#include "City.h"
using namespace std;

City::City() {
	cityName = "No Name";
	cityColor = "BLANK";
}

City::City(string cn, string cc) {
	cityName = cn;
	cityColor = cc;
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