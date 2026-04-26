#include "Person.h"
#include <iostream>

// Initialization of the static id counter
int Person::nextId = 0;

// Constructor
Person::Person(const string& name, const string& address, const string& phone)
    : id("PER-" + to_string(++nextId)),
    name(name),
    address(address),
    phone(phone)
{
}

// Destructor
Person::~Person() {}


void Person::display_info() const
{
    cout << "(" << id << ") : " << endl;
    cout << "  - Nom : " << name << endl;
    cout << "  - Adresse : " << address << endl;
    cout << "  - Téléphone : " << phone << endl;
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