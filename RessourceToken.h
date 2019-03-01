#pragma once
#include "GamePiece.h"
class RessourceToken :
	public GamePiece
{
public:
	RessourceToken();
	RessourceToken(int _number, string _identifier);
	~RessourceToken();

    void toString();

private:
	
};
