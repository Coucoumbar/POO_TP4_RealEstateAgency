#include "Agency.h"

Agency::Agency() {

}

Agency::~Agency() {
	for (auto rea : properties) delete rea;
	for (auto per : persons) delete per;
	for (auto con : contracts) delete con;
	for (auto tra : transactions) delete tra;
}

//void Agency::create_contract()
//{
//	cout << "\n\n ===== NOUVEAU CONTRAT =====\n\n";
//
//	// Select contract type
//	int type_contract;
//	cout << " Type de contrat :\n";
//	cout << " [1] Location\n";
//	cout << " [2] Vente\n";
//	cout << " [0] Annuler\n";
//	cout << " Choix : ";
//	while (!(cin >> type_contract) || type_contract < 0 || type_contract > 2)
//	{
//		cin.clear();
//		cin.ignore(INT_MAX, '\n');
//		cout << " *Entrez un choix valide : ";
//	}
//	cin.ignore(INT_MAX, '\n');
//	if (type_contract == 0) return;
//	string type_str = (type_contract == 1) ? "Location" : "Vente";
//
//	// Select an owner
//	if (owners.empty()) {
//		cout << " Aucun proprietaire enregistre. Operation annulee.\n";
//		return;
//	}
//	cout << "\n Proprietaires disponibles :\n";
//	for (size_t i = 0; i < owners.size(); ++i)
//		cout << " [" << (i + 1) << "] " << owners[i]->get_name() << " (" << owners[i]->get_id() << ")\n";
//	size_t owner_index;
//	cout << " Choisissez un proprietaire (1.." << owners.size() << ") : ";
//	while (!(cin >> owner_index) || owner_index < 1 || owner_index > owners.size())
//	{
//		cin.clear();
//		cin.ignore(INT_MAX, '\n');
//		cout << " *Entrez un indice valide : ";
//	}
//	cin.ignore(INT_MAX, '\n');
//	Owner* selected_owner = owners[owner_index - 1];
//
//	// Select a real estate
//	// Filter real estates with the status "Non-vendu"
//	vector<RealEstate*> owned_properties = selected_owner->get_owned();
//	vector<RealEstate*> available;
//	for (size_t i = 0; i < owned_properties.size(); ++i)
//		if (owned_properties[i]->get_status() == "Non-vendu")
//			available.push_back(owned_properties[i]);
//
//	if (available.empty()) {
//		cout << " Aucun bien disponible pour le moment. Operation annulee.\n";
//		return;
//	}
//	cout << "\n Biens disponibles :\n";
//	for (size_t i = 0; i < available.size(); ++i)
//		cout << " [" << (i + 1) << "] " << available[i]->get_address() << " (" << available[i]->get_type() << ", " << available[i]->get_surface() << " m2)\n";
//	size_t real_estate_index;
//	cout << " Choisissez un bien (1.." << available.size() << ") : ";
//	while (!(cin >> real_estate_index) || real_estate_index < 1 || real_estate_index > available.size())
//	{
//		cin.clear();
//		cin.ignore(INT_MAX, '\n');
//		cout << " *Entrez un indice valide : ";
//	}
//	cin.ignore(INT_MAX, '\n');
//	RealEstate* selected_real_estate = available[real_estate_index - 1];
//
//	// Set the price
//	double price;
//	if (type_contract == 1)
//	{
//		cout << "\n Prix mensuel du loyer : ";
//	}
//	else if (type_contract == 2)
//	{
//		cout << "\n Prix de la propriété : ";
//	}
//	while (!(cin >> price) || price <= 0)
//	{
//		cin.clear();
//		cin.ignore(INT_MAX, '\n');
//		cout << " *Entrez un prix valide : ";
//	}
//	cin.ignore(INT_MAX, '\n');
//
//	// Select date and terms
//	string date;
//	cout << "\n Date du contrat (AAAA-MM-JJ) : ";
//	getline(cin, date);
//	while (date.empty())
//	{
//		cout << "  (La date ne peut etre vide) - Date : ";
//		getline(cin, date);
//	}
//	string terms;
//	cout << " Termes du contrat : ";
//	getline(cin, terms);
//	while (terms.empty())
//	{
//		cout << "  (Les termes ne peuvent etre vides) - Termes : ";
//		getline(cin, terms);
//	}
//
//	// Confirmation
//	cout << "\n Resume du contrat :\n";
//	cout << " Type         : " << type_str << endl;
//	cout << " Proprietaire : " << selected_owner->get_name() << " (" << selected_owner->get_id() << ")\n";
//	cout << " Bien         : " << selected_real_estate->get_address() << " (" << selected_real_estate->get_id() << ")\n";
//	cout << " Prix         : " << price << "$" << endl;
//	cout << " Date         : " << date << endl;
//	cout << " Termes       : " << terms << endl;
//	cout << "\n [1] Confirmer\n [0] Annuler\n Choix : ";
//	int confirm;
//	while (!(cin >> confirm) || confirm < 0 || confirm > 1)
//	{
//		cin.clear();
//		cin.ignore(INT_MAX, '\n');
//		cout << " *Choix invalide : ";
//	}
//	cin.ignore(INT_MAX, '\n');
//	if (confirm == 0) {
//		cout << " Creation annulee.\n";
//		return;
//	}
//
//	// Create the contract and link it to the client and owner
//	Contract* new_contract = nullptr;
//	try {
//		new_contract = new Contract(selected_real_estate, date, type_str, terms, price);
//		contracts.push_back(new_contract);
//		selected_owner->add_contract(new_contract);
//		cout << "\n Contrat " << new_contract->get_id() << " cree avec succes.\n";
//	}
//	catch (const exception& e) {
//		cout << " Erreur lors de la creation du contrat : " << e.what() << endl;
//		delete new_contract;
//	}
//}

