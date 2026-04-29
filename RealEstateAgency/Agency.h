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
	void add_contract(Contract*);

	vector<Person*> filter_persons(const string&);
	vector<RealEstate*> filter_properties(const string&, const string&);
	vector<RealEstate*> filter_properties(const vector<RealEstate*>&, const string&, const string&);

	bool has_person(const string&) const;
	bool has_property(const string&, const string&) const;
	bool has_contract() const;

	void add_client(Client*);
	void add_owner(Owner*);

	void create_contract();
	void save_transaction(Transaction*);
	void sign_contract();

	vector<Contract*> get_contracts() const;
};

