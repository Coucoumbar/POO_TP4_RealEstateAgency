#pragma once

#include <vector>

#include "Person.h"
#include "Contract.h"

class Client : public Person
{
private:
	vector<Contract*> contracts;

public:
	Client(const string& name, const string& address, const string& phone);

	void addContract(Contract* contract);
	void displayInfo() const override;
};

