#pragma once

#include<iomanip>
#include"cl_string.h"
#include "cl_Screen.h"
#include"cl_User.h"

class cl_UpdateUserScreen : protected cl_Screen {

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

	static short pi_Access_on() {
		char Answer;
		short Total_access = 0;
		cout << "\nDo you wany to give access to : \n";
		cout << "\nShow Client List? y/n : ";
		cin >> Answer;
		Total_access += (tolower(Answer) == 'y') ? cl_User::Show_Client_List : 0;
		cout << "\nAdd New Client? y/n : ";
		cin >> Answer;
		Total_access += (tolower(Answer) == 'y') ? cl_User::Add_New_Client : 0;
		cout << "\nDelete Client? y/n : ";
		cin >> Answer;
		Total_access += (tolower(Answer) == 'y') ? cl_User::Delete_Client : 0;
		cout << "\nUpdate Client Info? y/n : ";
		cin >> Answer;
		Total_access += (tolower(Answer) == 'y') ? cl_User::Update_Client : 0;
		cout << "\nFind Client? y/n : ";
		cin >> Answer;
		Total_access += (tolower(Answer) == 'y') ? cl_User::Find_Client : 0;
		cout << "\nTransactions? y/n : ";
		cin >> Answer;
		Total_access += (tolower(Answer) == 'y') ? cl_User::Transactions : 0;
		cout << "\nManage Users? y/n : ";
		cin >> Answer;
		Total_access += (tolower(Answer) == 'y') ? cl_User::Manage_Users : 0;
		cout << "\nlogin Register? y/n : ";
		cin >> Answer;
		Total_access += (tolower(Answer) == 'y') ? cl_User::Login_Register : 0;
		return Total_access;
	}

	static void pi_Fill_User(cl_User &User, cl_User::en_Input_patterns choice = cl_User::check) {
		if (choice == cl_User::Log_in)
			User.UserName = cl_string::Read_string("Enter Name : ");
		User.First_name = cl_string::Read_string("\nEnter First name : ");
		User.Last_name = cl_string::Read_string("\nLast name  : ");
		User.Email = cl_string::Read_string("\nEmail  : ");
		User.Phone = cl_string::Read_string("\nEnter Phone number : ");
		User.Password = cl_string::Read_string("\nEnter Password : ");
		if (choice == cl_User::Add) {
			char Answer;
			cout << "\nDo you want to give full accsess ? y/n : ";
			cin >> Answer;
			if (tolower(Answer) == 'y') {
				User.Permissions = cl_User::Full_accsess;
				cout << "User Added Successfully.\n";
			}
			else
				User.Permissions = pi_Access_on();
		}
	}

public:

	static void Show_Update_client() {
		string UserName = "";
		cl_Screen::po_Draw_screen_header("\t   Update User Screen");
		UserName = cl_string::Read_string("\nPlease enter user UserName: ");
		while (!cl_User::Is_user_exist(UserName))
			UserName = cl_string::Read_string("\nUserName is not found, Choose another one : ");

		cl_User User = cl_User::Find_User(UserName);
		pi_Print(User);

		cout << "\n\nUpdate User Info:";
		cout << "\n_______________________\n";

		pi_Fill_User(User,cl_User::Add);

		cl_User::en_Save_result Save_result;

		Save_result = User.Save();

		switch (Save_result)
		{
		case cl_User::Save_succeeded:
			cout << "\nAccount Update successfully";
			pi_Print(User);
			break;
		case cl_User::Save_faild_empty_object:
			cout << "\nErorr account was not saved becsuse it's Empty";
			break;
		}

		cout << "\n\n\nPress any key to go back to Menue...";
		system("pause>0");
	}

};

