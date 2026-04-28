// Fait par : Mathias Lavoie & Nathan Morasse

#include <iostream>
#include <windows.h>

#include "Agency.h"
#include "Interface.hpp"
#include "Apartment.h"
#include "House.h"
#include "Land.h"

using namespace std;
using Itf = Interface;

Agency agency;

void menu();
RealEstate* property_creation();
Person* person_creation();
void person_list();
Person* person_choice(const string&);
void property_list();
RealEstate* property_choice(const string&);


int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	// Initial Data

	Client* client1 = new Client("Jean Dupont", "123 Rue Principale", "418-456-1234");
	agency.add_client(client1);
	agency.add_person(client1);
	Client* client2 = new Client("Yvon Tremblay", "43 Rue Secondaire", "654-623-6483");
	agency.add_client(client2);
	agency.add_person(client2);

	Owner* owner1 = new Owner("Alice Martin", "789 Boulevard des Fleurs", "555-123-4567");
	agency.add_owner(owner1);
	agency.add_person(owner1);
	Owner* owner2 = new Owner("Martin Pecheur", "2937 Avenue des Pins", "525-243-5452");
	agency.add_owner(owner2);
	agency.add_person(owner2);

	Tenant* tenant1 = new Tenant("Martin Pecheur", "2937 Avenue des Pins", "525-243-5452");
	agency.add_person(tenant1);

	House* rea1 = new House("693 Rabelais", 200, "Maison");
	agency.add_property(rea1);
	Apartment* rea2 = new Apartment(owner1, "201 Bernard", 10.5, "Appartement");
	agency.add_property(rea2);
	Land* rea3 = new Land("164 Camion", 30, "Terrain");
	agency.add_property(rea3);
	House* rea4 = new House("222 Lac", 2000, "Maison");
	agency.add_property(rea4);

	owner1->add_ownership(rea1);

	Contract* contract1 = new Contract(rea1, "2024-07-01", "Vente", "Termes du contrat", 100000);
	client1->add_contract(contract1);
	owner1->add_contract(contract1);

	menu();
}

void menu() {
	do
	{
		Itf::space();
		Itf::title("MENU");

		vector<string> choices;
		choices = {
			"Ajouter une personne",
			"Lister les personne",
			"Ajouter un bien immobilier",
			"Lister les bien immobilier",
			"Créer un contrat",
			"Enregistrer une transaction",
			"Quitter",
		};
		Itf::choice_field(choices);
		int choice = Itf::num_input<int>(0, choices.size());

		if (choice == 7)
		{
			Itf::space();
			Itf::confirm("Au revoir!");
			break;
		}

		switch (choice)
		{
		case 1:
		{
			Person* per = person_creation();
			if (per == nullptr)
			{
				Itf::back();
				continue;
			}
			agency.add_person(per);
			break;
		}
		case 2:
			person_list();
			break;
		case 3: 
		{
			RealEstate* rea = property_creation();
			if (rea == nullptr)
			{
				Itf::back();
				continue;
			}
			agency.add_property(rea);
			Itf::confirm("Propriété ajouté!");
			break;
		}
		case 4:
			property_list();
			break;
		case 5:
			agency.create_contract();
			break;
		case 6:
			agency.save_transaction();
			break;
		}

	} while (true);
}

RealEstate* property_creation() 
{
	Itf::space();
	Itf::title("NOUVEAU BIEN IMMOBILIER");



	vector<string> types;
	types =
	{
		"Appartement",
		"Maison",
		"Terrain",
		"Annuler"
	};
	Itf::choice_field("Type", types);
	int type = Itf::num_input<int>(1, types.size());

	if (type == types.size()) return nullptr;

	cout << endl;

	Itf::subtitle("Informations");

	Person* person = nullptr;
	if (types[type - 1] == "Appartement")
	{
		person = person_choice("Propriétaire");
	}

	Itf::text_field("Adresse");
	string address = Itf::text_input(1, -1);

	Itf::text_field("Surface");
	double surface = Itf::num_input<double>(5, -1);

	cout << endl;

	Itf::subtitle("Resume");
	if (person != nullptr)
	{
		Itf::display_value("Propriétaire", person->get_name());
	}
	Itf::display_value("Adresse", address);
	Itf::display_value("Surface", to_string(surface));
	Itf::display_value("Type", types[type - 1]);

	cout << endl;

	Itf::choice_field("Action", {"Sauvegarder", "Annuler"});
	int action = Itf::num_input<int>(1, 2);

	if (action == 2) return nullptr;

	switch (type)
	{
	case 1:
		return new Apartment(person, address, surface, types[type - 1]);
	}

	return new RealEstate(address, surface, types[type - 1]);
}

