#include "Contract.h"
#include <iostream>
#include <stdexcept>

int Contract::nextId = 0;

Contract::Contract(RealEstate* property, const string& date, const string& type, const string& terms)
    : id("CON-" + to_string(++nextId)),
    property(property),
    date(date),
    type(type),
    terms(terms),
    status("En attente")
{
}

void Contract::sign()
{
    if (status == "Signé") {
        throw runtime_error("Contrat déjà signé.");
    }
    if (!property) {
        throw runtime_error("Impossible de signer un contrat incomplet.");
    }
    status = "Signé";
}

void Contract::display_details() const {
    cout << "  ~~ Contrat " << id << " ~~" << endl;
    cout << "    - Type   : " << type << endl;
    cout << "    - Date   : " << date << endl;
    cout << "    - Termes : " << terms << endl;
    cout << "    - Statut : " << status << endl;
    cout << "    - Bien   : " << property->get_id() << endl;
    cout << "  ~~~~~~~~~~~~~~~~~~~~~" << endl;
}

string Contract::getId() const {
    return id;
}

string Contract::getDate() const {
    return date;
}

string Contract::getType() const {
    return type;
}

string Contract::getStatus() const {
    return status;
}

RealEstate* Contract::getProperty() const {
    return property;
}