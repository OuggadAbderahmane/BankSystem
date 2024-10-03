#pragma once

#include<iomanip>
#include "cl_Screen.h"
#include"cl_User.h"

class cl_FindUserScreen :
	protected cl_Screen
{
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

	static void Show_Find_user() {
		string UserName = "";
		cl_Screen::po_Draw_screen_header("\t   Find User Screen");
		UserName = cl_string::Read_string("\nPlease enter user UserName: ");
		while (!cl_User::Is_user_exist(UserName))
			UserName = cl_string::Read_string("\nUserName is not found, Choose another one : ");

		cl_User User = cl_User::Find_User(UserName);
		pi_Print(User);

		cout << "\n\n\nPress any key to go back to Menue...";
		system("pause>0");
	}

};

