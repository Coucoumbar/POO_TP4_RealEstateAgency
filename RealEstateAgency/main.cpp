// Fait par : Mathias Lavoie & Nathan Morasse

#include <iostream>
#include <windows.h>

#include "Agency.h"
#include "Contract.h"
#include "Interface.hpp"
#include "Transaction.h"

#include "Apartment.h"
#include "House.h"
#include "Land.h"

#include "Client.h"
#include "Tenant.h"
#include "Owner.h"

using namespace std;
using Itf = Interface;

Agency agency;

void menu();


Person* person_creation();
void person_list();
Person* person_choice(const string&);

RealEstate* property_creation();
void property_list();
RealEstate* property_choice(const string&, const string&);

Contract* contract_creation();
void contract_list();
Contract* contract_choice(const vector<Contract*>&);
Contract* contract_sign();


int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	// Initial Data

	Client* client1 = new Client("Jean Dupont", "123 Rue Principale", "418-456-1234");
	agency.add_person(client1);
	Client* client2 = new Client("Yvon Tremblay", "43 Rue Secondaire", "654-623-6483");
	agency.add_person(client2);

	Owner* owner1 = new Owner("Alice Martin", "789 Boulevard des Fleurs", "555-123-4567");
	agency.add_person(owner1);
	Owner* owner2 = new Owner("Martin Pecheur", "2937 Avenue des Pins", "525-243-5452");
	agency.add_person(owner2);

	Tenant* tenant1 = new Tenant("Martin Pecheur", "2937 Avenue des Pins", "525-243-5452");
	agency.add_person(tenant1);

	House* rea1 = new House(owner2, "693 Rabelais", 200, "Maison");
	agency.add_property(rea1);
	Apartment* rea2 = new Apartment(owner1, "201 Bernard", 10.5, "Appartement");
	agency.add_property(rea2);
	Land* rea3 = new Land(owner2, "164 Camion", 30, "Terrain");
	agency.add_property(rea3);
	House* rea4 = new House(owner1, "222 Lac", 2000, "Maison");
	agency.add_property(rea4);

	owner1->add_ownership(rea1);

	Contract* contract1 = new Contract(rea1, "2024-07-01", "Vente", "Termes du contrat", 100000, owner1);
	client1->add_contract(contract1);
	owner1->add_contract(contract1);
	agency.add_contract(contract1);

	menu();
}

//Main menu of the application
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
			"Lister les contrats",
			"Signer un contrat",
			"Quitter",
		};
		Itf::choice_field(choices);
		int choice = Itf::num_input<int>(0, choices.size());

		if (choice == choices.size())
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
			if (per != nullptr)
			{
				agency.add_person(per);
				Itf::confirm("Personne ajouté!");
			}
			break;
		}
		case 2:
			person_list();
			break;
		case 3:
		{
			RealEstate* rea = property_creation();
			if (rea != nullptr)
			{
				agency.add_property(rea);
				Itf::confirm("Propriété ajouté!");
			}
			break;
		}
		case 4:
			property_list();
			break;
		case 5: {
			Contract* con = contract_creation();
			if (con != nullptr)
			{
				agency.add_contract(con);
				Itf::confirm("Contrat ajouté!");
			}
			break;
		}
		case 6:
			contract_list();
			break;
		case 7:
		{
			Contract* con = contract_sign();
			if (con != nullptr)
			{
				Transaction* tra = new Transaction(con);
				tra->process(agency);
				if (tra->is_processed())
				{
					Itf::confirm("Transaction complétée!");
				}
			}
			break;
		}
		}

	} while (true);
}



//[PROPERTIES]

//Menu for the addition of a new property
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

	if (type == types.size()) {
		Itf::back();
		return nullptr;
	}

	cout << endl;

	Itf::subtitle("Informations");

	if (!agency.has_person("Propriétaire"))
	{
		Itf::error("Aucun propriétaire enregistré. Operation annulée.");
		Itf::back();
		return nullptr;
	}

	Owner* owner = dynamic_cast<Owner*>(person_choice("Propriétaire"));

	Itf::text_field("Adresse");
	string address = Itf::text_input(1, -1);

	Itf::text_field("Surface");
	double surface = Itf::num_input<double>(5, -1);

	cout << endl;

	Itf::subtitle("Resume");
	Itf::display_value("Propriétaire", owner->get_name());
	Itf::display_value("Adresse", address);
	Itf::display_value("Surface", to_string(surface));
	Itf::display_value("Type", types[type - 1]);

	cout << endl;

	Itf::choice_field("Action", {"Sauvegarder", "Annuler"});
	int action = Itf::num_input<int>(1, 2);

	if (action == 2) {
		Itf::back();
		return nullptr;
	}

	switch (type)
	{
	case 1:
		return new Apartment(owner, address, surface, types[type - 1]);
	case 2:
		return new House(owner, address, surface, types[type - 1]);
	case 3:
		return new Land(owner, address, surface, types[type - 1]);
	}
}

//Displays the different properties in the application
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
	vector<RealEstate*> filtered = agency.filter_properties(filters[filter - 1], "");
	Itf::detailed_list<RealEstate>(filtered);
}

