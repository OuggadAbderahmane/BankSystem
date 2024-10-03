#pragma once

#include<iomanip>
#include "cl_Screen.h"
#include"cl_BankClient.h"
#include"cl_Validation.h"

class cl_BalanceListScreen : protected cl_Screen
{
	static void pi_Balance_List_data(cl_BankClient &Client) {
		cout << "| " << left << setw(14) << Client.Account_number;
		cout << "| " << left << setw(32) << Client.Full_name();
		cout << "| " << Client.Account_balance << endl;
	}

public:

	static void Show_Balance_List() {

		vector <cl_BankClient> v_Client = cl_BankClient::Get_client_list();
		cl_Screen::po_Draw_screen_header("\t  Balance List Screen", "\t      (" + to_string(v_Client.size()) + ") client(s).");

		cout << "__________________________________________________________________________________________\n\n";
		cout << "| " << left << setw(14) << "Accout Number" << "| " << left << setw(32) << "Client Name" << "| " << left << setw(32) << "Balance" << "\n\n";
		cout << "__________________________________________________________________________________________\n\n";
		for (cl_BankClient &Client : v_Client) {
			pi_Balance_List_data(Client);
		}
		cout << "__________________________________________________________________________________________\n\n";
		cout << "\n" + cl_string::Tabs(4) + "Total Balance = " << cl_BankClient::Get_total_balance() << endl;

		cout << "\n\n\nPress any key to go back to Menue...";
		system("pause>0");
	}
	
};

