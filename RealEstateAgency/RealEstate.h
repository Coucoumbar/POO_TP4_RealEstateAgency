#pragma once

#include <string>
#include <iostream>

using namespace std;

class RealEstate
{
private:
	static int current_id;
protected:
	string id;
	string address;
	double surface;
	string type;
	string status;

public:
	RealEstate(const string&, double, const string&);
	
	virtual void display_details() const;
	void update_status(const string&);

	string get_id() const;
	string get_address() const;
	string get_surface() const;
	string get_type() const;
	string get_status() const;
};

