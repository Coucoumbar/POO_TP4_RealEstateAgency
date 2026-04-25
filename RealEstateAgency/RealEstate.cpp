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