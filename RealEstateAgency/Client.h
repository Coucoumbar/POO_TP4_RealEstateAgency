#pragma once

#include <vector>

#include "Person.h"
#include "Contract.h"

class Client : public Person
{
private:
	vector<Contract*> contracts;

public:
	Client(const string&, const string&, const string&);

	void add_contract(const Contract&);
};

