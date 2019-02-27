#pragma once
class Elektro
{
public:
	Elektro();
	Elektro(int _quantity, int _billValue);
	~Elektro();

	int getQuantity();
	int getBillValue();
	void setQuantity(int _quantity);
	void setBillValue(int _billValue);

	int getBalance();
	void toString();

private:
	int quantity;
	int billValue;

};

