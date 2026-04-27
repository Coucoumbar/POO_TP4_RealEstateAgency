#include "Transaction.h"
#include <iostream>
#include "Contract.h"
int Transaction::current_id = 0;

Transaction::Transaction(double price, const string& date, const string& type, Contract* contract) : price(price), date(date), type(type), contract(contract) {
	id = "TRA-" + to_string(++current_id);
}

void Transaction::process() {

}

void Transaction::display() const {
	cout << "Transaction " << id << " - " << type << " : " << price << "$ le " << date
		<< " (Contrat " << contract->get_id() << ")\n";
}

string Transaction::get_id() const { return id; }