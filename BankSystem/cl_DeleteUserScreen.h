#pragma once

#include"cl_string.h"
#include "cl_Screen.h"
#include"cl_User.h"

class cl_DeleteUserScreen : protected cl_Screen {

	static void pi_Print(cl_User &User) {
		cout << "\nInfo:\n";
		cout << "___________________________\n";
		cout << "\nFirstName        : " << User.First_name;
		cout << "\nLastName         : " << User.Last_name;
		cout << "\nFullName         : " << User.Full_name();
		cout << "\nEmail            : " << User.Email;
		cout << "\nPhone            : " << User.Phone;
		cout << "\nUserName         : " << User.UserName;
		cout << "\nPassword         : " << User.Password;
		cout << "\nPermissons       : " << User.Permissions;
		cout << "\n___________________________\n\n";
	}

public:

	static void Show_Delete_User() {
		string UserName = "";
		cl_Screen::po_Draw_screen_header("\t   Delete User Screen");
		UserName = cl_string::Read_string("\nPlease enter user UserName: ");
		while (!cl_User::Is_user_exist(UserName))
			UserName = cl_string::Read_string("\nUserName is not found, Choose another one : ");

		cl_User User = cl_User::Find_User(UserName);
		pi_Print(User);

		char answer;
		cout << "Are you sure you want to delete this account y/n : ";
		cin >> answer;
		if (tolower(answer) == 'y') {
			if (User.Delete()) {
				cout << "\nUser deleted successfully :-)\n";
				pi_Print(User);
			}
			else {
				cout << "\nErorr User was not deleted\n";
			}
		}

		cout << "\n\n\nPress any key to go back to Menue...";
		system("pause>0");
	}

};

