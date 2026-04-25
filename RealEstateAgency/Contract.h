#pragma once

#include <string>
#include "RealEstate.h"

using namespace std;

class Contract
{
private:
	const string id;
	RealEstate* property;
	string date;
	string type;
	string terms;
	string status;

public:
	Contract(const string&, const string&, const string&);

	void display_details();
	void sign();
};

