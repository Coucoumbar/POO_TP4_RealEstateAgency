#pragma once

#include <string>
#include <iostream>

#include "Person.h"
#include "Owner.h"

#include "Interface.hpp"

using namespace std;
using Itf = Interface;

class RealEstate
{
private:
	static int current_id;
protected:
	string id;
	string address;
	double surface;
	string type;
	string status; // "Non-vendu", "Vendu", "En location"
	Owner* owner;


public:
	RealEstate(Owner*&, const string&, double, const string&);
	
	virtual void display() const;
	void update_status(const string&);

	string get_id() const;
	string get_address() const;
	string get_surface() const;
	string get_type() const;
	string get_status() const;
};

