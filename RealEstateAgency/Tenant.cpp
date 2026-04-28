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

    cout << endl;

    Itf::display_value("Nombre de contrats", to_string(contracts.size()));

    if (!contracts.empty())
    {
        Itf::simple_list<Contract>(contracts);
    }
}

void Tenant::add_tenancy(RealEstate* property)
{
    rented_properties.push_back(property);
}