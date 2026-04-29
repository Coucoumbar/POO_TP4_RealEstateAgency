#pragma once

#include <string>

#include "Contract.h";

class Contract;
class Agency;

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
	bool processed = false;

public:
	Transaction(Contract* contract);

	void process(Agency&);
	void display() const;

	string get_id() const;
	bool is_processed() const;

};

