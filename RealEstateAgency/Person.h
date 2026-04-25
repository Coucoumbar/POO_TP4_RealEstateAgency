#pragma once

#include <string>

using namespace std;

class Person
{
protected:
	const int id;
	string name;
	string address;
	string phone;

public:
	Person(const string&, const string&, const string&);
};

