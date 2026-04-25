#include "Agency.h"

Agency::Agency() {

}

void Agency::create_real_estate() {
	cout << "\n\n ===== NOUVEAU BIEN IMMOBILIER =====\n\n";

	cout << " Informations" << endl;

	string address;
	cout << " - Adresse : ";
	while (!(cin >> address) || address.size() < 1)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\n  *Entrez une valeur valide : ";
	}

	cin.ignore(INT_MAX, '\n');

	double surface;
	cout << " - Surface : ";
	while (!(cin >> surface) || surface < 1)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\n  *Entrez une valeur valide : ";
	}

	cin.ignore(INT_MAX, '\n');

	int input;
	cout
		<< " - Type : \n"
		<< "   [1] Appartement\n"
		<< "   [2] Maison\n"
		<< "   [3] Terrain\n"
		<< "   Choix : ";
	while (!(cin >> input) || input < 1 || input > 3)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\n  *Entrez une valeur valide : ";
	}

	cin.ignore(INT_MAX, '\n');

	string type;
	if (input == 1) type = "Appartement";
	else if (input == 2) type = "Maison";
	else type = "Terrain";

	cout
		<< "\n Resume"
		<< "\n - Adresse : " << address
		<< "\n - Surface (m^2) : " << surface
		<< "\n - Type : " << type
		<< endl << endl;

	cout
		<< " [0] Annuler\n"
		<< " [1] Confirmer\n"
		<< " Choix : ";
	while (!(cin >> input) || input < 0 || input > 1)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\n *Entrez une valeur valide : ";
	}

	if (input == 0) return;

	add_real_estate({ address, surface, type });

	cout << endl << type << " (" << address << ") ajoute!";
}

void Agency::add_real_estate(const RealEstate content) {
	real_estates.push_back(content);
}

void Agency::add_client() {

}

void Agency::add_owner() {

}

void Agency::list_options() {
	cout << "\n\n ===== BIENS IMMOBILIERS =====\n\n";

	for (int i = 1; i <= real_estates.size(); i++)
	{
		cout << "\n [" << i << "]";
		real_estates[i - 1].display_details();
	}
}

void Agency::create_contract() {

}

void Agency::save_transaction() {

}