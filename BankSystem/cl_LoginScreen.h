#pragma once
#include "cl_Screen.h"
#include"cl_MainScreen.h"
#include"Global.h"
//#include""

class cl_LoginScreen : protected cl_Screen {

	static void pi_Fill_User(string &UserName, string &Password) {
		UserName = cl_string::Read_string("please Enter Name : ");
		cl_string::Replace_words(UserName, "\n","");
		Password = cl_string::Read_string("\nEnter Password : ");
		cl_string::Replace_words(Password, "\n", "");
	}

	static bool pi_Check_account(string UserName, string Password) {
		Currently_User = cl_User::Find_User(UserName, Password);
		return !Currently_User.Is_empty();
	}

public:

	static void Show_login(short Try_times) {
		string UserName;
		string Password;
		short counter = Try_times;
		bool Correct_Password = true;
		do
		{
			system("cls");
			po_Draw_screen_header("\t\tLogin Screen");

			if (Correct_Password == false) {
				cout << "Invlaid Username/Password!\n";
				cout << "You have " << counter << " Trials to login.\n\n";
			}

			if (counter == 0) {
				cout << "You are Locked After "<< Try_times <<" Faild Trails\n";
				break;
			}

			pi_Fill_User(UserName, Password);
			Correct_Password = pi_Check_account(UserName, Password);
			if (Correct_Password == true) {
				counter = Try_times;
				Currently_User.Login_register();
				cl_MainScreen::Show_main_menue();
			}
			else {
				counter -= 1;
				Correct_Password = 0;
			}


		} while (true);
	}
	
};