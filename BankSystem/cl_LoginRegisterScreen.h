#pragma once

#include<iomanip>
#include "cl_Screen.h"
class cl_LoginRegisterScreen : protected cl_Screen {

	static void pi_print_Client_data(string Line) {
		vector <string> v_Usre = cl_string::sepreate_the_words_and_put_in_vector(Line,"#//#");
		cout << "| " << left << setw(30) << v_Usre[0];
		cout << "| " << left << setw(20) << v_Usre[1];
		cout << "| " << left << setw(20) << cl_Util::Decrypt_word(v_Usre[2],5);
		cout << "| " << v_Usre[3] << endl;
	}

public:

	static void Show_Login_Register_list() {

		if (!Check_access_rights(cl_User::en_Permissons::Login_Register)) {
			return;
		}

		vector <string> v_User = cl_User::Get_Register_list();

		cl_Screen::po_Draw_screen_header("\t     Client List Screen", "\t      (" + to_string(v_User.size()) + ") client(s).");

		cout << "_______________________________________________________________________________________________________\n\n";
		cout << "| " << left << setw(30) << "Date/Time" << "| " << left << setw(20) << "UserName" << "| " << left << setw(20) << "Password" << "| " << left << setw(25) << "Get_Register_list" <<endl;
		cout << "_______________________________________________________________________________________________________\n\n";
		if (v_User.size() != 0) {
			for (string &User : v_User)
				pi_print_Client_data(User);
			cout << "_______________________________________________________________________________________________________\n\n";
		}
		else
			cout << cl_string::Tabs(3) + "No Users Available in the system!\n";
		cout << "\n\n\nPress any key to go back to Menue...";
		system("pause>0");
	}
	

};

