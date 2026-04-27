#pragma once

#include <string>

#include "Interface.hpp"

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

	static int nextId;
public:
	Person(const string& name, const string& address, const string& phone, const string& type);
	virtual ~Person();

	virtual void display() const;

	string get_id() const;
	string get_name() const;
	string get_address() const;
	string get_phone() const;
	string get_type() const;
};
