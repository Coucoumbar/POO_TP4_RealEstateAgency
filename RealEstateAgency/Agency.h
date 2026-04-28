#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "RealEstate.h"
#include "Person.h"
#include "Client.h"
#include "Owner.h"
#include "Tenant.h"
#include "Contract.h"
#include "Transaction.h"

using namespace std;

class Agency
{
private:
	vector<RealEstate*> properties;
	vector<Person*> persons;
	vector<Client*> clients;
	vector<Owner*> owners;
	vector<Tenant*> tenants;
	vector<Contract*> contracts;
	vector<Transaction*> transactions;

public:
	Agency();
	~Agency();

	void add_property(RealEstate*);
	void add_person(Person*);

	vector<Person*> filter_persons(const string&);
	vector<RealEstate*> filter_properties(const string&);

	void add_client(Client*);
	void add_owner(Owner*);

	void create_contract();
	void save_transaction();
	void sign_contract();
};

