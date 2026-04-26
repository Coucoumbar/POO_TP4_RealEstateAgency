#pragma once

#include <string>

using namespace std;

class Person
{
protected:
	const string id;
	string name;
	string address;
	string phone;

	static int nextId;
public:
	Person(const string& name, const string& address, const string& phone);
	virtual ~Person();

	virtual void display_info() const;

	string get_id() const;
	string get_name() const;
	string get_address() const;
	string get_phone() const;
};
