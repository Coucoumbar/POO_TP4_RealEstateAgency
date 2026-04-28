#pragma once

#include "RealEstate.h"

class Land : public RealEstate
{
public:
	Land(const string& address, double surface, const string& type);
};

