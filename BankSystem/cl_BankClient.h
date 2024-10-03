#pragma once
#include<string>
#include<vector>
#include<fstream>
#include"cl_Person.h"
#include"cl_string.h"
#include"cl_Date.h"
#include"cl_Util.h"


string The_file = "Mysecond.txt";
string Register_tarnsfer_file = "Tarnsfer_Register.txt";

class cl_BankClient : public cl_Person
{
	enum en_Mode { Empty_mode = 0, Update_mode, Add_mode };
	en_Mode pi_Mode;

	string pi_Account_number;
	string pi_Pin_code;
	float pi_Account_balance;

	bool pi_Deleted = false;

	void pi_Transfer_register(cl_BankClient &Client_To, float Amount) {
		fstream MyFile;
		MyFile.open(Register_tarnsfer_file, ios::out | ios::app);
		if (MyFile.is_open()) {
			MyFile << pi_Transfer_info_to_string(Client_To, Amount, "#//#") << endl;
			MyFile.close();
		}
	}

	string pi_Transfer_info_to_string(cl_BankClient &Client_To, float Amount,string character = " ") {
		string String = "";

		return cl_Date::Get_system_accurate_date().print_date() + character + pi_Account_number + character + Client_To.Account_number + character + to_string(pi_Account_balance+ Amount) + character + to_string(Client_To.Account_balance- Amount) + character + to_string(pi_Account_balance) + character + to_string(Client_To.Account_balance) + character + Currently_User.UserName;
	}

	static cl_BankClient pi_string_to_Client(string data, string character = " ") {

		vector <string> v_Client = cl_string::sepreate_the_words_and_put_in_vector(data, character);

		return cl_BankClient(v_Client[0], v_Client[1], v_Client[2], v_Client[3],
			v_Client[4], cl_Util::Decrypt_word(v_Client[5],4), stof(v_Client[6]), Update_mode);
	}

	static string pi_Client_to_string(cl_BankClient Client, string character = " ") {

		return Client.First_name + character + Client.Last_name + character + Client.Email + character + Client.Phone + character + Client.Account_number + character + cl_Util::Encrypt_word(Client.Pin_code,4) + character + to_string(Client.Account_balance);
	}

	static void pi_load_data_from_file_to_vector(string File_name, vector <cl_BankClient> &vline) {
		fstream MyFile;
		MyFile.open(File_name, ios::in);
		if (MyFile.is_open()) {

			string line;
			while (getline(MyFile, line)) {
				vline.push_back(pi_string_to_Client(line, "/##/"));
			}

			MyFile.close();
		}
	}

	static bool pi_search_for_client(string Account_number, cl_BankClient *&Client, vector <cl_BankClient> &vline) {

		for (cl_BankClient &c : vline) {
			if (c.Account_number == Account_number) {
				Client = &c;

				return true;
			}
		}

		return false;
	}

	static bool pi_search_for_client(string Account_number, cl_BankClient *&Client, vector <cl_BankClient> &vline,string Pin_code) {

		for (cl_BankClient &c : vline) {
			if (c.Account_number == Account_number && c.Pin_code == Pin_code) {
				Client = &c;

				return true;
			}
		}

		return false;
	}

	static void pi_load_data_from_vector_to_file(vector <cl_BankClient> &vline) {
		fstream MyFile;
		MyFile.open(The_file, ios::out);
		if (MyFile.is_open()) {

			for (cl_BankClient &line : vline) {
				if (!line.Mark_deleted())
					MyFile << pi_Client_to_string(line, "/##/") << endl;

			}
			MyFile.close();
		}
		vline.clear();
	}

	static cl_BankClient pi_Get_empty_client_object() {
		return cl_BankClient("", "", "", "", "", "", 0, Empty_mode);
	}

	void pi_Update() {
		cl_BankClient *Client;
		string Account_number;
		vector <cl_BankClient> v_Client;
		pi_load_data_from_file_to_vector(The_file, v_Client);

		pi_search_for_client(pi_Account_number, Client, v_Client);
		*Client = *this;

		pi_load_data_from_vector_to_file(v_Client);

	}

	void pi_Add_new(){

		vector <cl_BankClient> v_Client;
		pi_load_data_from_file_to_vector(The_file, v_Client);
		v_Client.push_back(*this);
		pi_load_data_from_vector_to_file(v_Client);
	}

public:

	cl_BankClient(string First_name, string Last_name, string Email, string Phone, string Account_number, string Pin_code, float Account_balance, en_Mode Mode)
		:cl_Person(First_name, Last_name, Email, Phone),
		pi_Mode(Mode),
		pi_Account_number(Account_number),
		pi_Pin_code(Pin_code),
		pi_Account_balance(Account_balance) {

	}

