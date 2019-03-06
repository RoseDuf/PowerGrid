#pragma once
#include "GamePiece.h"

class House :
	public GamePiece
{
public:
	House();
	House(string _identifier);
	~House();

    virtual void toString() override;


private:
	
};

