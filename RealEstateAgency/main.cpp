// Fait par : Mathias Lavoie & Nathan Morasse

#include <iostream>

#include "Agency.h"

using namespace std;

int main()
{
	// Initial Data
	Agency agency;

	RealEstate real_estate1 = RealEstate("693 Rabelais", 200, "Maison");
	agency.add_real_estate(real_estate1);
	agency.add_real_estate({ "603 Avion", 10.5, "Appartement" });
	agency.add_real_estate({ "207 Bateau", 30, "Terrain" });
	agency.add_real_estate({ "1369 Bernard", 1000, "Maison" });

	Client* client1 = new Client("Jean Dupont", "123 Rue Principale", "418-456-1234");
	agency.add_client(client1);
	Client* client2 = new Client("Yvon Tremblay", "43 Rue Secondaire", "654-623-6483");
	agency.add_client(client2);

	Owner* owner1 = new Owner("Alice Martin", "789 Boulevard des Fleurs", "555-123-4567");
	agency.add_owner(owner1);
	Owner* owner2 = new Owner("Martin Pecheur", "2937 Avenue des Pins", "525-243-5452");
	agency.add_owner(owner2);

	owner1->add_ownership(&real_estate1);

	Contract* contract1 = new Contract(&real_estate1, "2024-07-01", "Vente", "Termes du contrat");
	client1->add_contract(contract1);
	owner1->add_contract(contract1);
	do
	{
		cout << "\n\n ===== MENU =====\n\n";

		cout
			<< " [1] Ajouter une personne.\n"
			<< " [2] Lister les personne.\n"
			<< " [3] Ajouter un bien immobilier\n"
			<< " [4] Lister les bien immobilier\n"
			<< " [5] Creer un contrat\n"
			<< " [6] Enregistrer une transaction\n"
			<< " [0] Quitter\n";

		cout << "\nEntrez votre choix : ";

		int choice;

		while (!(cin >> choice) || choice < 0 || choice > 6) {
			cout << "\nChoix invalide! Veuillez reessayer." << endl;
			cout << "Entrez votre choix : ";

			cin.clear();
			cin.ignore(10000, '\n');
		}

		if (choice == 0) 
		{
			cout << "\nAu revoir!\n";
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
			agency.create_real_estate();
			break;
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