	bool Is_empty() {
		return (pi_Mode == Empty_mode);
	}

	bool Mark_deleted() {
		return pi_Deleted;
	}

	string Get_Account_number() {
		return pi_Account_number;
	}

	__declspec(property(get = Get_Account_number)) string Account_number;

	void Set_Pin_code(string Pin_code) {
		pi_Pin_code = Pin_code;
	}

	string Get_Pin_code() {
		return pi_Pin_code;
	}

	__declspec(property(get = Get_Pin_code, put = Set_Pin_code)) string Pin_code;
	
	void Set_Account_balance(float Account_balance) {
		pi_Account_balance = Account_balance;
	}

	float Get_Account_balance() {
		return pi_Account_balance;
	}

	__declspec(property(get = Get_Account_balance, put = Set_Account_balance)) float Account_balance;

	static cl_BankClient Find_Client(string Account_number) {
		cl_BankClient *Client;
		vector <cl_BankClient> v_Client;

		pi_load_data_from_file_to_vector(The_file, v_Client);

		Client = NULL;
		if (pi_search_for_client(Account_number, Client, v_Client)) {
			return *Client;
		}
		else
			return pi_Get_empty_client_object();
	}

	static cl_BankClient Find_Client(string Account_number, string Pin_code) {
		cl_BankClient *Client;
		vector <cl_BankClient> v_Client;

		pi_load_data_from_file_to_vector(The_file, v_Client);

		Client = NULL;
		if (pi_search_for_client(Account_number, Client, v_Client,Pin_code))
			return *Client;
		else
			return pi_Get_empty_client_object();
	}

	static bool Is_client_exist(string Account_number) {
		cl_BankClient Client = cl_BankClient::Find_Client(Account_number);
		return !Client.Is_empty();
	}

	static cl_BankClient Get_add_new_client_object(string Account_number) {
		return cl_BankClient("", "", "", "", Account_number, "", 0, Add_mode);
	}
	
	enum en_Save_result { Save_faild_empty_object = 0, Save_faild_account_number_object, Save_succeeded };

	en_Save_result Save() {
		switch (pi_Mode)
		{
		case cl_BankClient::Empty_mode:
			return Save_faild_empty_object;
		case cl_BankClient::Update_mode:
			pi_Update();
			return Save_succeeded;
		case cl_BankClient::Add_mode:
		{
			if (cl_BankClient::Is_client_exist(pi_Account_number))
				return Save_faild_account_number_object;
			pi_Add_new();
			return Save_succeeded;
		}

		}
	}

	bool Delete() {
		cl_BankClient *Client;
			vector <cl_BankClient> v_Client;
			pi_load_data_from_file_to_vector(The_file, v_Client);
		if (cl_BankClient::pi_search_for_client(pi_Account_number,Client,v_Client)) {
			pi_Deleted = true;
			*Client = *this;
			pi_load_data_from_vector_to_file(v_Client);
		*this = Get_add_new_client_object("");
		return true;
		}
		return false;
	}

	static vector <cl_BankClient> Get_client_list() {
		vector <cl_BankClient> v_Client;
		pi_load_data_from_file_to_vector(The_file, v_Client);
		return v_Client;
	}

	static double Get_total_balance() {
		double Total_Balance = 0;
		vector <cl_BankClient> v_Client = cl_BankClient::Get_client_list();

		for (cl_BankClient &Client : v_Client) {
			Total_Balance += Client.Account_balance;
		}
		return Total_Balance;
	}

	void Deposit(float Account_balance) {
		pi_Account_balance += Account_balance;
		pi_Update();
	}

	void Withdraw(float Account_balance) {
		pi_Account_balance -= Account_balance;
		pi_Update();
	}

	static vector <string> Get_Register_list() {
		vector <string> v_Line;
		fstream MyFile;
		MyFile.open(Register_tarnsfer_file, ios::in);
		if (MyFile.is_open()) {

			string line;
			while (getline(MyFile, line)) {
				v_Line.push_back(line);
			}

			MyFile.close();
		}
		return v_Line;
	}

	bool Transfer(float Amount,cl_BankClient &Client_To) {
		if (Amount > 0 && Amount <= pi_Account_balance) {
			Withdraw(Amount);
			Client_To.Deposit(Amount);
			pi_Transfer_register(Client_To, Amount);
			return true;
		}
		else return false;
	}


};

