#pragma once

#include "RealEstate.h"
#include "Owner.h"

class Apartment : public RealEstate
{
private:
	Person* owner;

public:
	Apartment(Person*, const string&, double, const string&);
};