//Menu for the selection of a property
RealEstate* property_choice(const vector<RealEstate*>& available) {

	Itf::subtitle("Choix de propriété");
	Itf::detailed_list<RealEstate>(available);

	cout << endl;

	Itf::text_field("Choix");
	int choice = Itf::num_input<int>(1, available.size());

	return available[choice - 1];
}



//[PERSONS]

//Menu for the addition of a new person
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

//Displays the different persons in the application
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

//Menu for the selection of a person
Person* person_choice(const string& filter) {

	Itf::subtitle("Choix du " + filter);
	vector<Person*> filtered = agency.filter_persons(filter);
	Itf::detailed_list<Person>(filtered);

	cout << endl;

	Itf::text_field("Choix");
	int choice = Itf::num_input<int>(1, filtered.size());

	return filtered[choice - 1];
}



//[CONTRACTS]

//Menu for the addition of a new contract
Contract* contract_creation() {
	Itf::space();
	Itf::title("NOUVEAU CONTRAT");

	vector<string> types = {
		"Location",
		"Vente",
		"Annuler"
	};
	Itf::choice_field("Type de contrat", types);
	int type = Itf::num_input<int>(1, types.size());

	if (type == types.size()) {
		Itf::back();
		return nullptr;
	}

	if (!agency.has_person("Propriétaire"))
	{
		Itf::error("Aucun propriétaire enregistré. Operation annulée.");
		Itf::back();
		return nullptr;
	}

	cout << endl;

	Owner* owner = dynamic_cast<Owner*>(person_choice("Propriétaire"));

	vector<RealEstate*> available;
	if (type == 1)
	{
		available = agency.filter_properties(owner->get_owned(), "Appartement", "Non-vendu");
	}
	else
	{
		available = agency.filter_properties(owner->get_owned(), "", "Non-vendu");
	}

	if (available.empty())
	{
		Itf::error("Aucune propriété de " + types[type - 1] + " enregistrée. Opération annulée.");
		Itf::back();
		return nullptr;
	}

	cout << endl;

	RealEstate* property = property_choice(available);

	if (type == 1) Itf::text_field("Prix du loyer");
	else if (type == 2) Itf::text_field("Prix du bien");
	double price = Itf::num_input<double>(0, -1);

	Itf::text_field("Date (JJ-MM-AAAA)");
	string date = Itf::text_input(10, 10);

	Itf::text_field("Termes du contrat");
	string terms = Itf::text_input(0, -1);

	cout << endl;

	Itf::subtitle("Résumé");
	Itf::display_value("Type", types[type - 1]);
	Itf::display_value("Propriété", property->get_address() + " (" + property->get_id() + ")");
	Itf::display_value("Propriétaire", owner->get_name() + " (" + owner->get_id() + ")");
	Itf::display_value("Prix", to_string(price));
	Itf::display_value("Date", date);
	Itf::display_value("Termes", terms);

	cout << endl;

	Itf::choice_field("Action", { "Sauvegarder", "Annuler" });
	int action = Itf::num_input<int>(1, 2);

	if (action == 2) { 
		Itf::back();
		return nullptr; 
	}

	Contract* c = new Contract(property, date, types[type - 1], terms, price, owner);
	owner->add_contract(c);
	
	return  c;
}

//Displays the different contracts in the application
void contract_list(){
	Itf::space();
	Itf::title("LISTE DES CONTRATS");

	vector<Contract*> contracts = agency.get_contracts();

	Itf::detailed_list<Contract>(contracts);
}

//Menu for the selection of a contract
Contract* contract_choice(const vector<Contract*>& available) {
	Itf::subtitle("Choix de contrat");
	Itf::detailed_list<Contract>(available);

	cout << endl;

	Itf::text_field("Choix");
	int choice = Itf::num_input<int>(1, available.size());

	return available[choice - 1];
}

////Menu for the signature of a contract
Contract* contract_sign() {
	Itf::space();
	Itf::title("SIGNATURE DE CONTRAT");

	if (!agency.has_contract("", "En attente"))
	{
		Itf::error("Aucun contrat en attente. Operation annulée.");
		Itf::back();
		return nullptr;
	}

	vector<Contract*> pending = agency.filter_contracts("", "En attente");
	Contract* contract = contract_choice(pending);
	pending.clear();

	Person* person;

	if (contract->get_type() == "Location")
	{
		if (!agency.has_person("Locataire"))
		{
			Itf::error("Aucun locataire enregistré. Operation annulée.");
			Itf::back();
			return nullptr;
		}

		person = person_choice("Locataire");
	}
	else
	{
		if (!agency.has_person("Client"))
		{
			Itf::error("Aucun client enregistré. Operation annulée.");
			Itf::back();
			return nullptr;
		}

		person = person_choice("Client");
	}

	string owner = contract->get_owner()->get_name();

	Itf::display_value("Propriétaire du contrat", owner);
	Itf::text_field("Réécrire le nom pour confirmer");
	if (Itf::text_input(1, -1) != owner)
	{
		Itf::error("Nom incorrect. Operation annulée.");
		Itf::back();
		return nullptr;
	}

	try
	{
		contract->sign();
	}
	catch (const std::exception& e)
	{
		Itf::error(e.what());
		Itf::back();
		return nullptr;
	}

	contract->set_client(person);
	person->add_contract(contract);

	Itf::confirm("Contrat signé!");

	return contract;
}