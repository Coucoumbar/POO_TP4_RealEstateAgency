#include "Apartment.h"

Apartment::Apartment(
	Person* owner, 
	const string& address, 
	double surface, 
	const string& type
) : 
	RealEstate(address, surface, type),
	owner(owner)
{
	dynamic_cast<Owner*>(owner)->add_ownership(this);
}