
#include "Market.hpp"


Market::Market()
{
    coal_market = 24;
    oil_market = 15;
    garbage_market = 6;
    uranium_market = 2;
}

Market::~Market()
{

}
void Market::restockMarket(int step)
{
    //need to check if enough in supply before restock***
    if(step==1)
    {
        coal_market+=3;
        oil_market+=2;
        garbage_market+=1;
        uranium_market+=1;
    }
    else if(step==2)
    {
        coal_market+=4;
        oil_market+=2;
        garbage_market+=2;
        uranium_market+=1;
    }
    else if(step==3)
    {
        coal_market+=3;
        oil_market+=4;
        garbage_market+=3;
        uranium_market+=1;
    }
    else
    {
        cout << "Invalid step."<< endl;
    }
    
    coal_supply = TOTAL_COAL - coal_market;
    oil_supply = TOTAL_OIL - oil_market;
    garbage_supply = TOTAL_GARBAGE - garbage_market;
    uranium_supply = TOTAL_URANIUM - uranium_market;
}

int Market::getPrice(string type)
{
    //NOT SURE THIS IS THE BEST WAY TO IMPLEMENT
    if(type=="coal"){
    
    if(coal_market<=3) coal_price=8;
    else if(coal_market>3 && coal_market<=6)coal_price=7;
    else if(coal_market>6 && coal_market<=9)coal_price=6;
    else if(coal_market>9 && coal_market<=12)coal_price=5;
    else if(coal_market>12 && coal_market<=15)coal_price=4;
    else if(coal_market>15 && coal_market<=18)coal_price=3;
    else if(coal_market>18 && coal_market<=21)coal_price=2;
    else if(coal_market>21 && coal_market<=24)coal_price=1;
    return coal_price;
    }
else if(type=="oil")
    {
    if(oil_market<=3) oil_price=8;
    else if(oil_market>3 && oil_market<=6)oil_price=7;
    else if(oil_market>6 && oil_market<=9)coal_price=6;
    else if(oil_market>9 && oil_market<=12)oil_price=5;
    else if(oil_market>12 && oil_market<=15)oil_price=4;
    else if(oil_market>15 && oil_market<=18)oil_price=3;
    else if(oil_market>18 && oil_market<=21)oil_price=2;
    else if(oil_market>21 && oil_market<=24)oil_price=1;
    return oil_price;
    }
    
    else if(type=="garbage")
    {
        if(garbage_market<=3) garbage_price=8;
        else if(garbage_market>3 && garbage_market<=6)garbage_price=7;
        else if(garbage_market>6 && garbage_market<=9)garbage_price=6;
        else if(garbage_market>9 && garbage_market<=12)garbage_price=5;
        else if(garbage_market>12 && garbage_market<=15)garbage_price=4;
        else if(garbage_market>15 && garbage_market<=18)garbage_price=3;
        else if(garbage_market>18 && garbage_market<=21)garbage_price=2;
        else if(garbage_market>21 && garbage_market<=24)garbage_price=1;
        
        return garbage_price;
    }
    else if(type=="uranium")
    {
        if(uranium_market==1) uranium_price=16;
        else if(uranium_market==2) uranium_price=14;
        else if(uranium_market==3) uranium_price=12;
        else if(uranium_market==4) uranium_price=10;
        else if(uranium_market==5) uranium_price=8;
        else if(uranium_market==6) uranium_price=7;
        else if(uranium_market==7) uranium_price=6;
        else if(uranium_market==8) uranium_price=5;
        else if(uranium_market==9) uranium_price=4;
        else if(uranium_market==10) uranium_price=3;
        else if(uranium_market==11) uranium_price=2;
        else if(uranium_market==12) uranium_price=1;
        return uranium_price;
    }
    
    
    return 0;
}


bool Market::checkSupply(string type, int number)
{
    if(type=="coal")
    {
        return number <= coal_supply ? true : false;
    }
    else if(type=="oil")
    {
        return number <= oil_supply  ? true : false;
    }
    
    else if(type=="garbage")
    {
        return number <= garbage_supply  ? true : false;
    }
    else if(type=="uranium")
    {
        return number <= uranium_supply  ? true : false;
    }
    
    return 0;
}


void Market::rtPurchase(string type, int number)
{

    if(type=="coal")
    {
        if(checkMarket("coal", number))
        {
            coal_market-=number;
        }
        else
        {
              cout << "Not enough coal in the market."<< endl;
        }
    }
    else if(type=="oil")
    {
        if(checkMarket("oil", number))
        {
            oil_market-=number;
        }
        else
        {
            cout << "Not enough oil in the market."<< endl;
        }    }

    else if(type=="garbage")
    {
        if(checkMarket("garbage", number))
        {
            garbage_market-=number;
        }
        else
        {
            cout << "Not enough garbage in the market."<< endl;
        }
    }
    else if(type=="uranium")
    {
        if(checkMarket("uranium", number))
        {
            uranium_market-=number;
        }
        else
        {
            cout << "Not enough uranium in the market."<< endl;
        }
    }
    else
    {
        cout << "Invalid type."<< endl;

    }
}

bool Market::checkMarket(string type, int number)
{
    if(type=="coal")
    {
        return number<=coal_market ? true : false;
    }
    else if(type=="oil")
    {
         return number<=oil_market ? true : false;
    }
    
    else if(type=="garbage")
    {
      return number<=garbage_market ? true : false;
    }
    else if(type=="uranium")
    {
        return number<=uranium_market ? true : false;
    }

    return 0;
}