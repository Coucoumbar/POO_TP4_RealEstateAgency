// Fait par : Mathias Lavoie & Nathan Morasse

#include <iostream>
#include <windows.h>

#include "Agency.h"
#include "Interface.hpp"

using namespace std;
using Itf = Interface;

Agency agency;

void menu();
RealEstate* real_estate_creation();
Person* person_creation();


int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	// Initial Data
	

	RealEstate* rea1 = new RealEstate("693 Rabelais", 200, "Maison");
	agency.add_real_estate(rea1);
	RealEstate* rea2 = new RealEstate("201 Bernard", 10.5, "Appartement");
	agency.add_real_estate(rea1);
	RealEstate* rea3 = new RealEstate("164 Camion", 30, "Terrain");
	agency.add_real_estate(rea1);
	RealEstate* rea4 = new RealEstate("222 Lac", 2000, "Maison");
	agency.add_real_estate(rea1);

	Client* client1 = new Client("Jean Dupont", "123 Rue Principale", "418-456-1234");
	agency.add_client(client1);
	Client* client2 = new Client("Yvon Tremblay", "43 Rue Secondaire", "654-623-6483");
	agency.add_client(client2);

	Owner* owner1 = new Owner("Alice Martin", "789 Boulevard des Fleurs", "555-123-4567");
	agency.add_owner(owner1);
	Owner* owner2 = new Owner("Martin Pecheur", "2937 Avenue des Pins", "525-243-5452");
	agency.add_owner(owner2);

	owner1->add_ownership(rea1);

	Contract* contract1 = new Contract(rea1, "2024-07-01", "Vente", "Termes du contrat");
	client1->add_contract(contract1);
	owner1->add_contract(contract1);

	menu();
}

void menu() {
	do
	{
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
		int choice = Itf::num_input(0, 6);

		if (choice == 7)
		{
			Itf::title("Au revoir!");
			break;
		}

		switch (choice)
		{
		case 1:
			agency.create_person();
			break;
		case 2:
			agency.list_persons();
			break;
		case 3: 
		{
			RealEstate* rea = real_estate_creation();
			if (rea == nullptr)
			{
				Itf::back();
				continue;
			}
			agency.add_real_estate(rea);
			break;
		}
		case 4:
			agency.list_options();
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

RealEstate* real_estate_creation() 
{
	Itf::space();

	Itf::title("NOUVEAU BIEN IMMOBILIER");



	Itf::subtitle("Informations");

	Itf::text_field("Adresse");
	string address = Itf::text_input(1, -1);

	Itf::text_field("Surface");
	double surface = Itf::num_input<double>(5, -1);

	vector<string> choices;

	choices =
	{
		"Appartement",
		"Maison",
		"Terrain"
	};
	Itf::choice_field("Type", choices);
	string type = choices[Itf::num_input<int>(1, choices.size()) - 1];

	cout << endl;

	Itf::subtitle("Resume");
	Itf::display_value("Adresse", address);
	Itf::display_value("Surface", to_string(surface));
	Itf::display_value("Type", type);

	cout << endl;

	choices =
	{
		"Sauvegarder",
		"Annuler"
	};
	Itf::choice_field("Action", choices);
	int action = Itf::num_input<int>(1, choices.size());

	if (action == 2) return nullptr;

	return new RealEstate(address, surface, type);
}