#pragma once

#include <string>

using namespace std;

class Transaction
{
private:
	static int current_id;

private:
	string id;
	double price;
	string date;


public:
	Transaction(double, const string&);

	void process();
};

