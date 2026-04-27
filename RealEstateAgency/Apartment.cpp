#include "Apartment.h"

Apartment::Apartment(
	Person* owner, 
	const string& address, 
	double surface, 
	const string& type
) : 
	RealEstate(address, surface, type),
	owner(owner)
{}