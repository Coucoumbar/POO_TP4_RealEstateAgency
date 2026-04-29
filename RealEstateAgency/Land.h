#pragma once

#include "RealEstate.h"

class Land : public RealEstate
{
public:
	Land(Owner*& owner, const string& address, double surface, const string& type);

	void display() const override;
};

