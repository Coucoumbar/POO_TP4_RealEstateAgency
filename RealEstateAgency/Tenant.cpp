#include "Tenant.h"
#include <iostream>

Tenant::Tenant(const string& name, const string& address, const string& phone)
    : Person(name, address, phone, "Locataire")
{
}

void Tenant::add_contract(Contract* contract)
{
    contracts.push_back(contract);
}

void Tenant::display() const
{
    Person::display();
    cout << "  - Nombre de contrats : " << contracts.size() << endl;
    if (!contracts.empty())
    {
        cout << "  - Détail des contrats :" << endl;
        for (size_t i = 0; i < contracts.size(); ++i)
        {
            contracts[i]->display();
        }
    }
}

void Tenant::add_tenancy(RealEstate* property)
{
    rented_properties.push_back(property);
}