#include "Elektro.hpp"
#include <iostream>
using namespace std;

Elektro::Elektro()
{
}

Elektro::Elektro(int _bill1, int _bill10, int _bill50)
{

    bills[0].second = _bill1;
    bills[1].second = _bill10;
    bills[2].second = _bill50;
}

Elektro::~Elektro()
{
	// TO DO
}


void Elektro:: setBillAmount(int _billType, int _billAmount)
{
    if(_billType==1)
    {
         bills[0].second = _billAmount;
        
    }
    else if(_billType==10)
    {
        bills[1].second = _billAmount;;
    }
    else if(_billType==50)
    {
        bills[2].second = _billAmount;;
    }
}

int Elektro::getBillAmmount(int _bill)
{
    if(_bill==1)
    {
        return bills[0].second;
        
    }
    else if(_bill==10)
    {
        return bills[1].second;
    }
    else
    {
        return bills[2].second;
    }
    
}

//adds money income to wallet
void Elektro::addElektros(int _bill1, int _bill10, int _bill50)
{
    bills[0].second += _bill1;
    bills[1].second += _bill10;
    bills[2].second += _bill50;
}

//spends money in wallet
void Elektro::spendElektros(int _bill1, int _bill10, int _bill50)
{
    bills[0].second -= _bill1;
    bills[1].second -= _bill10;
    bills[2].second -= _bill50;
}

int Elektro::getTotalBalance()
{
    int sum = 0;
    for(int i = 0; i < bills.size() ; i++)
    {
        sum+=bills[i].first*bills[i].second;
        
    }
    
    return sum;
}

void Elektro::toString()
{
	cout << "Elektro " << bills[0].first << " : "  << bills[0].second << "\n" <<
    "Elektro " << bills[1].first << " : "  << bills[1].second << "\n" <<
    "Elektro " << bills[2].first << " : "  << bills[2].second
    << "\nTotal of Elektros: " << this->getTotalBalance() << endl;
}

/*#include "ElektroBill.hpp"
#include <iostream>
using namespace std;

ElektroBill::ElektroBill()
{
}

ElektroBill::ElektroBill(int _quantity, int _billValue)
{
	quantity = _quantity;
	billValue = _billValue;
}

ElektroBill::~ElektroBill()
{
	// TO DO
}

void ElektroBill::collectElektroBill(int _quantity, int _billValue)
{
    quantity+=_quantity;
    billValue = _billValue;
}

void ElektroBill::spendElektroBills(int _quantity, int _billValue)
{
    quantity-=_quantity;
    billValue = _billValue;
}

void ElektroBill::setElektroBill(int _quantity, int _billValue)
{
    quantity = _quantity;
    billValue = _billValue;
}

int ElektroBill::getQuantity()
{
	return quantity;
}

int ElektroBill::getBillValue()
{
	return billValue;
}


int ElektroBill::getBalance()
{
	return this->billValue*this->quantity;
}

void ElektroBill::toString()
{
	cout << this->quantity << " :: " << this->billValue << " ElektroBill bills. Total of " << this->getBalance() << " ElektroBills." << endl;
}
*/
