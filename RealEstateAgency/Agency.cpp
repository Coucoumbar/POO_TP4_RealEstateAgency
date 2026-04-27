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

//void Agency::create_person()
//{
//	int type_choice;
//	cout << "\n\n ===== NOUVELLE PERSONNE =====\n\n";
//	cout << " [1] Client\n";
//	cout << " [2] Proprietaire\n";
//	cout << " [3] Locataire\n";
//	cout << " [0] Annuler\n";
//	cout << " Choix : ";
//
//	while (!(cin >> type_choice) || type_choice < 0 || type_choice > 3)
//	{
//		cin.clear();
//		cin.ignore(INT_MAX, '\n');
//		cout << " *Entrez un choix valide : ";
//	}
//	cin.ignore(INT_MAX, '\n');
//
//	if (type_choice == 0) return;
//
//	string name, address, phone;
//
//	cout << "\n Informations\n";
//	cout << " - Nom : ";
//	getline(cin, name);
//	while (name.empty())
//	{
//		cout << "   (Le nom ne peut pas etre vide) - Nom : ";
//		getline(cin, name);
//	}
//
//	cout << " - Adresse : ";
//	getline(cin, address);
//	while (address.empty())
//	{
//		cout << "   (L'adresse ne peut pas etre vide) - Adresse : ";
//		getline(cin, address);
//	}
//
//	cout << " - Telephone : ";
//	getline(cin, phone);
//	while (phone.empty())
//	{
//		cout << "   (Le telephone ne peut pas etre vide) - Telephone : ";
//		getline(cin, phone);
//	}
//
//	switch (type_choice)
//	{
//		case 1:
//		{
//			Client* new_client = new Client(name, address, phone);
//			clients.push_back(new_client);
//			cout << "\n Client " << new_client->get_id() << " (" << new_client->get_name() << ") cree avec succes.\n";
//			break;
//		}
//		case 2:
//		{
//			Owner* new_owner = new Owner(name, address, phone);
//			owners.push_back(new_owner);
//			cout << "\n Proprietaire " << new_owner->get_id() << " (" << new_owner->get_name() << ") cree avec succes.\n";
//			break;
//		}
//		case 3:
//		{
//			Tenant* new_tenant = new Tenant(name, address, phone);
//			tenants.push_back(new_tenant);
//			cout << "\n Locataire " << new_tenant->get_id() << " (" << new_tenant->get_name() << ") cree avec succes.\n";
//			break;
//		}
//	}
//}

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
	vector<RealEstate*> owned_properties = selected_owner->get_owned();
	vector<RealEstate*> available;
	for (size_t i = 0; i < owned_properties.size(); ++i)
		if (owned_properties[i]->get_status() == "Non-vendu")
			available.push_back(owned_properties[i]);

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

	// Set the price
	double price;
	if (type_contract == 1)
	{
		cout << "\n Prix mensuel du loyer : ";
	}
	else if (type_contract == 2)
	{
		cout << "\n Prix de la propriété : ";
	}
	while (!(cin >> price) || price <= 0)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << " *Entrez un prix valide : ";
	}
	cin.ignore(INT_MAX, '\n');

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
	cout << " Proprietaire : " << selected_owner->get_name() << " (" << selected_owner->get_id() << ")\n";
	cout << " Bien         : " << selected_real_estate->get_address() << " (" << selected_real_estate->get_id() << ")\n";
	cout << " Prix         : " << price << "$" << endl;
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
		new_contract = new Contract(selected_real_estate, date, type_str, terms, price);
		contracts.push_back(new_contract);
		selected_owner->add_contract(new_contract);
		cout << "\n Contrat " << new_contract->get_id() << " cree avec succes.\n";
	}
	catch (const exception& e) {
		cout << " Erreur lors de la creation du contrat : " << e.what() << endl;
		delete new_contract;
	}
}

void Agency::add_property(RealEstate* content) {
	properties.push_back(content);
}

void Agency::add_person(Person* content) {
	persons.push_back(content);
}

void Agency::add_client(Client* client) {
	clients.push_back(client);
}

void Agency::add_owner(Owner* owner) {
		owners.push_back(owner);
}

void Agency::list_options() {
	cout << "\n\n ===== BIENS IMMOBILIERS =====\n\n";

	for (int i = 1; i <= properties.size(); i++)
	{
		cout << "\n [" << i << "]";
		properties[i - 1]->display();
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
			clients[i]->display();
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
			owners[i]->display();
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
			tenants[i]->display();
			cout << endl;
		}
	}
}

void Agency::save_transaction() {

}

