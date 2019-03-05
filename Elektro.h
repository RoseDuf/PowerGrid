#pragma once
class Elektro
{
public:
	Elektro();
	Elektro(int _quantity, int _billValue);
	~Elektro();

    void CollectElektro(int quantity, int billValue);
    void setElektro(int quantity, int billValue);
    int getQuantity();
    int getBillValue();
    /*
     int getQuantity();
	int getBillValue();
	void setQuantity(int _quantity);
	void setBillValue(int _billValue);
*/
	int getBalance();
	void toString();

private:
	int quantity;
	int billValue;

};

