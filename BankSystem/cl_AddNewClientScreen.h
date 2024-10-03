#pragma once

#include<iomanip>
#include "cl_Screen.h"
#include"cl_BankClient.h"

class cl_AddNewClientScreen : protected cl_Screen {

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

	static void pi_Read_Client_info(cl_BankClient &Client) {

		Client.First_name = cl_string::Read_string("\nEnter First name : ");
		Client.Last_name = cl_string::Read_string("\nplease Last name  : ");
		Client.Email = cl_string::Read_string("\nplease Email  : ");
		Client.Phone = cl_string::Read_string("\nEnter Phone number : ");
		Client.Pin_code = cl_string::Read_string("\nPincode : ");
		cout << "\nplease Enter Account Balance : ";
		Client.Account_balance = cl_Validation::Read_and_check_number("please Enter a number : ");
	}

public:

	static void Show_Add_new_client() {

		if (!Check_access_rights(cl_User::en_Permissons::Add_New_Client)) {
			return;
		}

		string Account_number = "";
		cl_Screen::po_Draw_screen_header("\t   Add New Client Screen");
		Account_number = cl_string::Read_string("\nPlease enter client Account number: ");
		while (cl_BankClient::Is_client_exist(Account_number))
			Account_number = cl_string::Read_string("\nAccount number is already used, Choose another one : ");
		cl_BankClient Client = cl_BankClient::Get_add_new_client_object(Account_number);

		cout << "\n\nAdd new Client Info:";
		cout << "\n_______________________\n";

		pi_Read_Client_info(Client);

		cl_BankClient::en_Save_result Save_result;

		Save_result = Client.Save();

		switch (Save_result)
		{
		case cl_BankClient::Save_succeeded:
			cout << "\nAccount Update successfully";
			pi_Print(Client);
			break;
		case cl_BankClient::Save_faild_empty_object:
			cout << "\nErorr account was not saved becsuse it's Empty";
			break;
		case cl_BankClient::Save_faild_account_number_object:
			cout << "\nErorr account was not saved because account number is used!";
		}

		cout << "\n\n\nPress any key to go back to Menue...";
		system("pause>0");
	}

};

