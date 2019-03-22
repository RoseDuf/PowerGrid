//
//  Market.cpp
//  PowerGrid_local_update
//
//  Created by Isabelle Charette on 2019-03-22.
//  Copyright © 2019 Isabelle Charette. All rights reserved.
//

#include "Market.hpp"


Market::Market()
{
    coal_market = 24;
    oil_market = 15;
    garbage_market = 6;
    uranium_market = 2;
}
void Market::restockMarket(int step)
{
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
        return number<coal_market ? true : false;
    }
    else if(type=="oil")
    {
         return number<oil_market ? true : false;
    }
    
    else if(type=="garbage")
    {
      return number<garbage_market ? true : false;
    }
    else if(type=="uranium")
    {
        return number<uranium_market ? true : false;
    }

    return 0;
}