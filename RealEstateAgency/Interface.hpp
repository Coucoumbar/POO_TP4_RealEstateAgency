#pragma once

#include <iostream>
#include <type_traits>
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

		while (!(cin >> value) || value.size() < min || value.size() > max)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			error("Entrez une valeur valide : ");
		}

		cin.ignore(INT_MAX, '\n');

		return value;
	}

	//Display a section title.
	static void title(const string& text) {
		cout << " ===== " << text << " =====";
		space();
	}

	static void subtitle(const string& text) {
		cout << " --- " << text << " ---" << endl;
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

		text_field("Choix");
	}



	static void error(const string& message) {
		cout << "\033[31m" << " * " << message << "\033[0m";
	}

	static void back() {
		cout << endl << "\033[34m" << " < " << "Retour" << "\033[0m";
	}



	//Goes down two lines.
	static void space() {
		cout << endl << endl;
	}
};

