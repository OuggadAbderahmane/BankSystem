#pragma once
#include<iomanip>
#include "cl_Screen.h"
#include"cl_BankClient.h"
class cl_DeleteClientScreen : protected cl_Screen
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

	static void Show_Delete_Client() {

		if (!Check_access_rights(cl_User::en_Permissons::Delete_Client)) {
			return;
		}

		string Account_number = "";
		cl_Screen::po_Draw_screen_header("\t   Delete Client Screen");
		Account_number = cl_string::Read_string("\nPlease enter client Account number: ");
		while (!cl_BankClient::Is_client_exist(Account_number))
			Account_number = cl_string::Read_string("\nAccount number is not found, Choose another one : ");

		cl_BankClient Client = cl_BankClient::Find_Client(Account_number);
		pi_Print(Client);

		char answer;
		cout << "Are you sure you want to delete this account y/n : ";
		cin >> answer;
		if (tolower(answer) == 'y') {
			if (Client.Delete()) {
				cout << "\nClient deleted successfully :-)\n";
				pi_Print(Client);
			}
			else {
				cout << "\nErorr Client was not deleted\n";
			}
		}

		cout << "\n\n\nPress any key to go back to Menue...";
		system("pause>0");
	}
	
};

