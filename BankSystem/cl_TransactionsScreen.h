#pragma once
#include<iomanip>
#include "cl_Screen.h"
#include"cl_Validation.h"
#include"cl_DepositScreen.h"
#include"cl_WidthdrawScreen.h"
#include"cl_BalanceListScreen.h"
#include"cl_TransferScreen.h"
#include"cl_TransferRegisterScreen.h"

class cl_TransactionsScreen : protected cl_Screen
{

	enum en_Transactions_menue_options {
		en_Deposit = 1, en_Withdraw, en_Total_balances
		, en_Transfer, en_Transfer_Log, en_Main_menue
	};

	static short pi_Read_main_option() {
		cout << setw(37) << left << "" << "Choose what do you want to do [1 to 6] : ";
		short choice = cl_Validation::Read_number_between(1, 6, "");
		return choice;
	}

	static void pi_Show_Deposit_screen() {
		cl_DepositScreen::Show_Deposit();
	}

	static void pi_Show_Withdraw_screen() {
		cl_WidthdrawScreen::Show_Withdraw();
	}

	static void pi_Show_Total_balances_screen() {
		cl_BalanceListScreen::Show_Balance_List();
	}

	static void pi_Transfer_screen() {
		cl_TransferScreen::Show_Transfer();
	}

	static void pi_Transfer_Log_screen() {
		cl_TransferRegisterScreen::Show_Login_Register_list();
	}

	static void pi_Go_back_to_main_menue_screen() {
		//
	}

	static bool pi_Perform_transactions_menue_optin(en_Transactions_menue_options Transactions_menue_option) {
		switch (Transactions_menue_option)
		{
		case cl_TransactionsScreen::en_Deposit:
			pi_Show_Deposit_screen();
			return false;
		case cl_TransactionsScreen::en_Withdraw:
			pi_Show_Withdraw_screen();
			return false;
		case cl_TransactionsScreen::en_Total_balances:
			pi_Show_Total_balances_screen();
			return false;
		case cl_TransactionsScreen::en_Transfer:
			pi_Transfer_screen();
			return false;
		case cl_TransactionsScreen::en_Transfer_Log:
			pi_Transfer_Log_screen();
			return false;
		case cl_TransactionsScreen::en_Main_menue:
			pi_Go_back_to_main_menue_screen();
			return true;
		}
	}

public:

	static void Show_transactions_menue() {

		if (!Check_access_rights(cl_User::en_Permissons::Transactions)) {
			return;
		}

		do {

			system("cls");
			po_Draw_screen_header("\tTransactions Menue");

			cout << setw(37) << left << "" << "===============================================\n";
			cout << setw(44) << left << "" << "   Transactions Menue Screen\n";
			cout << setw(37) << left << "" << "===============================================\n";
			cout << setw(44) << left << "" << "[1] Deposit.\n";
			cout << setw(44) << left << "" << "[2] Withdraw.\n";
			cout << setw(44) << left << "" << "[3] Total Balances.\n";
			cout << setw(44) << left << "" << "[4] Transfer.\n";
			cout << setw(44) << left << "" << "[5] Transfer Log.\n";
			cout << setw(44) << left << "" << "[6] Main Menue.\n";
			cout << setw(37) << left << "" << "===============================================\n";

			if (pi_Perform_transactions_menue_optin(en_Transactions_menue_options(pi_Read_main_option())))
				return;
		} while (true);
	}

};

