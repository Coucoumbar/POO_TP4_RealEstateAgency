#include "Owner.h"
#include <iostream>

// Constructor
Owner::Owner(const string& name, const string& address, const string& phone)
    : Person(name, address, phone)
{
}

// Add a property to the owner's list of owned properties
void Owner::addOwnership(RealEstate* property)
{
    owned.push_back(property);
}

// Add a contract to the owner's list of contracts
void Owner::addContract(Contract* contract)
{
    contracts.push_back(contract);
}

// Display owner's informations
void Owner::displayInfo() const
{
    cout << "--- Propriétaire ---" << endl;
    Person::displayInfo();
    cout << "Nombre de biens possédés : " << owned.size() << endl;
    cout << "Nombre de contrats     : " << contracts.size() << endl;
    // À suivre quand Contract et RealEstate sont implémenté : afficher les détails de chaqu'un
}