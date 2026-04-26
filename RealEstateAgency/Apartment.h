#pragma once

#include "RealEstate.h"
#include "Owner.h"

class Apartment : public RealEstate
{
private:
	Owner& owner;

public:
	Apartment(Owner&, const string&, double, const string&, const string&);
};