void Agency::add_property(RealEstate* content) {
	properties.push_back(content);
}

void Agency::add_person(Person* content) {
	persons.push_back(content);
}

void Agency::add_contract(Contract* content) {
	contracts.push_back(content);
}

void Agency::save_transaction(Transaction* new_transaction) {
	try {
		transactions.push_back(new_transaction);
		cout << " Transaction " << new_transaction->get_id() << " enregistrée.\n";
	}
	catch (const exception& e) {
		cout << " Erreur lors de l'enregistrement de la transaction : " << e.what() << endl;
		delete new_transaction;
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

vector<RealEstate*> Agency::filter_properties(const string& filter, const string& status) {
	vector<RealEstate*> filtered;

	for (RealEstate* p : properties)
	{
		if (
			(p->get_type() == filter || filter.empty()) 
			&& 
			(p->get_status() == status || status.empty())) 
			filtered.push_back(p);
	}

	return filtered;
}
vector<RealEstate*> Agency::filter_properties(const vector<RealEstate*>& values, const string& filter, const string& status) {
	vector<RealEstate*> filtered;

	for (RealEstate* p : values)
	{
		if (
			(p->get_type() == filter || filter.empty())
			&&
			(p->get_status() == status || status.empty()))
			filtered.push_back(p);
	}

	return filtered;
}

vector<Contract*> Agency::filter_contracts(const string& filter, const string& status) {
	vector<Contract*> filtered;

	for (Contract* p : contracts)
	{
		if (
			(p->get_type() == filter || filter.empty())
			&&
			(p->get_status() == status || status.empty()))
			filtered.push_back(p);
	}

	return filtered;
}

bool Agency::has_person(const string& filter) const {
	for (Person* p : persons)
	{
		if (p->get_type() == filter) return true;
	}

	return false;
}

bool Agency::has_property(const string& filter, const string& status) const {
	for (RealEstate* p : properties)
	{
		if (
			(p->get_type() == filter || filter.empty())
			&&
			(p->get_status() == status || status.empty())) 
			return true;
	}

	return false;
}

bool Agency::has_contract(const string& filter, const string& status) const {
	for (Contract* c : contracts)
	{
		if (
			(c->get_type() == filter || filter.empty())
			&&
			(c->get_status() == status || status.empty()))
			return true;
	}

	return false;
}

vector<Contract*> Agency::get_contracts() const {
	return contracts;
}