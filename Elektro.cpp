#include "Elektro.h"
#include <iostream>
using namespace std;

Elektro::Elektro()
{
}

Elektro::Elektro(int _quantity, int _billValue)
{
	quantity = _quantity;
	billValue = _billValue;
}

Elektro::~Elektro()
{
	// TO DO
}

int Elektro::getQuantity()
{
	return quantity;
}

int Elektro::getBillValue()
{
	return billValue;
}

void Elektro::setQuantity(int _quantity)
{
	quantity = _quantity;
}

void Elektro::setBillValue(int _billValue)
{
	billValue = _billValue;
}

int Elektro::getBalance()
{
	return this->billValue*this->quantity;
}

void Elektro::toString()
{
	cout << this->quantity << " :: " << this->billValue << " Elektro bills. Total of " << this->getBalance() << " Elektros." << endl;
}
