#pragma once

#include "Person.h"
#include <vector>
#include "Contract.h"

class Tenant : public Person
{
private:
	vector<Contract*> contracts;
	vector<RealEstate*> rented_properties;

public:
	Tenant(const string& name, const string& address, const string& phone);

	void add_contract(Contract* contract);
	void add_tenancy(RealEstate* property);
	void display_info() const override;
};

