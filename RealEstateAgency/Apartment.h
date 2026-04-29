#pragma once

#include "RealEstate.h"
#include "Tenant.h"

class Apartment : public RealEstate
{
private:
	Tenant* tenant = nullptr;
public:
	Apartment(Owner*&, const string&, double, const string&);

	void display() const override;

	void change_tenant(Tenant*);
};

