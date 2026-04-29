#include "Transaction.h"

#include <iostream>

#include "Contract.h"
#include "Apartment.h";

int Transaction::current_id = 0;

Transaction::Transaction(Contract* contract) : 
	id("TRA-" + to_string(++current_id)),
	contract(contract),
	price(contract->get_price()),
	date(contract->get_date()),
	type(contract->get_type())
{
	
}

void Transaction::process(Agency& a) {
	if (contract->get_status() != "Signé")
		throw runtime_error("Transaction impossible : le contrat n'est pas signé.");
	if (processed)
		throw runtime_error("Transaction déjà effectuée.");

	if (type == "Location")
	{
		Apartment* rea = dynamic_cast<Apartment*>(contract->get_property());
		Person* per = contract->get_client();
		vector<Person*> tenants = a.filter_persons("Locataire");

		Tenant* target = nullptr;
		for (Person* t : tenants)
		{
			bool v = (
				t->get_name() == per->get_name() &&
				t->get_address() == per->get_address() &&
				t->get_phone() == per->get_phone());

			if (v) target = dynamic_cast<Tenant*>(t);
		}

		if (!target)
		{
			target = new Tenant(
				per->get_name(),
				per->get_address(),
				per->get_phone());

			a.add_person(target);
		}

		rea->change_tenant(target);
		target->add_tenancy(rea);
		target->add_contract(contract);
	}
	else 
	{
		RealEstate* rea = contract->get_property();
		Person* per = contract->get_client();
		vector<Person*> owners = a.filter_persons("Propriétaire");

		Owner* target = nullptr;
		for (Person* o : owners)
		{
			bool v = (
				o->get_name() == per->get_name() &&
				o->get_address() == per->get_address() &&
				o->get_phone() == per->get_phone());

			if (v) target = dynamic_cast<Owner*>(o);
		}

		if (!target)
		{
			target = new Owner(
				per->get_name(),
				per->get_address(),
				per->get_phone());

			a.add_person(target);
		}

		contract->get_owner()->remove_ownership(rea);
		target->add_ownership(rea);
		target->add_contract(contract);

		processed = true;
	}
}

void Transaction::display() const {
	cout << " Transaction " << id << " - " << type << " : " << price << "$ le " << date
		<< " (Contrat " << contract->get_id() << ")\n";
}

string Transaction::get_id() const { return id; }

bool Transaction::is_processed() const { return processed; }