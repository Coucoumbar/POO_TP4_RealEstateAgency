#pragma once

#include <string>
#include <vector>

#include "RealEstate.h"
#include "Transaction.h"

// forward declaration tu avoid circular dependencies
class Client;
class Owner;

using namespace std;

class Contract
{
private:
	const string id;
	RealEstate* property;
	Client* client;
	Owner* owner;
	string date;
	string type; // Location, Vente, etc.
	string terms;
	string status; // En attente, Signé
	double price;
	vector<Transaction*> transactions;

	static int nextId;

public:
	Contract(RealEstate* property, const string& date, const string& type, const string& terms, double price, Owner* owner = nullptr);

	void display_details() const;
	void sign();

	string get_id() const;
	string get_date() const;
	string get_type() const;
	string get_status() const;
	double get_price() const;
	RealEstate* get_property() const;
	Owner* get_owner() const;
	Client* get_client() const;
	void set_owner(Owner* new_owner);
	void set_client(Client* new_client);
};

