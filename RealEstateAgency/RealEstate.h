#pragma once

#include <string>

using namespace std;

class RealEstate
{
protected:
	const string id;
	string address;
	double surface;
	string type;
	string status;

public:
	RealEstate(const string&, double, const string&, const string&);
	
	virtual void display_details() const;
	void update_status(const string&);
};

