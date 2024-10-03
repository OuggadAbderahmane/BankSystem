#pragma once
#include<iomanip>
#include"cl_ClientListScreen.h"
#include"cl_AddNewClientScreen.h"
#include"cl_DeleteClientScreen.h"
#include"cl_UpdateClientScreen.h"
#include"cl_FindClient.h"
#include"cl_TransactionsScreen.h"
#include"cl_ManageScreen.h"
#include"cl_LoginRegisterScreen.h"
#include"cl_CurrencyScreen.h"

class cl_MainScreen : protected cl_Screen
{
private:

	enum en_Main_menue_options {
		en_List_clients = 1, en_Add_new_client, en_Delete_client,
		en_Update_client, en_Find_client, en_Show_transactions_menue,
		en_Manage_users, en_Login_Register, en_Currency, en_Exit
	};

	static short pi_Read_main_option() {
		cout << setw(37) << left << "" << "Choose what do you want to do [1 to 10] : ";
		short choice = cl_Validation::Read_number_between(1, 10, "");
		return choice;
	}

	static void pi_Show_all_client_screen() {
		cl_ClientListScreen::Show_client_list();
	}

	static void pi_Show_add_new_client_screen() {
		cl_AddNewClientScreen::Show_Add_new_client();
	}

	static void pi_Show_delete_client_screen() {
		cl_DeleteClientScreen::Show_Delete_Client();
	}

	static void pi_Show_update_client_screen() {
		cl_UpdateClient::Show_Update_client();
	}

	static void pi_Show_find_client_screen() {
		cl_FindClient::Show_Find_client();
	}

	static void pi_Show_transactions_client_menue() {
		cl_TransactionsScreen::Show_transactions_menue();
	}

	static void pi_Show_manage_users_menue() {
		cl_ManageScreen::Show_manige_menue();
	}

	static void pi_Show_Login_Register_screen() {
		cl_LoginRegisterScreen::Show_Login_Register_list();
	}

	static void pi_Show_Currency_screen() {
		cl_CurrencyScreen::Show_Currency_menue();
	}

	static void pi_Show_end_client_screen() {
		Currently_User = cl_User::Find_User("", "");
	}

	static bool pi_Perform_main_menue_optin(en_Main_menue_options Main_menue_option) {

		switch (Main_menue_option)
		{
		case en_Main_menue_options::en_List_clients:
			system("cls");
			pi_Show_all_client_screen();
			return false;
		case en_Main_menue_options::en_Add_new_client:
			system("cls");
			pi_Show_add_new_client_screen();
			return false;
		case en_Main_menue_options::en_Delete_client:
			system("cls");
			pi_Show_delete_client_screen();
			return false;
		case en_Main_menue_options::en_Update_client:
			system("cls");
			pi_Show_update_client_screen();
			return false;
		case en_Main_menue_options::en_Find_client:
			system("cls");
			pi_Show_find_client_screen();
			return false;
		case en_Main_menue_options::en_Show_transactions_menue:
			system("cls");
			pi_Show_transactions_client_menue();
			return false;
		case en_Main_menue_options::en_Manage_users:
			system("cls");
			pi_Show_manage_users_menue();
			return false;
		case en_Main_menue_options::en_Login_Register:
			pi_Show_Login_Register_screen();
			return false;
		case en_Main_menue_options::en_Currency:
			pi_Show_Currency_screen();
			return false;
		case en_Main_menue_options::en_Exit:
			system("cls");
			pi_Show_end_client_screen();
			return true;
		}

	}

public:

	static void Show_main_menue() {
		do {

			system("cls");
			po_Draw_screen_header("\t\tMain Menue");

			cout << setw(37) << left << "" << "===============================================\n";
			cout << setw(37) << left << "" << "\t\tMain Menue Screen\n";
			cout << setw(37) << left << "" << "===============================================\n";
			cout << setw(37) << left << "" << "[1] Show Client List.\n";
			cout << setw(37) << left << "" << "[2] Add New Client.\n";
			cout << setw(37) << left << "" << "[3] Delete Client.\n";
			cout << setw(37) << left << "" << "[4] Update Client Info.\n";
			cout << setw(37) << left << "" << "[5] Find Client.\n";
			cout << setw(37) << left << "" << "[6] Transactions.\n";
			cout << setw(37) << left << "" << "[7] Manage Users.\n";
			cout << setw(37) << left << "" << "[8] login Register.\n";
			cout << setw(37) << left << "" << "[9] Currency.\n";
			cout << setw(37) << left << "" << "[10] GO back to login screen.\n";
			cout << setw(37) << left << "" << "===============================================\n";

			if (pi_Perform_main_menue_optin(en_Main_menue_options(pi_Read_main_option())))
				return;

		} while (true);
	}
	
};

