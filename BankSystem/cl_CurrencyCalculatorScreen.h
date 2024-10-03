#pragma once

#include "cl_Screen.h"
#include "cl_Currency.h"

class cl_CurrencyCalculatorScreen : protected cl_Screen {

	static void pi_Print(cl_Currency &Currency) {
		cout << "___________________________\n";
		cout << "\nCountry      : " << Currency.Country;
		cout << "\nCode         : " << Currency.Currenct_code;
		cout << "\nName         : " << Currency.Currenct_name;
		cout << "\nRate(1$)     : " << Currency.Rate;
		cout << "\n___________________________\n\n";
	}

public:

	static void Show_Calculator_Currency() {

		char answer;
		float Amount;
		float Result;
		string Code = "";

		do {

			cl_Screen::po_Draw_screen_header("\t   Calculator Currency Screen");


			Code = cl_string::Read_string("\nPlease enter Currency1 Code: ");
			while (!cl_Currency::Is_Currency_exist_By_code(Code))
				Code = cl_string::Read_string("\nCurrency Code is not found, Choose another one : ");

			cl_Currency Currency1 = cl_Currency::Find_Currency_By_code(Code);

			Code = cl_string::Read_string("\nPlease enter Currency2 Code: ");
			while (!cl_Currency::Is_Currency_exist_By_code(Code))
				Code = cl_string::Read_string("\nCurrency Code is not found, Choose another one : ");

			cl_Currency Currency2 = cl_Currency::Find_Currency_By_code(Code);

			cout << "\nEnter Amount to exchange : ";
			Amount = cl_Validation::Read_and_check_number();

			cout << "\nConvert From:\n";
			pi_Print(Currency1);
			cl_Currency USD_Currency = cl_Currency::Find_Currency_By_code("USD");
			Result = Currency1.Calculate_Currency(USD_Currency, Amount);
			cout << Amount << " " << Currency1.Currenct_code << " = " << Result << " USD\n";

			if (cl_string::Upper_letter_string(Code) != "USD") {
				cout << "\nConvert To:\n";
				pi_Print(Currency2);
				Result = USD_Currency.Calculate_Currency(Currency2, Result);
				cout << Amount << " " << Currency1.Currenct_code << " = " << Result << " " << Currency2.Currenct_code << endl;
			}

			cout << "\nDo you want to preform another clculation y/n : ";
			cin >> answer;

		} while (tolower(answer) == 'y');
	}
};

