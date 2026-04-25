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


void Person::displayInfo() const
{
    cout << "ID: " << id << endl;
    cout << "Nom: " << name << endl;
    cout << "Adresse: " << address << endl;
    cout << "Téléphone: " << phone << endl;
}

// Getters
string Person::getId() const {
    return id;
}

string Person::getName() const {
    return name;
}

string Person::getAddress() const {
    return address;
}

string Person::getPhone() const {
    return phone;
}