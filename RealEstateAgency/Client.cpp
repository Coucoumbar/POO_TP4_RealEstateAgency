#include "Client.h"
#include <iostream>

// Constructor
Client::Client(const string& name, const string& address, const string& phone)
	: Person(name, address, phone) 
{
}


// Add a contract to the client's list of contracts
void Client::add_contract(Contract* contract)
{
	contracts.push_back(contract);
}

void Client::display_info() const
{
    Person::display_info();
    cout << "  - Nombre de contrats : " << contracts.size() << endl;

    if (!contracts.empty())
    {
        cout << "  - Détail des contrats :" << endl;
        for (size_t i = 0; i < contracts.size(); ++i)
        {
            contracts[i]->display_details();
        }
    }
}