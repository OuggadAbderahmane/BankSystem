#pragma once

#include<iostream>
#include<string>
#include"cl_string.h"
#include<vector>
#include<fstream>

string Currency_file = "Currencies.txt";

class cl_Currency {

	enum en_Mode { Empty_mode = 0, Update_mode = 1 };
	en_Mode pi_Mode;

	string pi_Country;
	string pi_Currenct_code;
	string pi_Currenct_name;
	float pi_Rate;

	static cl_Currency pi_string_to_Currency(string data, string character = " ") {

		vector <string> v_Currency = cl_string::sepreate_the_words_and_put_in_vector(data, character);

		return cl_Currency(v_Currency[0], v_Currency[1], v_Currency[2],stof(v_Currency[3]), Update_mode);
	}

	static string pi_Currency_to_string(cl_Currency Currency, string character = " ") {

		return Currency.Country + character + Currency.Currenct_code + character + Currency.Currenct_name + character + to_string(Currency.pi_Rate);
	}

	static bool pi_search_for_Country(string Country_name, cl_Currency *&Currency, vector <cl_Currency> &vline) {

		for (cl_Currency &c : vline) {
			if (cl_string::Upper_letter_string(c.Country) == cl_string::Upper_letter_string(Country_name)) {
				Currency = &c;
				return true;
			}
		}

		return false;
	}

	static bool pi_search_for_Currenct_code(string Currenct_code, cl_Currency *&Currency, vector <cl_Currency> &vline) {

		for (cl_Currency &c : vline) {
			if (cl_string::Upper_letter_string(c.Currenct_code) == cl_string::Upper_letter_string(Currenct_code)) {
				Currency = &c;
				return true;
			}
		}

		return false;
	}

	static void pi_load_data_from_file_to_vector( vector <cl_Currency> &vline) {
		fstream MyFile;
		MyFile.open(Currency_file, ios::in);
		if (MyFile.is_open()) {

			string line;
			while (getline(MyFile, line)) {
				vline.push_back(pi_string_to_Currency(line, "#//#"));
			}

			MyFile.close();
		}
	}

	static void pi_load_data_from_vector_to_file(vector <cl_Currency> &vline) {
		fstream MyFile;
		MyFile.open(Currency_file, ios::out);
		if (MyFile.is_open()) {
			for (cl_Currency &line : vline) {
					MyFile << pi_Currency_to_string(line, "#//#") << endl;

			}
			MyFile.close();
		}
		vline.clear();
	}

	static cl_Currency pi_Get_empty_Currency_object() {
		return cl_Currency("", "", "", 0, Empty_mode);
	}

	void pi_Update() {
		cl_Currency *Country;
		string Account_number;
		vector <cl_Currency> v_Country;
		pi_load_data_from_file_to_vector(v_Country);

		pi_search_for_Country(pi_Country, Country, v_Country);
		*Country = *this;

		pi_load_data_from_vector_to_file(v_Country);

	}

public:

	cl_Currency(string Country, string Currenct_code, string Currenct_name, float Rate, en_Mode Mode)
		:pi_Country(Country),
		pi_Currenct_code(Currenct_code),
		pi_Currenct_name(Currenct_name),
		pi_Rate(Rate),
		pi_Mode(Mode)
	{

	}

	bool Is_empty() {
		return (pi_Mode == Empty_mode);
	}

	string Get_Country() {
		return pi_Country;
	}

	__declspec(property(get = Get_Country)) string Country;

	string Get_Currenct_code() {
		return pi_Currenct_code;
	}

	__declspec(property(get = Get_Currenct_code)) string Currenct_code;
	
	string Get_Currenct_name() {
		return pi_Currenct_name;
	}

	__declspec(property(get = Get_Currenct_name)) string Currenct_name;

	void Set_Rate(float Rate) {
		pi_Rate = Rate;
		pi_Update();
	}

	float Get_Rate() {
		return pi_Rate;
	}

	__declspec(property(get = Get_Rate, put = Set_Rate)) float Rate;

	static cl_Currency Find_Currency_By_Country_name(string Country_name) {
		cl_Currency *Currency;
		vector <cl_Currency> v_Currency;

		pi_load_data_from_file_to_vector(v_Currency);

		Currency = NULL;
		if (pi_search_for_Country(Country_name, Currency, v_Currency)) {
			return *Currency;
		}
		else
			return pi_Get_empty_Currency_object();
	}

	static cl_Currency Find_Currency_By_code(string Currenct_code) {
		cl_Currency *Currency;
		vector <cl_Currency> v_Currency;

		pi_load_data_from_file_to_vector(v_Currency);

		Currency = NULL;
		if (pi_search_for_Currenct_code(Currenct_code, Currency, v_Currency)) {
			return *Currency;
		}
		else
			return pi_Get_empty_Currency_object();
	}

	static bool Is_Currency_exist_By_Country_name(string Country_name) {
		cl_Currency Currency = cl_Currency::Find_Currency_By_Country_name(Country_name);
		return !Currency.Is_empty();
	}

	static bool Is_Currency_exist_By_code(string Currenct_code) {
		cl_Currency Currency = cl_Currency::Find_Currency_By_code(Currenct_code);
		return !Currency.Is_empty();
	}

	static vector <cl_Currency> Get_Currency_list() {
		vector <cl_Currency> v_Currency;
		pi_load_data_from_file_to_vector(v_Currency);
		return v_Currency;
	}

	float Calculate_Currency(cl_Currency &Currency,float Amount) {
		return (Currency.Rate / Rate)*Amount;
	}

};

