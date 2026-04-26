#include "Agency.h"

Agency::Agency() {

}

Agency::~Agency() {
	for (auto c : clients) delete c;
	for (auto o : owners) delete o;
	for (auto t : tenants) delete t;
	for (auto ct : contracts) delete ct;
	for (auto tr : transactions) delete tr;
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
	int type_choice;
	cout << "\n\n ===== NOUVELLE PERSONNE =====\n\n";
	cout << " [1] Client\n";
	cout << " [2] Proprietaire\n";
	cout << " [3] Locataire\n";
	cout << " [0] Annuler\n";
	cout << " Choix : ";

	while (!(cin >> type_choice) || type_choice < 0 || type_choice > 3)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << " *Entrez un choix valide : ";
	}
	cin.ignore(INT_MAX, '\n');

	if (type_choice == 0) return;

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

	switch (type_choice)
	{
		case 1:
		{
			Client* new_client = new Client(name, address, phone);
			clients.push_back(new_client);
			cout << "\n Client " << new_client->get_id() << " (" << new_client->get_name() << ") cree avec succes.\n";
			break;
		}
		case 2:
		{
			Owner* new_owner = new Owner(name, address, phone);
			owners.push_back(new_owner);
			cout << "\n Proprietaire " << new_owner->get_id() << " (" << new_owner->get_name() << ") cree avec succes.\n";
			break;
		}
		case 3:
		{
			Tenant* new_tenant = new Tenant(name, address, phone);
			tenants.push_back(new_tenant);
			cout << "\n Locataire " << new_tenant->get_id() << " (" << new_tenant->get_name() << ") cree avec succes.\n";
			break;
		}
	}
}

void Agency::create_contract()
{
	cout << "\n\n ===== NOUVEAU CONTRAT =====\n\n";

	// Select contract type
	int type_contract;
	cout << " Type de contrat :\n";
	cout << " [1] Location\n";
	cout << " [2] Vente\n";
	cout << " [0] Annuler\n";
	cout << " Choix : ";
	while (!(cin >> type_contract) || type_contract < 0 || type_contract > 2)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << " *Entrez un choix valide : ";
	}
	cin.ignore(INT_MAX, '\n');
	if (type_contract == 0) return;
	string type_str = (type_contract == 1) ? "Location" : "Vente";

	// Select a client
	if (clients.empty()) {
		cout << " Aucun client enregistre. Operation annulee.\n";
		return;
	}
	cout << "\n Clients disponibles :\n";
	for (size_t i = 0; i < clients.size(); ++i)
		cout << " [" << (i + 1) << "] " << clients[i]->get_name() << " (" << clients[i]->get_id() << ")\n";
	size_t client_index;
	cout << " Choisissez un client (1.." << clients.size() << ") : ";
	while (!(cin >> client_index) || client_index < 1 || client_index > clients.size())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << " *Entrez un indice valide : ";
	}
	cin.ignore(INT_MAX, '\n');
	Client* selected_client = clients[client_index - 1];

	// Select an owner
	if (owners.empty()) {
		cout << " Aucun proprietaire enregistre. Operation annulee.\n";
		return;
	}
	cout << "\n Proprietaires disponibles :\n";
	for (size_t i = 0; i < owners.size(); ++i)
		cout << " [" << (i + 1) << "] " << owners[i]->get_name() << " (" << owners[i]->get_id() << ")\n";
	size_t owner_index;
	cout << " Choisissez un proprietaire (1.." << owners.size() << ") : ";
	while (!(cin >> owner_index) || owner_index < 1 || owner_index > owners.size())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << " *Entrez un indice valide : ";
	}
	cin.ignore(INT_MAX, '\n');
	Owner* selected_owner = owners[owner_index - 1];

	// Select a real estate
	// Filter real estates with the status "Non-vendu"
	vector<RealEstate*> available;
	for (size_t i = 0; i < real_estates.size(); ++i)
		if (real_estates[i].get_status() == "Non-vendu")
			available.push_back(&real_estates[i]);

	if (available.empty()) {
		cout << " Aucun bien disponible pour le moment. Operation annulee.\n";
		return;
	}
	cout << "\n Biens disponibles :\n";
	for (size_t i = 0; i < available.size(); ++i)
		cout << " [" << (i + 1) << "] " << available[i]->get_address() << " (" << available[i]->get_type() << ", " << available[i]->get_surface() << " m2)\n";
	size_t real_estate_index;
	cout << " Choisissez un bien (1.." << available.size() << ") : ";
	while (!(cin >> real_estate_index) || real_estate_index < 1 || real_estate_index > available.size())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << " *Entrez un indice valide : ";
	}
	cin.ignore(INT_MAX, '\n');
	RealEstate* selected_real_estate = available[real_estate_index - 1];

	// Select date and terms
	string date;
	cout << "\n Date du contrat (AAAA-MM-JJ) : ";
	getline(cin, date);
	while (date.empty())
	{
		cout << "  (La date ne peut etre vide) - Date : ";
		getline(cin, date);
	}
	string terms;
	cout << " Termes du contrat : ";
	getline(cin, terms);
	while (terms.empty())
	{
		cout << "  (Les termes ne peuvent etre vides) - Termes : ";
		getline(cin, terms);
	}

	// Confirmation
	cout << "\n Resume du contrat :\n";
	cout << " Type         : " << type_str << endl;
	cout << " Client       : " << selected_client->get_name() << " (" << selected_client->get_id() << ")\n";
	cout << " Proprietaire : " << selected_owner->get_name() << " (" << selected_owner->get_id() << ")\n";
	cout << " Bien         : " << selected_real_estate->get_address() << " (" << selected_real_estate->get_id() << ")\n";
	cout << " Date         : " << date << endl;
	cout << " Termes       : " << terms << endl;
	cout << "\n [1] Confirmer\n [0] Annuler\n Choix : ";
	int confirm;
	while (!(cin >> confirm) || confirm < 0 || confirm > 1)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << " *Choix invalide : ";
	}
	cin.ignore(INT_MAX, '\n');
	if (confirm == 0) {
		cout << " Creation annulee.\n";
		return;
	}

	// Create the contract and link it to the client and owner
	Contract* new_contract = nullptr;
	try {
		new_contract = new Contract(selected_real_estate, date, type_str, terms);
		contracts.push_back(new_contract);
		selected_client->add_contract(new_contract);
		selected_owner->add_contract(new_contract);
		cout << "\n Contrat " << new_contract->get_id() << " cree avec succes.\n";
	}
	catch (const exception& e) {
		cout << " Erreur lors de la creation du contrat : " << e.what() << endl;
		delete new_contract;
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

void Agency::save_transaction() {

}

void Agency::sign_contract()
{

}