#include "Owner.h"
#include <iostream>

// Constructor
Owner::Owner(const string& name, const string& address, const string& phone)
    : Person(name, address, phone, "Propriétaire")
{
}

// Add a property to the owner's list of owned properties
void Owner::add_ownership(RealEstate* property)
{
    owned.push_back(property);
}

void Owner::remove_ownership(RealEstate* property_to_delete) {
    auto property = find(owned.begin(), owned.end(), property_to_delete);
    if (property != owned.end())
        owned.erase(property);
}

// Add a contract to the owner's list of contracts
void Owner::add_contract(Contract* contract)
{
    contracts.push_back(contract);
}

// Display owner's informations
void Owner::display() const
{
    Person::display();

    cout << endl;

    Itf::display_value("Nombre de propriétés", to_string(owned.size()));
    Itf::display_value("Nombre de contrats", to_string(contracts.size()));

    if (!contracts.empty())
    {
        Itf::simple_list<Contract>(contracts);
    }
}

vector<RealEstate*> Owner::get_owned() const {
	return owned;
}