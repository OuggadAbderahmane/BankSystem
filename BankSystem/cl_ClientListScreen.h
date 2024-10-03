#pragma once

#include<iomanip>
#include "cl_Screen.h"
#include"cl_BankClient.h"

class cl_ClientListScreen : protected cl_Screen {

	static void pi_print_Client_data(cl_BankClient &Client) {
		cout << "| " << left << setw(14) << Client.Account_number;
		cout << "| " << left << setw(20) << Client.Full_name();
		cout << "| " << left << setw(14) << Client.Phone;
		cout << "| " << left << setw(25) << Client.Email;
		cout << "| " << left << setw(10) << Client.Pin_code;
		cout << "| " << Client.Account_balance << endl;
	}

public:

	static void Show_client_list() {

		if (!Check_access_rights(cl_User::en_Permissons::Show_Client_List)) {
			return;
		}

		vector <cl_BankClient> v_Client = cl_BankClient::Get_client_list();

		cl_Screen::po_Draw_screen_header("\t     Client List Screen","\t      ("+to_string(v_Client.size())+") client(s).");

		//cout << left << setw(30) << '\n' << "Client List (" <<  << ") Client(s)\n\n";
		cout << "_______________________________________________________________________________________________________\n\n";
		cout << "| " << left << setw(14) << "Accout Number" << "| " << left << setw(20) << "Full name" << "| " << left << setw(14) << "Phone" << "| " << left << setw(25) << "Email" << "| " << left << setw(10) << "Pin code" << "| " << left << setw(14) << "Balance" << endl;
		cout << "_______________________________________________________________________________________________________\n\n";
		if (v_Client.size() != 0) {
			for (cl_BankClient &Client : v_Client)
				pi_print_Client_data(Client);
			cout << "_______________________________________________________________________________________________________\n\n";
		}
		else
			cout << cl_string::Tabs(3) + "No Clients Available in the system!\n";
		cout << "\n\n\nPress any key to go back to Menue...";
		system("pause>0");
	}

};

