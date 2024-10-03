#pragma once

#include "cl_Screen.h"
#include"cl_BankClient.h"

class cl_TransferScreen : protected cl_Screen {

	static void pi_Print(cl_BankClient &Client) {
		cout << "\Client Card:\n";
		cout << "___________________________\n";
		cout << "\nFullName         : " << Client.Full_name();
		cout << "\nAccount number   : " << Client.Account_number;
		cout << "\nAccount balance  : " << Client.Account_balance;
		cout << "\n___________________________\n\n";
	}

public:

	static void Show_Transfer() {
		string Account_number_From = "";
		string Account_number_To = "";
		float Amount;
		char answer;
		cl_Screen::po_Draw_screen_header("\t    Transfer Screen");
		Account_number_From = cl_string::Read_string("\nPlease enter client Account number to Transfer From: ");
		while (!cl_BankClient::Is_client_exist(Account_number_From))
			Account_number_From = cl_string::Read_string("\nAccount number is not found, Choose another one : ");

		cl_BankClient Client_From = cl_BankClient::Find_Client(Account_number_From);
		pi_Print(Client_From);

		Account_number_To = cl_string::Read_string("\nPlease enter client Account number to Transfer To: ");
		while (!cl_BankClient::Is_client_exist(Account_number_To))
			Account_number_To = cl_string::Read_string("\nAccount number is not found, Choose another one : ");

		cl_BankClient Client_To = cl_BankClient::Find_Client(Account_number_To);
		pi_Print(Client_To);

		cout << "Please enter Transfer amount : ";
		Amount = cl_Validation::Read_and_check_number();
		while (Amount > Client_From.Account_balance && Amount <= 0) {
			cout << "Amount Exceeds the balance.\n";
			cout << "You can Transfer down to 0 or up to : " << Client_From.Account_balance << '\n';
			cout << "Enter another Amount : ";
			Amount = cl_Validation::Read_and_check_number();
		}

		cout << "Are you sure you want perfrom this transaction  (y/n) : ";
		cin >> answer;
		if (tolower(answer) == 'y') {
			if (Client_From.Transfer(Amount, Client_To)) {
				cout << "Transfer done Successfully.\n";
			}
			else
				cout << "Erorr.\n";
		}

		pi_Print(Client_From);
		pi_Print(Client_To);

		cout << "\n\n\nPress any key to go back to Menue...";
		system("pause>0");
	}


};

