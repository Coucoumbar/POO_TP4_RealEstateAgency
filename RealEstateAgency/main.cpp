// Fait par : Mathias Lavoie & Nathan Morasse

#include <iostream>

#include "Agency.h"

using namespace std;

int main()
{
	Agency agency;

	agency.add_real_estate({ "693 Rabelais", 200, "Maison" });
	agency.add_real_estate({ "603 Avion", 10.5, "Appartement" });
	agency.add_real_estate({ "207 Bateau", 30, "Terrain" });
	agency.add_real_estate({ "1369 Bernard", 1000, "Maison" });

	do
	{
		cout << "\n\n ===== MENU =====\n\n";

		cout
			<< " [1] Ajouter un client.\n"
			<< " [2] Ajouter un proprietaire.\n"
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
			agency.add_client();
			break;
		case 2:
			agency.add_owner();
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
