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
	Owner(const string& name, const string& address, const string& phone);

	void addOwnership(RealEstate* property);
	void addContract(Contract* contract);
	void displayInfo() const override;
};

