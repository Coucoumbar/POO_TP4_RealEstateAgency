#pragma once

#include "Person.h"
#include <vector>
#include "Contract.h"

class Tenant : public Person
{
private:
	vector<Contract*> contracts;

public:
	Tenant(const string& name, const string& address, const string& phone);

	void add_contract(Contract* contract);
	void display_info() const override;
};

