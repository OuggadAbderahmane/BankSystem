#pragma once

#include<iomanip>
#include "cl_Screen.h"
#include"cl_User.h"

class cl_ListUsersScreen : protected cl_Screen
{

	static void pi_Print_Users_data(cl_User &User) {
		cout << "| " << left << setw(14) << User.UserName;
		cout << "| " << left << setw(20) << User.Full_name();
		cout << "| " << left << setw(14) << User.Phone;
		cout << "| " << left << setw(25) << User.Email;
		cout << "| " << left << setw(10) << User.Password;
		cout << "| " << User.Permissions << endl;
	}

public:

	static void Show_users_list() {
		vector <cl_User> v_User = cl_User::Get_user_list();

		cl_Screen::po_Draw_screen_header("\t     User List Screen", "\t      (" + to_string(v_User.size()) + ") user(s).");

		//cout << left << setw(30) << '\n' << "Client List (" <<  << ") Client(s)\n\n";
		cout << "_________________________________________________________________________________________________________________\n\n";
		cout << "| " << left << setw(14) << "UserName" << "| " << left << setw(20) << "Full name" << "| " << left << setw(14) << "Phone" << "| " << left << setw(25) << "Email" << "| " << left << setw(10) << "Password" << "| " << left << setw(14) << "Permissons" << endl;
		cout << "_________________________________________________________________________________________________________________\n\n";
		if (v_User.size() != 0) {
			for (cl_User &User : v_User)
				pi_Print_Users_data(User);
			cout << "_________________________________________________________________________________________________________________\n\n";
		}
		else
			cout << cl_string::Tabs(3) + "No Users Available in the system!\n";
		cout << "\n\n\nPress any key to go back to Menue...";
		system("pause>0");
	}

};

