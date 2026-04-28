#include "Client.h"
#include <iostream>

// Constructor
Client::Client(const string& name, const string& address, const string& phone)
	: Person(name, address, phone, "Client")
{}


// Add a contract to the client's list of contracts
void Client::add_contract(Contract* contract)
{
	contracts.push_back(contract);
}

void Client::display() const
{
    Person::display();

    cout << endl;

    Itf::display_value("Nombre de contrats", to_string(contracts.size()));

    if (!contracts.empty())
    {
        Itf::simple_list<Contract>(contracts);
    }
}