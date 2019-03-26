#include<iostream>
#include<cstdlib>
#include "City.h"
using namespace std;

City::City() {
	cityNumber = 0;
	cityName = "No Name";
	cityColor = "BLANK";
}

City::City(int cityno, string cn, string cc) {
	cityNumber = cityno;
	cityName = cn;
	cityColor = cc;
	available = true;
}

City::City(int cityno, string cn, string cc, bool a) {
	cityNumber = cityno;
	cityName = cn;
	cityColor = cc;
	available = a;
}

City::~City() {}

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

bool City::isAvailable() {
	return available;
}

void City::setAvailable(bool a) {
	available = a;
}