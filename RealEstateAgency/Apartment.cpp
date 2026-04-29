#include "Apartment.h"

Apartment::Apartment(
	Owner*& owner, 
	const string& address, 
	double surface, 
	const string& type
) : 
	RealEstate(owner, address, surface, type)
{
	
}

void Apartment::change_tenant(Tenant* tenant) {
	this->tenant = tenant;
}

void Apartment::display() const {
	RealEstate::display();

	Itf::display_value("Loacataire", (!tenant ? "Aucun" : tenant->get_name()));
}