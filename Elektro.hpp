#ifndef ELEKTRO_H_
#define ELEKTRO_H_
#include <vector>

using namespace std;

class Elektro
{
public:
	Elektro();
	Elektro(int _bill1, int _bill10, int _bill50);
    

	~Elektro();

    //sets the numbers of 1$,10$ and 50$ (= _billType) to _billNum value
    void setBillAmount(int _billType, int _billNum);
    
    //gets the numbers of bills of type _bill (1$, 10$ or 50$)
    int getBillAmmount(int _bill);

    //adds money to wallet
    void addElektros(int _bill1, int _bill10, int _bill50);
    
    void spendElektros(int _bill1, int _bill10, int _bill50);
	
    //returns total value of money for this elektro object
    int getTotalBalance();
    
    
    void toString();

private:
    
    std::vector< std::pair<int,int> > bills =  { {1,0},
                                                {10,0},
                                                {50,0} };
    
};

#endif

/*#ifndef ELEKTROBILL_H_
#define ELEKTROBILL_H_

class ElektroBill
{
public:
	ElektroBill();
	ElektroBill(int _quantity, int _billValue);
	~ElektroBill();

    //increments number of bills
    void collectElektroBill(int quantity, int billValue);
    
    //decreases number of bills
    void spendElektroBills(int quantity, int billValue);
    
    //set number of bills and their value
    void setElektroBill(int quantity, int billValue);
    
    //setnumber of bills
    int getQuantity();
    
    //set the value of the bill (1$,10$,....)
    int getBillValue();

    //returns total value of money for this ElektroBill object
	int getBalance();
	void toString();

private:
    
    //number of billes
	int quantity;
    
    //is it a 1$, 10$ or 50$ bill?
	int billValue;

};

#endif
*/
