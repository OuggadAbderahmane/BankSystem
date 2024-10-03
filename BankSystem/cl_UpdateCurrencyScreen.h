#pragma once

#include "cl_Screen.h"
#include "cl_Currency.h"

class cl_UpdateCurrencyScreen : protected cl_Screen {

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

	static void Show_Update_Currency() {
		char answer;
		float Amount;
		string Code = "";
		cl_Screen::po_Draw_screen_header("\t   Update Currency Screen");


		Code = cl_string::Read_string("\nPlease enter Currency Code: ");
		while (!cl_Currency::Is_Currency_exist_By_code(Code))
			Code = cl_string::Read_string("\nCurrency Code is not found, Choose another one : ");

		cl_Currency Currency = cl_Currency::Find_Currency_By_code(Code);
		pi_Print(Currency);

		
		cout << "Are you sure you want to Update the rate of this Currency y/n : ";
		cin >> answer;

		if (tolower(answer) == 'y') {
			cout << "Update Currency Rate:\n";
			cout << "____________________\n\n";
			cout << "Enter New Rate : ";
			Amount = cl_Validation::Read_and_check_number();
			Currency.Set_Rate(Amount);
			cout << "\nUser Update successfully :-)\n";
			pi_Print(Currency);
		}

		cout << "\n\n\nPress any key to go back to Menue...";
		system("pause>0");

	}
	
};

