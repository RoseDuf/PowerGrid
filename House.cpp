#include "House.h"



House::House()
{
}

House::House(string _identifier, int _num)
{
    number = _num;
    identifier = _identifier;
}

House::~House()
{
	// TO DO
}

//ACCESSORS AND MUTATORS
//----------------------
int House::getNumber()
{
    //cout << "In GamePiece getNumber method" << endl;
    return number;
}

string House::getIndentifier()
{
    return identifier;
}
void House::setNumber(int _number)
{
    if (checkNumber(_number))
    {
        number = _number;
    }
    else
    {
        //cout << "Invalid number." << endl;;
    }
}

void House::setIdentifier(string _identifier)
{
    if (checkIdentifier(_identifier))
    {
        identifier = _identifier;
    }
    else
    {
        //cout << "Invalid identifier." << endl;
    }
}


void House::toString() {
    cout << "House Token : "  << this->identifier << endl;
}



