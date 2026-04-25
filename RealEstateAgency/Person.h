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

	virtual void displayInfo() const;

	string getId() const;
	string getName() const;
	string getAddress() const;
	string getPhone() const;
};

