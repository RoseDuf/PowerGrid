#ifndef RESOURCETOKEN_HPP_
#define RESOURCETOKEN_HPP_
#include <vector>
#include <string>
using namespace std;

class ResourceToken
{
public:
	ResourceToken();
    //constructor of Resource Token to keep track of all types: coal, garbage, uranium, oil
    ResourceToken(int _numCoal, int _numGarbage, int _numUranium, int _numOil);

	~ResourceToken();

   void toString();

private:
    std::vector< std::pair<string,int> > tokens =  {{"coal",0},
                                                   {"garbage",0},
                                                   {"uranium",0},
                                                   {"oil",0}};
};
#endif
