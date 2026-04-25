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

	void addContract(Contract* contract);
	void displayInfo() const override;
};

