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

	void add_ownership(RealEstate* property);
	void remove_ownership(RealEstate* property);
	void add_contract(Contract* contract);
	void display_info() const override;

	vector<RealEstate*> get_owned() const;
};

