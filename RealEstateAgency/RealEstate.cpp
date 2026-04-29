#include "RealEstate.h"

int RealEstate::current_id = 0;

RealEstate::RealEstate(
	Owner*& owner,
	const string& address,
	double surface,
	const string& type
) :
	id("REA-" + to_string(++current_id)),
	address(address),
	surface(surface),
	type(type), 
	status("Non-vendu")
{
	owner->add_ownership(this);
}

void RealEstate::display() const {
	Itf::subtitle(id);

	Itf::display_value("Adresse", address);
	Itf::display_value("Surface", to_string(surface));
	Itf::display_value("Type", type);
	Itf::display_value("Statut", status);
}

void RealEstate::update_status(const string& value) {
	status = value;
}

// Getters
string RealEstate::get_id() const {
	return id;
}

string RealEstate::get_address() const {
	return address;
}

string RealEstate::get_surface() const {
	return to_string(surface);
}

string RealEstate::get_type() const {
	return type;
}

string RealEstate::get_status() const {
	return status;
}
