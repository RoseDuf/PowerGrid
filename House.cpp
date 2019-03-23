#include "House.h"


House::House()
{
}

House::House(int _number, string _identifier)
{
    //calling methods because checking if valid is done there
    number =_number;
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
    //cout << "In House getNumber method" << endl;
    return number;
}

string House::getIndentifier()
{
    return identifier;
}

void House::setNumber(int _number)
{
    number = _number;
}

void House::setIdentifier(string _identifier)
{
    
        identifier = _identifier;
}


void House::toString() {
    cout << "House Token : "  << this->identifier << endl;
}



