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

void Agency::create_person()
{
	int typeChoice;
	cout << "\n\n ===== NOUVELLE PERSONNE =====\n\n";
	cout << " [1] Client\n";
	cout << " [2] Proprietaire\n";
	cout << " [3] Locataire\n";
	cout << " [0] Annuler\n";
	cout << " Choix : ";

	while (!(cin >> typeChoice) || typeChoice < 0 || typeChoice > 3)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << " *Entrez un choix valide : ";
	}
	cin.ignore(INT_MAX, '\n');

	if (typeChoice == 0) return;

	string name, address, phone;

	cout << "\n Informations\n";
	cout << " - Nom : ";
	getline(cin, name);
	while (name.empty())
	{
		cout << "   (Le nom ne peut pas etre vide) - Nom : ";
		getline(cin, name);
	}

	cout << " - Adresse : ";
	getline(cin, address);
	while (address.empty())
	{
		cout << "   (L'adresse ne peut pas etre vide) - Adresse : ";
		getline(cin, address);
	}

	cout << " - Telephone : ";
	getline(cin, phone);
	while (phone.empty())
	{
		cout << "   (Le telephone ne peut pas etre vide) - Telephone : ";
		getline(cin, phone);
	}

	switch (typeChoice)
	{
		case 1:
		{
			Client* newClient = new Client(name, address, phone);
			clients.push_back(newClient);
			cout << "\n Client " << newClient->get_id() << " (" << newClient->get_name() << ") cree avec succes.\n";
			break;
		}
		case 2:
		{
			Owner* newOwner = new Owner(name, address, phone);
			owners.push_back(newOwner);
			cout << "\n Proprietaire " << newOwner->get_id() << " (" << newOwner->get_name() << ") cree avec succes.\n";
			break;
		}
		case 3:
		{
			Tenant* newTenant = new Tenant(name, address, phone);
			tenants.push_back(newTenant);
			cout << "\n Locataire " << newTenant->get_id() << " (" << newTenant->get_name() << ") cree avec succes.\n";
			break;
		}
	}
}

void Agency::add_real_estate(const RealEstate content) {
	real_estates.push_back(content);
}

void Agency::add_client(Client* client) {
	clients.push_back(client);
}

void Agency::add_owner(Owner* owner) {
		owners.push_back(owner);
}

void Agency::list_options() {
	cout << "\n\n ===== BIENS IMMOBILIERS =====\n\n";

	for (int i = 1; i <= real_estates.size(); i++)
	{
		cout << "\n [" << i << "]";
		real_estates[i - 1].display_details();
	}
}

void Agency::list_persons()
{
	cout << "\n\n ===== LISTE DES PERSONNES =====\n\n";

	// Clients
	cout << "--- Clients ---" << endl;
	if (clients.empty()) {
		cout << "Aucun client enregistre." << endl;
	}
	else {
		for (size_t i = 0; i < clients.size(); ++i)
		{
			cout << "[" << (i + 1) << "] ";
			clients[i]->display_info();
			cout << endl;
		}
	}

	// Propriétaires
	cout << "\n--- Proprietaires ---" << endl;
	if (owners.empty()) {
		cout << "Aucun proprietaire enregistre." << endl;
	}
	else {
		for (size_t i = 0; i < owners.size(); ++i)
		{
			cout << "[" << (i + 1) << "] ";
			owners[i]->display_info();
			cout << endl;
		}
	}

	// Locataires
	cout << "\n--- Locataires ---" << endl;
	if (tenants.empty()) {
		cout << "Aucun locataire enregistre." << endl;
	}
	else {
		for (size_t i = 0; i < tenants.size(); ++i)
		{
			cout << "[" << (i + 1) << "] ";
			tenants[i]->display_info();
			cout << endl;
		}
	}
}

void Agency::create_contract() {

}

void Agency::save_transaction() {

}