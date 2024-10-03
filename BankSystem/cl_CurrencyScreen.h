#pragma once

#include<iomanip>
#include "cl_Screen.h"
#include "cl_CurrentiesListScreen.h"
#include "cl_FindCurrencyScreen.h"
#include "cl_UpdateCurrencyScreen.h"
#include "cl_CurrencyCalculatorScreen.h"

class cl_CurrencyScreen : protected cl_Screen {

	enum en_Currency_menue_options {
		en_List_Currencies = 1, en_Find_Currency,
		en_Update_Rate, en_Currency_Calculator, en_Exit
	};

	static short pi_Read_Currency_option() {
		cout << setw(37) << left << "" << "Choose what do you want to do [1 to 5] : ";
		short choice = cl_Validation::Read_number_between(1, 5, "");
		return choice;
	}

	static void pi_Show_List_Currencies_screen() {
		cl_CurrentiesListScreen::Show_Currency_list();
	}

	static void pi_Show_Find_Currency_screen() {
		cl_FindCurrencyScreen::Show_Find_Currency();
	}
	
	static void pi_Show_Update_Rate_screen() {
		cl_UpdateCurrencyScreen::Show_Update_Currency();
	}
	
	static void pi_Show_Currency_Calculator_screen() {
		cl_CurrencyCalculatorScreen::Show_Calculator_Currency();
	}
	
	static void pi_Show_Exit_screen() {
		cout << "Too soon.\n";
	}

	static bool pi_Perform_Currency_menue_optin(en_Currency_menue_options Main_menue_option) {
		switch (Main_menue_option)
		{
		case cl_CurrencyScreen::en_List_Currencies:
			system("cls");
			pi_Show_List_Currencies_screen();
			return false;
		case cl_CurrencyScreen::en_Find_Currency:
			system("cls");
			pi_Show_Find_Currency_screen();
			return false;
		case cl_CurrencyScreen::en_Update_Rate:
			system("cls");
			pi_Show_Update_Rate_screen();
			return false;
		case cl_CurrencyScreen::en_Currency_Calculator:
			system("cls");
			pi_Show_Currency_Calculator_screen();
			return false;
		case cl_CurrencyScreen::en_Exit:
			system("cls");
			pi_Show_Exit_screen();
			return true;
		}
	}

public:

	static void Show_Currency_menue() {

		if (!Check_access_rights(cl_User::en_Permissons::Currency)) {
			return;
		}

		do {

			system("cls");
			po_Draw_screen_header("\t\tCurrency Menue");

			cout << setw(37) << left << "" << "===============================================\n";
			cout << setw(37) << left << "" << "\t\tCurrency Menue Screen\n";
			cout << setw(37) << left << "" << "===============================================\n";
			cout << setw(37) << left << "" << "[1] Show List Currencies.\n";
			cout << setw(37) << left << "" << "[2] Find Currency.\n";
			cout << setw(37) << left << "" << "[3] Update Rate.\n";
			cout << setw(37) << left << "" << "[4] Currency Calculator.\n";
			cout << setw(37) << left << "" << "[5] GO back to Main screen.\n";
			cout << setw(37) << left << "" << "===============================================\n";

			if (pi_Perform_Currency_menue_optin(en_Currency_menue_options(pi_Read_Currency_option())))
				return;

		} while (true);
	}

};

