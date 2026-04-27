#include "Owner.h"
#include <iostream>

// Constructor
Owner::Owner(const string& name, const string& address, const string& phone)
    : Person(name, address, phone)
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
void Owner::display_info() const
{
    Person::display_info();
    cout << "  - Nombre de biens possédés : " << owned.size() << endl;
    cout << "  - Nombre de contrats     : " << contracts.size() << endl;
    if (!contracts.empty())
    {
        cout << "  - Détail des contrats :" << endl;
        for (size_t i = 0; i < contracts.size(); ++i)
        {
            contracts[i]->display_details();
        }
    }
}

vector<RealEstate*> Owner::get_owned() const {
	return owned;
}