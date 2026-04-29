#pragma once

#include <string>
#include <vector>

// forward declaration tu avoid circular dependencies
class RealEstate;
class Person;
class Client;
class Owner;
class Transaction;

using namespace std;

class Contract
{
private:
	const string id;
	RealEstate* property;
	Person* client;
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

	void display() const;
	void sign();

	string get_id() const;
	string get_date() const;
	string get_type() const;
	string get_status() const;
	double get_price() const;
	RealEstate* get_property() const;
	Owner* get_owner() const;
	Person* get_client() const;
	void set_owner(Owner* new_owner);
	void set_client(Person* new_client);
};

