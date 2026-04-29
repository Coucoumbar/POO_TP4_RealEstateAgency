#include "House.h"

House::House(
	Owner*& owner,
	const string& address,
	double surface,
	const string& type
) :
	RealEstate(owner, address, surface, type)
{
	
}

void House::display() const {

}