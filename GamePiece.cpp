#include "GamePiece.h"



GamePiece::GamePiece()
{
}

GamePiece::GamePiece(int _number, string _identifier)
{
	//calling methods because checking if valid is done there
    number =_number;
    identifier = _identifier;
}

GamePiece::~GamePiece()
{
	// TO DO
}

//ACCESSORS AND MUTATORS
//----------------------
int GamePiece::getNumber()
{
	//cout << "In GamePiece getNumber method" << endl;
	return number;
}

string GamePiece::getIndentifier()
{
	return identifier;
}
void GamePiece::setNumber(int _number)
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

void GamePiece::setIdentifier(string _identifier)
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


void GamePiece::toString()
{
	cout << "Game piece : " << this->number << " " << this->identifier << endl;
}

bool GamePiece::checkIdentifier(string _identifier)
{
	///how to iterate through vector
     
     
	for (int i = 0; i < tokenNames.size(); i++)
	{
		if (_identifier == tokenNames.at(i))
		{
			return true;
			break;
		}
	}
	
	return false;
}


bool GamePiece::checkNumber(int _number)
{
	return (_number > 0) ? true : false;
}