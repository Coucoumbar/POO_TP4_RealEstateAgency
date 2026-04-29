#include "Transaction.h"
#include <iostream>
#include "Contract.h"
int Transaction::current_id = 0;

Transaction::Transaction(double price, const string& date, const string& type, Contract* contract) : price(price), date(date), type(type), contract(contract) {
	id = "TRA-" + to_string(++current_id);
}

void Transaction::process() {
	if (contract->get_status() != "Signé")
		throw runtime_error("Transaction impossible : le contrat n'est pas signé.");
	if (processed)
		throw runtime_error("Transaction déjà effectuée.");
	else
		cout << " Transaction " << id << " effectuée : " << type << " de " << price << "$ pour le contrat " << contract->get_id() << ".\n";
	processed = true;
}

void Transaction::display() const {
	cout << " Transaction " << id << " - " << type << " : " << price << "$ le " << date
		<< " (Contrat " << contract->get_id() << ")\n";
}

string Transaction::get_id() const { return id; }