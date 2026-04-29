#include "Land.h"

Land::Land(
	Owner*& owner,
	const string& address,
	double surface,
	const string& type
) :
	RealEstate(owner, address, surface, type)
{
	
}

void Land::display() const {

}