Person* person_creation() 
{
	Itf::space();
	Itf::title("NOUVELLE PERSONNE");

	vector<string> types;

	types =
	{
		"Client",
		"Propriétaire",
		"Locataire",
		"Annuler"
	};
	Itf::choice_field("Type", types);
	int type = Itf::num_input<int>(1, types.size());

	if (type == types.size()) return nullptr;

	string name, address, phone;

	cout << endl;

	Itf::subtitle("Informations");

	Itf::text_field("Nom");
	name = Itf::text_input(1, -1);

	Itf::text_field("Adresse");
	address = Itf::text_input(1, -1);

	Itf::text_field("Numéro de téléphone");
	phone = Itf::text_input(1, -1);

	cout << endl;

	Itf::subtitle("Resume");
	Itf::display_value("Type", types[type - 1]);
	Itf::display_value("Nom", name);
	Itf::display_value("Adresse", address);
	Itf::display_value("Numéro", phone);

	cout << endl;

	Itf::choice_field("Action", {"Sauvegarder", "Annuler"});
	int action = Itf::num_input<int>(1, 2);

	if (action == 2) return nullptr;

	switch (type)
	{
	case 1:
		return new Client(name, address, phone);
		break;
	case 2:
		return new Owner(name, address, phone);
		break;
	case 3:
		return new Tenant(name, address, phone);
		break;
	}
}

void person_list() {
	Itf::space();
	Itf::title("LISTE DES PERSONNES");

	vector<string> filters = {
		"Client",
		"Propriétaire",
		"Locataire",
		"Annuler"
	};

	Itf::choice_field("Filtre", filters);
	int filter = Itf::num_input<int>(1, filters.size());

	if (filter == filters.size())
	{
		Itf::back();
		return;
	}

	cout << endl;

	Itf::subtitle(filters[filter - 1]);
	vector<Person*> filtered = agency.filter_persons(filters[filter - 1]);
	Itf::detailed_list<Person>(filtered);
}

Person* person_choice(const string& filter) {

	Itf::subtitle("Choix du " + filter);
	vector<Person*> filtered = agency.filter_persons(filter);
	Itf::detailed_list<Person>(filtered);

	cout << endl;

	Itf::text_field("Choix");
	int choice = Itf::num_input<int>(1, filtered.size());

	return filtered[choice - 1];
}

void property_list() {
	Itf::space();
	Itf::title("LISTE DES PROPRIÉTÉS");

	vector<string> filters = {
		"Appartement",
		"Maison",
		"Terrain",
		"Annuler"
	};

	Itf::choice_field("Filtre", filters);
	int filter = Itf::num_input<int>(1, filters.size());

	if (filter == filters.size())
	{
		Itf::back();
		return;
	}

	cout << endl;

	Itf::subtitle(filters[filter - 1]);
	vector<RealEstate*> filtered = agency.filter_properties(filters[filter - 1]);
	Itf::detailed_list<RealEstate>(filtered);
}

RealEstate* property_choice(const string& filter) {

	Itf::subtitle("Choix du " + filter);
	vector<RealEstate*> filtered = agency.filter_properties(filter);
	Itf::detailed_list<RealEstate>(filtered);

	cout << endl;

	Itf::text_field("Choix");
	int choice = Itf::num_input<int>(1, filtered.size());

	return filtered[choice - 1];
}