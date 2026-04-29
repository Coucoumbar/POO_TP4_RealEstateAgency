#include "Agency.h"

Agency::Agency() {

}

Agency::~Agency() {
	for (auto rea : properties) delete rea;
	for (auto per : persons) delete per;
	for (auto con : contracts) delete con;
	for (auto tra : transactions) delete tra;
}

void Agency::add_property(RealEstate* content) {
	properties.push_back(content);
}

void Agency::add_person(Person* content) {
	persons.push_back(content);
}

void Agency::add_contract(Contract* content) {
	contracts.push_back(content);
}

void Agency::save_transaction(Transaction* new_transaction) {
	try {
		transactions.push_back(new_transaction);
		cout << " Transaction " << new_transaction->get_id() << " enregistrée.\n";
	}
	catch (const exception& e) {
		cout << " Erreur lors de l'enregistrement de la transaction : " << e.what() << endl;
		delete new_transaction;
	}
}

vector<Person*> Agency::filter_persons(const string& filter) {
	vector<Person*> filtered;

	for (Person* p : persons)
	{
		if (p->get_type() == filter) filtered.push_back(p);
	}

	return filtered;
}

vector<RealEstate*> Agency::filter_properties(const string& filter, const string& status) {
	vector<RealEstate*> filtered;

	for (RealEstate* p : properties)
	{
		if (
			(p->get_type() == filter || filter.empty()) 
			&& 
			(p->get_status() == status || status.empty())) 
			filtered.push_back(p);
	}

	return filtered;
}
vector<RealEstate*> Agency::filter_properties(const vector<RealEstate*>& values, const string& filter, const string& status) {
	vector<RealEstate*> filtered;

	for (RealEstate* p : values)
	{
		if (
			(p->get_type() == filter || filter.empty())
			&&
			(p->get_status() == status || status.empty()))
			filtered.push_back(p);
	}

	return filtered;
}

vector<Contract*> Agency::filter_contracts(const string& filter, const string& status) {
	vector<Contract*> filtered;

	for (Contract* p : contracts)
	{
		if (
			(p->get_type() == filter || filter.empty())
			&&
			(p->get_status() == status || status.empty()))
			filtered.push_back(p);
	}

	return filtered;
}

bool Agency::has_person(const string& filter) const {
	for (Person* p : persons)
	{
		if (p->get_type() == filter) return true;
	}

	return false;
}

bool Agency::has_property(const string& filter, const string& status) const {
	for (RealEstate* p : properties)
	{
		if (
			(p->get_type() == filter || filter.empty())
			&&
			(p->get_status() == status || status.empty())) 
			return true;
	}

	return false;
}

bool Agency::has_contract(const string& filter, const string& status) const {
	for (Contract* c : contracts)
	{
		if (
			(c->get_type() == filter || filter.empty())
			&&
			(c->get_status() == status || status.empty()))
			return true;
	}

	return false;
}

vector<Contract*> Agency::get_contracts() const {
	return contracts;
}