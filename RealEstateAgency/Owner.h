#pragma once

#include <vector>

#include "Person.h"
#include "RealEstate.h"
#include "Contract.h"

class Owner : public Person
{
private:
	vector<RealEstate*> owned;
	vector<Contract*> contracts;

public:
	Owner(const string&, const string&, const string&);

	void add_ownership(const RealEstate&);
	void add_contract(const Contract&);
};

