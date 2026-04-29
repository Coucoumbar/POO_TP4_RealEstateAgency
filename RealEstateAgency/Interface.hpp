#pragma once

#include <iostream>
#include <type_traits>
#include <concepts>
#include <vector>
#include <string>

using namespace std;

static class Interface
{
public:
	//Loops until the user enters a valid numeric value.
	template <typename T>
	static T num_input(T min, T max) {
		static_assert(is_arithmetic_v<T>, "Type must be numeric.");

		T value;

		if (max < 0) max = INT_MAX;
		
		while (!(cin >> value) || value < min || value > max)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			error("Entrez une valeur valide : ");
		}

		cin.ignore(INT_MAX, '\n');

		return value;
	}

	//Loops until the user enters a valid string.
	static string text_input(size_t min, size_t max) {
		string value;

		if (max < 0) max = INT_MAX;

		while (!getline(cin, value) || value.empty())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			error("Entrez une valeur valide : ");
		}

		return value;
	}

	//Display a section title.
	static void title(const string& text) {
		cout << "\033[96m" << " ===== " << text << " =====" << "\033[0m";
		space();
	}

	static void subtitle(const string& text) {
		cout << "\033[94m" << " --- " << text << " ---" << "\033[0m" << endl;
	}

	static void display_value(const string& name, const string& value) {
		cout << " - " << name << " : " << value << endl;
	}



	static void text_field(const string& message) {
		cout << " > " << message << " : ";
	}

	static void choice_field(const string& message, const vector<string>& choices) {
		if (!message.empty()) cout << " - " << message << " : " << endl;

		for (size_t i = 1; i <= choices.size(); i++)
		{
			cout << "   [" << i << "] " << choices[i-1] << endl;
		}

		cout << endl;

		text_field("Choix");
	}

	static void choice_field(const vector<string>& choices) {
		for (size_t i = 1; i <= choices.size(); i++)
		{
			cout << " [" << i << "] " << choices[i - 1] << endl;
		}

		cout << endl;

		text_field("Choix");
	}

	template <typename T>
	static void detailed_list(const vector<T*>& objects) {
		if (objects.empty()) 
		{
			error("Aucun item trouvé");
			return;
		}

		for (size_t i = 1; i <= objects.size(); i++)
		{
			cout << endl << " [" << i << "]";
			objects[i - 1]->display();
		}

		cout << endl;
	}

	template <typename T>
	static void simple_list(const vector<T*>& objects) {
		if (objects.empty())
		{
			error("Aucun item trouvé");
			return;
		}

		for (size_t i = 1; i <= objects.size(); i++)
		{
			cout << " " << i << ". " << objects[i - 1]->get_id();
		}
	}


	static void error(const string& message) {
		cout << "\033[91m" << " * " << message << "\033[0m";
	}

	static void confirm(const string& message) {
		cout << endl << "\033[92m" << " > " << message << "\033[0m" << endl;
	}

	static void back() {
		cout << endl << "\033[93m" << " < " << "Retour" << "\033[0m" << endl;
	}



	//Goes down two lines.
	static void space() {
		cout << endl << endl;
	}
};

