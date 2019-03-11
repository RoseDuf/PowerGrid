#ifndef RESOURCETOKEN_HPP_
#define RESOURCETOKEN_HPP_
#include "GamePiece.h"


class ResourceToken :
	public GamePiece
{
public:
	ResourceToken();
	ResourceToken(int _number, string _identifier);
	~ResourceToken();

    virtual void toString() override;

private:
	
};
#endif
