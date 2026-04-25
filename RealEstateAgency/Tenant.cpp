#include "Tenant.h"
#include <iostream>

Tenant::Tenant(const string& name, const string& address, const string& phone)
    : Person(name, address, phone)
{
}

void Tenant::addContract(Contract* contract)
{
    contracts.push_back(contract);
}

void Tenant::displayInfo() const
{
    cout << "--- Locataire ---" << endl;
    Person::displayInfo();
    cout << "Nombre de contrats : " << contracts.size() << endl;
    // À suivre quand Contract est implémenté : afficher les détails de chaque contrat
}