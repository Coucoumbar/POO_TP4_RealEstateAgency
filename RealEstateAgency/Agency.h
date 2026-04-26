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
	vector<RealEstate> real_estates;
	vector<Client*> clients;
	vector<Owner*> owners;
	vector<Tenant*> tenants;
	vector<Contract*> contracts;
	vector<Transaction*> transactions;

public:
	Agency();
	~Agency();

	void add_real_estate(const RealEstate);
	void create_real_estate();
	void create_person();
	void create_contract();
	void add_client(Client*);
	void add_owner(Owner*);
	void list_options();
	void list_persons();
	void save_transaction();
};

