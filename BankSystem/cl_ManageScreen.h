#pragma once

#include<iostream>
#include<iomanip>
#include"cl_Screen.h"
#include"cl_Validation.h"
#include"cl_ListUsersScreen.h"
#include"cl_AddNewUserScreen.h"
#include"cl_DeleteUserScreen.h"
#include"cl_UpdateUserScreen.h"
#include"cl_FindUserScreen.h"


using namespace std;

class cl_ManageScreen : protected cl_Screen {

	enum en_Manage_menue_options {
		en_List_users = 1, en_Add_new_user, en_Delete_user,
		en_Update_user, en_Find_user, en_GO_back_to_main
	};

	static short pi_Read_manage_option() {
		cout << setw(37) << left << "" << "Choose what do you want to do [1 to 6] : ";
		short choice = cl_Validation::Read_number_between(1, 6, "");
		return choice;
	}

	static void pi_Show_List_users_screen() {
		cl_ListUsersScreen::Show_users_list();
	}

	static void pi_Show_Add_new_user_screen() {
		cl_AddNewUserScreen::Show_Add_new_user();
	}

	static void pi_Show_Delete_user_screen() {
		cl_DeleteUserScreen::Show_Delete_User();
	}

	static void pi_Show_Update_user_screen() {
		cl_UpdateUserScreen::Show_Update_client();
	}

	static void pi_Show_Find_user_screen() {
		cl_FindUserScreen::Show_Find_user();
	}

	static void pi_Go_back_to_main_menue_screen() {
		cout << "\n Too soon.\n";
	}

	static bool pi_Perform_Manage_menue_optin(en_Manage_menue_options Manage_menue_option) {
		

		switch (Manage_menue_option)
		{
		case cl_ManageScreen::en_List_users:
			pi_Show_List_users_screen();
			return false;
		case cl_ManageScreen::en_Add_new_user:
			pi_Show_Add_new_user_screen();
			return false;
		case cl_ManageScreen::en_Delete_user:
			pi_Show_Delete_user_screen();
			return false;
		case cl_ManageScreen::en_Update_user:
			pi_Show_Update_user_screen();
			return false;
		case cl_ManageScreen::en_Find_user:
			pi_Show_Find_user_screen();
			return false;
		case cl_ManageScreen::en_GO_back_to_main:
			pi_Go_back_to_main_menue_screen();
			return true;
		}


	}

public:

	static void Show_manige_menue() {

		if (!Check_access_rights(cl_User::en_Permissons::Manage_Users)) {
			return;
		}

		do {
			system("cls");
			po_Draw_screen_header("\t\tMain Menue");

			cout << setw(37) << left << "" << "===============================================\n";
			cout << setw(44) << left << "" << "Manageusers Menue Screen\n";
			cout << setw(37) << left << "" << "===============================================\n";
			cout << setw(44) << left << "" << "[1] Show List Users.\n";
			cout << setw(44) << left << "" << "[2] Add New User.\n";
			cout << setw(44) << left << "" << "[3] Delete User.\n";
			cout << setw(44) << left << "" << "[4] Update User Info.\n";
			cout << setw(44) << left << "" << "[5] Find User.\n";
			cout << setw(44) << left << "" << "[6] GO back to Main screen.\n";
			cout << setw(37) << left << "" << "===============================================\n";

			if (pi_Perform_Manage_menue_optin(en_Manage_menue_options(pi_Read_manage_option())))
				return;

		} while (true);
	}

};

