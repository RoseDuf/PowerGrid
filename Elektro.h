#ifndef ELEKTRO_H_
#define ELEKTRO_H_

class Elektro
{
public:
	Elektro();
	Elektro(int _quantity, int _billValue);
	~Elektro();

    //increments number of bills
    void collectElektro(int quantity, int billValue);
    
    //decreases number of bills
    void spendElektros(int quantity, int billValue);
    
    //set number of bills and their value
    void setElektro(int quantity, int billValue);
    
    //setnumber of bills
    int getQuantity();
    
    //set the value of the bill (1$,10$,....)
    int getBillValue();

    //returns total value of money for this elektro object
	int getBalance();
	void toString();

private:
    
    //number of billes
	int quantity;
    
    //is it a 1$, 10$ or 50$ bill?
	int billValue;

};

#endif
