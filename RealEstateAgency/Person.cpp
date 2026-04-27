#include "Person.h"
#include <iostream>

// Initialization of the static id counter
int Person::nextId = 0;

// Constructor
Person::Person(
    const string& name, 
    const string& address, 
    const string& phone, 
    const string& type
) : 
    id("PER-" + to_string(++nextId)),
    name(name),
    address(address),
    phone(phone),
    type(type)
{}

// Destructor
Person::~Person() {}


void Person::display() const
{
    Itf::subtitle(id);

    Itf::display_value("Nom", name);
    Itf::display_value("Adresse", address);
    Itf::display_value("Téléphone", phone);
}

// Getters
string Person::get_id() const {
    return id;
}

string Person::get_name() const {
    return name;
}

string Person::get_address() const {
    return address;
}

string Person::get_phone() const {
    return phone;
}

string Person::get_type() const {
    return type;
}