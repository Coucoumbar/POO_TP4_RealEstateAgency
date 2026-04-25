#pragma once

#include <string>

using namespace std;

class Transaction
{
private:
	const int id;
	double price;
	string date;
public:
	Transaction(double, const string&);

	void process();
};

