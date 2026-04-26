#pragma once

#include <string>
#include <vector>
#include "RealEstate.h"

using namespace std;

class Contract
{
private:
	const string id;
	RealEstate* property;
	string date;
	string type; // Location, Vente, etc.
	string terms;
	string status; // En attente, Signé

	static int nextId;

public:
	Contract(RealEstate* property, const string& date, const string& type, const string& terms);

	void display_details() const;
	void sign();

	string get_id() const;
	string get_date() const;
	string get_type() const;
	string get_status() const;
	RealEstate* get_property() const;
};

