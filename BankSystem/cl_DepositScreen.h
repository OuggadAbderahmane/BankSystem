#pragma once

#include "cl_Screen.h"
#include"cl_BankClient.h"
#include"cl_Validation.h"

class cl_DepositScreen : protected cl_Screen
{
	static void pi_Print(cl_BankClient &Client) {
		cout << "\nInfo:\n";
		cout << "___________________________\n";
		cout << "\nFirstName        : " << Client.First_name;
		cout << "\nLastName         : " << Client.Last_name;
		cout << "\nFullName         : " << Client.Full_name();
		cout << "\nEmail            : " << Client.Email;
		cout << "\nPhone            : " << Client.Phone;
		cout << "\nAccount number   : " << Client.Account_number;
		cout << "\nPin code         : " << Client.Pin_code;
		cout << "\nAccount balance  : " << Client.Account_balance;
		cout << "\n___________________________\n\n";
	}

public:

	static void Show_Deposit() {
		string Account_number = "";
		float Account_balance;
		char answer;
		cl_Screen::po_Draw_screen_header("\t     Deposit Screen");
		Account_number = cl_string::Read_string("\nPlease enter client Account number: ");
		while (!cl_BankClient::Is_client_exist(Account_number))
			Account_number = cl_string::Read_string("\nAccount number is not found, Choose another one : ");

		cl_BankClient Client = cl_BankClient::Find_Client(Account_number);
		pi_Print(Client);

		cout << "Please enter Deposit amount : ";
		Account_balance = cl_Validation::Read_and_check_number();
		while (Account_balance <= 0) {
			cout << "Amount Exceeds the balance.\n";
			cout << "You can Deposit down to 0 \n";
			cout << "Enter another Amount : ";
			Account_balance = cl_Validation::Read_and_check_number();
		}

		cout << "Are you sure you want perfrom this transaction  (y/n) : ";
		cin >> answer;
		if (tolower(answer) == 'y') {
			Client.Deposit(Account_balance);
			cout << "Client Deposit Successfully.\n";
		}

		cout << "\n\n\nPress any key to go back to Menue...";
		system("pause>0");

	}
	
};

