#pragma once

#include "cl_Screen.h"
#include "cl_Currency.h"

class cl_FindCurrencyScreen : protected cl_Screen {

	static void pi_Print(cl_Currency &Currency) {
		cout << "\nCurrency Card:\n";
		cout << "___________________________\n";
		cout << "\nCountry      : " << Currency.Country;
		cout << "\nCode         : " << Currency.Currenct_code;
		cout << "\nName         : " << Currency.Currenct_name;
		cout << "\nRate(1$)     : " << Currency.Rate;
		cout << "\n___________________________\n\n";
	}

public:

	static void Show_Find_Currency() {

		short choise;
		string Code_or_country = "";
		cl_Screen::po_Draw_screen_header("\t   Find Currency Screen");

		if (short choice = cl_Validation::Read_number_between(1, 2, "Find By: [1] Code or [2] country : ") == 1) {

			Code_or_country = cl_string::Read_string("\nPlease enter Currency Code: ");
			while (!cl_Currency::Is_Currency_exist_By_code(Code_or_country))
				Code_or_country = cl_string::Read_string("\nCurrency Code is not found, Choose another one : ");

			cl_Currency Currency = cl_Currency::Find_Currency_By_code(Code_or_country);
			pi_Print(Currency);

		}
		else {

			Code_or_country = cl_string::Read_string("\nPlease enter Country name: ");
			while (!cl_Currency::Is_Currency_exist_By_Country_name(Code_or_country))
				Code_or_country = cl_string::Read_string("\nCountry name is not found, Choose another one : ");

			cl_Currency Currency = cl_Currency::Find_Currency_By_Country_name(Code_or_country);
			pi_Print(Currency);

		}

		cout << "\n\n\nPress any key to go back to Menue...";
		system("pause>0");
	}
	
};

