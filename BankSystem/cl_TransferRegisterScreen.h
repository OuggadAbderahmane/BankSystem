#pragma once

#include<iomanip>
#include "cl_Screen.h"
#include"cl_BankClient.h"


class cl_TransferRegisterScreen : protected cl_Screen
{

	static void pi_print_Client_data(string Line) {
		vector <string> v_Usre = cl_string::sepreate_the_words_and_put_in_vector(Line, "#//#");
		cout << "| " << left << setw(30) << v_Usre[0];
		cout << "| " << left << setw(10) << v_Usre[1];
		cout << "| " << left << setw(10) << v_Usre[2];
		cout << "| " << left << setw(14) << stof(v_Usre[3]) - stof(v_Usre[5]);
		cout << "| " << left << setw(14) << v_Usre[5];
		cout << "| " << left << setw(14) << v_Usre[6];
		cout << "| " << v_Usre[7] << endl;
	}

public:

	static void Show_Login_Register_list() {

		vector <string> v_Transfer = cl_BankClient::Get_Register_list();

		cl_Screen::po_Draw_screen_header("\t     Client List Screen", "\t      (" + to_string(v_Transfer.size()) + ") client(s).");

		cout << "________________________________________________________________________________________________________________________\n\n";
		cout << "| " << left << setw(30) << "Date/Time" << "| " << left << setw(10) << "s.Acct" << "| " << left << setw(10) << "d.Acct" << "| " << left << setw(14) << "Amount" << "| " << left << setw(14) << "s.Balance" << "| " << left << setw(14) << "d.Balance" << "| " << left << setw(20) << "User" << endl;
		cout << "________________________________________________________________________________________________________________________\n\n";
		if (v_Transfer.size() != 0) {
			for (string &User : v_Transfer)
				pi_print_Client_data(User);
			cout << "________________________________________________________________________________________________________________________\n\n";
		}
		else
			cout << cl_string::Tabs(3) + "No Users Available in the system!\n";
		cout << "\n\n\nPress any key to go back to Menue...";
		system("pause>0");
	}
};

