#pragma once

#include "RealEstate.h"

class House : public RealEstate
{
public:
	House(Owner*& owner, const string& address, double surface, const string& type);

	void display() const override;
};