void Agency::sign_contract() {
	cout << "\n\n ===== SIGNATURE DE CONTRAT =====\n\n";

	// Select a pending contract
	vector<Contract*> pending;
	for (Contract* c : contracts) {
		if (c->get_status() == "En attente")
			pending.push_back(c);
	}
	if (pending.empty()) {
		cout << " Aucun contrat en attente de signature.\n";
		return;
	}

	cout << " Contrats en attente :\n";
	for (size_t i = 0; i < pending.size(); ++i) {
		Contract* c = pending[i];
		cout << " [" << (i + 1) << "] Contrat " << c->get_id()
			<< " | Type: " << c->get_type()
			<< " | Bien: " << c->get_property()->get_address()
			<< " | Proprietaire: " << (c->get_owner() ? c->get_owner()->get_name() : "Inconnu")
			<< " | Prix: " << c->get_price() << "$"
			<< " | Date: " << c->get_date() << endl;
	}

	size_t contract_index;
	cout << " Choisissez un contrat (1.." << pending.size() << ") : ";
	while (!(cin >> contract_index) || contract_index < 1 || contract_index > pending.size()) {
		cin.clear(); cin.ignore(INT_MAX, '\n');
		cout << " *Entrez un indice valide : ";
	}
	cin.ignore(INT_MAX, '\n');
	Contract* selected_contract = pending[contract_index - 1];

	// Select a client to sign the contract
	if (clients.empty()) {
		cout << " Aucun client enregistre. Operation annulee.\n";
		return;
	}
	cout << "\n Clients disponibles :\n";
	for (size_t i = 0; i < clients.size(); ++i)
		cout << " [" << (i + 1) << "] " << clients[i]->get_name() << " (" << clients[i]->get_id() << ")\n";
	size_t client_index;
	cout << " Choisissez le client signataire (1.." << clients.size() << ") : ";
	while (!(cin >> client_index) || client_index < 1 || client_index > clients.size()) {
		cin.clear(); cin.ignore(INT_MAX, '\n');
		cout << " *Entrez un indice valide : ";
	}
	cin.ignore(INT_MAX, '\n');
	Client* selected_client = clients[client_index - 1];

	// Owner signature confirmation
	Owner* current_owner = selected_contract->get_owner();
	if (!current_owner) {
		cout << " Contrat sans proprietaire. Annulation.\n";
		return;
	}
	cout << "\n Proprietaire du bien : " << current_owner->get_name() << endl;
	cout << " Veuillez réécrire le nom du proprietaire pour confirmer : ";
	string owner_name_input;
	getline(cin, owner_name_input);
	if (owner_name_input != current_owner->get_name()) {
		cout << " Nom incorrect. Signature annulee.\n";
		return;
	}

	// Change contract status to "Signé"
	try {
		selected_contract->sign();
	}
	catch (const exception& e) {
		cout << " Erreur : " << e.what() << endl;
		return;
	}

	// Update real estate status
	RealEstate* property = selected_contract->get_property();
	string contract_type = selected_contract->get_type();
	if (contract_type == "Vente") {
		property->update_status("Vendu");
	}
	else {
		property->update_status("En Location");
	}

	// Transfer ownership if it's a sale
	if (contract_type == "Vente") {
		// Remove ownership from the current owner
		current_owner->remove_ownership(property);

		// Create a new owner for the client (or find an existing one if the client is already an owner)
		Owner* target_owner = nullptr;
		// Search if the client is already an owner (same name, address, phone)
		for (Owner* o : owners) {
			if (o->get_name() == selected_client->get_name() &&
				o->get_address() == selected_client->get_address() &&
				o->get_phone() == selected_client->get_phone()) {
				target_owner = o;
				break;
			}
		}
		if (!target_owner) {
			// Create a new owner based on the client's info
			target_owner = new Owner(selected_client->get_name(),
				selected_client->get_address(),
				selected_client->get_phone());
			owners.push_back(target_owner);
		}
		// Add ownership and contract to the target owner
		target_owner->add_ownership(property);
		target_owner->add_contract(selected_contract);
		selected_contract->set_owner(target_owner);
	}
	else if (contract_type == "Location")
	{
		// Create a new tenant for the client (or find an existing one if the client is already a tenant)
		Tenant* target_tenant = nullptr;
		// Search if the client is already a tenant (same name, address, phone)
		for (Tenant* o : tenants) {
			if (o->get_name() == selected_client->get_name() &&
				o->get_address() == selected_client->get_address() &&
				o->get_phone() == selected_client->get_phone()) {
				target_tenant = o;
				break;
			}
		}
		if (!target_tenant) {
			// Create a new tenant based on the client's info
			target_tenant = new Tenant(selected_client->get_name(),
				selected_client->get_address(),
				selected_client->get_phone());
			tenants.push_back(target_tenant);
		}
		// Add tenancy and contract to the target tenant
		target_tenant->add_tenancy(property);
		target_tenant->add_contract(selected_contract);
	}

	// Link the contract to the client
	selected_contract->set_client(selected_client);
	selected_client->add_contract(selected_contract);

	// Create new transaction for this contract
	double price = selected_contract->get_price();
	string trans_type = (contract_type == "Location") ? "Loyer" : "Vente";
	Transaction* new_transaction = nullptr;
	try {
		new_transaction = new Transaction(price, selected_contract->get_date(), trans_type, selected_contract);
		transactions.push_back(new_transaction);
		cout << " Transaction " << new_transaction->get_id() << " enregistree.\n";
	}
	catch (const exception& e) {
		cout << " Erreur lors de l'enregistrement de la transaction : " << e.what() << endl;
		delete new_transaction;
	}

	cout << "\n Contrat " << selected_contract->get_id() << " signe avec succes.\n";
	cout << " Bien " << property->get_address() << " : " << property->get_status() << ".\n";
	if (contract_type == "Vente") {
		cout << " " << selected_client->get_name() << " devient proprietaire.\n";
	}
}

vector<Person*> Agency::filter_persons(const string& filter) {
	vector<Person*> filtered;

	for (Person* p : persons)
	{
		if (p->get_type() == filter) filtered.push_back(p);
	}

	return filtered;
}