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

	// Still issue with inheritance here ******

    void toString();


private:

	
	
};

