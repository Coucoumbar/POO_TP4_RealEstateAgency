#pragma once

#include <string>
#include <vector>

#include "Interface.hpp"
#include "Contract.h"

using namespace std;
using Itf = Interface;

class Person
{
protected:
	const string id;
	string name;
	string address;
	string phone;
	string type;
	vector<Contract*> contracts;

	static int nextId;
public:
	Person(const string& name, const string& address, const string& phone, const string& type);
	virtual ~Person();

	virtual void display() const;

	void add_contract(Contract*&);

	string get_id() const;
	string get_name() const;
	string get_address() const;
	string get_phone() const;
	string get_type() const;
};
