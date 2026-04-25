#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "RealEstate.h"
#include "Person.h"
#include "Client.h"
#include "Owner.h"
#include "Contract.h"
#include "Transaction.h"

using namespace std;

class Agency
{
private:
	vector<RealEstate> real_estates;
	vector<Client> clients;
	vector<Owner> owners;
	vector<Contract> contracts;
	vector<Transaction> transactions;

public:
	Agency();

	void add_real_estate();
	void add_client();
	void add_owner();
	void list_options();
	void create_contract();
	void save_transaction();
};

