#pragma once

#include<iomanip>
#include "cl_Screen.h"
#include"cl_BankClient.h"

class cl_FindClient : protected cl_Screen
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

	static void Show_Find_client() {

		if (!Check_access_rights(cl_User::en_Permissons::Find_Client)) {
			return;
		}

		string Account_number = "";
		cl_Screen::po_Draw_screen_header("\t   Find Client Screen");
		Account_number = cl_string::Read_string("\nPlease enter client Account number: ");
		while (!cl_BankClient::Is_client_exist(Account_number))
			Account_number = cl_string::Read_string("\nAccount number is not found, Choose another one : ");

		cl_BankClient Client = cl_BankClient::Find_Client(Account_number);
		pi_Print(Client);

		cout << "\n\n\nPress any key to go back to Menue...";
		system("pause>0");
	}

};

