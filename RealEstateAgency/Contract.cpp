#include "Contract.h"

#include <iostream>
#include <stdexcept>

#include "RealEstate.h"

int Contract::nextId = 0;

Contract::Contract(RealEstate* property, const string& date, const string& type,
    const string& terms, double price, Owner* owner)
    : id("CON-" + to_string(++nextId)),
    property(property),
    date(date),
    type(type),
    terms(terms),
    price(price),
    owner(owner),
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

void Contract::display() const {
    Itf::subtitle("Contrat " + id);

    Itf::display_value("Type", type);
    Itf::display_value("Date", date);
    Itf::display_value("Termes", terms);
    Itf::display_value("Statut", status);
    Itf::display_value("Propriété", property->get_id());
    Itf::display_value("Prix", to_string(price) + "$");
}

string Contract::get_id() const {
    return id;
}

string Contract::get_date() const {
    return date;
}

string Contract::get_type() const {
    return type;
}

string Contract::get_status() const {
    return status;
}

RealEstate* Contract::get_property() const {
    return property;
}

double Contract::get_price() const {
    return price;
}

Person* Contract::get_client() const {
    return client;
}

Owner* Contract::get_owner() const {
    return owner;
}

void Contract::set_owner(Owner* new_owner) {
    owner = new_owner;
}

void Contract::set_client(Person* new_client) {
    client = new_client;
}