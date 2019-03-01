#pragma once
#include "GamePiece.h"
#include <vector>

class House :
	public GamePiece
{
public:
	House();
	House(string _identifier);
	~House();

    void toString();


private:
	
};

