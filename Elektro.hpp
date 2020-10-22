//(Isabelle)

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
    int getTotalBalance() const;
    
    
    void toString();

private:
    
    std::vector< std::pair<int,int> > bills =  { {1,0},
                                                {10,0},
                                                {50,0} };
    
};

#endif
