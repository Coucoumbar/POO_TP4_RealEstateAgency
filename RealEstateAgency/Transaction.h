#pragma once

#include <string>

class Contract;

using namespace std;

class Transaction
{
private:
	static int current_id;

private:
	string id;
	double price;
	string date;
	string type; // "Loyer", "Commission"
	Contract* contract;

public:
	Transaction(double price, const string& date, const string& type, Contract* contract);

	void process();
	void display() const;
	string get_id() const;

};

