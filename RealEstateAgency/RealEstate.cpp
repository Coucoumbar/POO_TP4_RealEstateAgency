#include "RealEstate.h"

int RealEstate::current_id = 0;

RealEstate::RealEstate(
	const string& address,
	double surface,
	const string& type
) :
	address(address),
	surface(surface),
	type(type)
{
	id = "REA-" + to_string(++current_id);
	status = "Non-vendu";
}

void RealEstate::display_details() const {
	cout
		<< " (" << id << ") :\n"
		<< "  - Adresse : " << address << endl
		<< "  - Surface : " << surface << " metres carres" << endl
		<< "  - Type : " << type << endl
		<< "  - Statut : " << status << endl;
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
