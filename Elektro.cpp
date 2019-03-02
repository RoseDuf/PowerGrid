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

void Elektro::CollectElektro(int _quantity, int _billValue)
{
    quantity+=_quantity;
    billValue = _billValue;
}

void Elektro::setElektro(int _quantity, int _billValue)
{
    quantity = _quantity;
    billValue = _billValue;
}

int Elektro::getQuantity()
{
	return quantity;
}

int Elektro::getBillValue()
{
	return billValue;
}


int Elektro::getBalance()
{
	return this->billValue*this->quantity;
}

void Elektro::toString()
{
	cout << this->quantity << " :: " << this->billValue << " Elektro bills. Total of " << this->getBalance() << " Elektros." << endl;
}
