#pragma once

#include<string>
#include<vector>
#include<fstream>
#include"cl_Person.h"
#include"cl_string.h"
#include"cl_Util.h"



string The_File = "Users.txt";
string Register_login_file = "Login_Register.txt";

class cl_User : public cl_Person
{
	enum en_Mode { Empty_mode = 1, Update_mode, Add_mode };
	en_Mode pi_Mode;

	string pi_UserName;
	string pi_Password;
	short pi_Permissions;

	bool pi_Deleted = false;

	string pi_info_to_string(string character = " ") {
		string String = "";

		return cl_Date::Get_system_accurate_date().print_date() + character + pi_UserName + character + cl_Util::Encrypt_word(pi_Password,5) + character + to_string(pi_Permissions);
	}

	static cl_User pi_string_to_User(string data, string character = " ") {

		vector <string> v_Usre = cl_string::sepreate_the_words_and_put_in_vector(data, character);

		return cl_User(v_Usre[0], v_Usre[1], v_Usre[2], v_Usre[3],
			v_Usre[4], cl_Util::Decrypt_word(v_Usre[5],5), stof(v_Usre[6]), Update_mode);
	}

	static string pi_User_to_string(cl_User user, string character = " ") {
		string String = "";

		return user.First_name + character + user.Last_name + character + user.Email + character + user.Phone + character + user.UserName + character + cl_Util::Encrypt_word(user.Password,5) + character + to_string(user.Permissions);
	}

	static void pi_load_data_from_file_to_vector(string File_name, vector <cl_User> &vline) {
		fstream MyFile;
		MyFile.open(File_name, ios::in);
		if (MyFile.is_open()) {

			string line;
			while (getline(MyFile, line)) {
				vline.push_back(pi_string_to_User(line, "#//#"));
			}

			MyFile.close();
		}
	}

	static bool pi_search_for_user(string UserName, cl_User *&User, vector <cl_User> &vline) {

		for (cl_User &c : vline) {
			if (c.UserName == UserName) {
				User = &c;

				return true;
			}
		}

		return false;
	}

	static bool pi_search_for_user(string UserName, cl_User *&User, vector <cl_User> &vline, string Password) {

		for (cl_User &c : vline) {
			if (c.UserName == UserName && c.Password == Password) {
				User = &c;

				return true;
			}
		}

		return false;
	}

	static void pi_load_data_from_vector_to_file(vector <cl_User> &vline) {
		fstream MyFile;
		MyFile.open(The_File, ios::out);
		if (MyFile.is_open()) {

			for (cl_User &line : vline) {
				if (!line.Mark_deleted())
					MyFile << pi_User_to_string(line, "#//#") << endl;

			}
			MyFile.close();
		}
		vline.clear();
	}

	static cl_User pi_Get_empty_user_object() {
		return cl_User("", "", "", "", "", "", 0, en_Mode(1));
	}

	void pi_Update() {
		cl_User *User;
		string Account_number;
		vector <cl_User> v_User;
		pi_load_data_from_file_to_vector(The_File, v_User);

		pi_search_for_user(pi_UserName, User, v_User);
		*User = *this;

		pi_load_data_from_vector_to_file(v_User);

	}

	void pi_Add_new() {

		vector <cl_User> v_User;
		pi_load_data_from_file_to_vector(The_File, v_User);
		v_User.push_back(*this);
		pi_load_data_from_vector_to_file(v_User);
	}

public:

	enum en_Permissons
	{
		Full_accsess = -1, Show_Client_List = 1,
		Add_New_Client = 2, Delete_Client = 4, Update_Client = 8,
		Find_Client = 16, Transactions = 32, Manage_Users = 64, 
		Login_Register = 128, Currency = 256
	};

	cl_User(string First_name, string Last_name, string Email, string Phone, string UserName, string Password, short Permissons, en_Mode Mode)
		:cl_Person(First_name,Last_name,Email,Phone),
		pi_Mode(Mode),
		pi_UserName(UserName),
		pi_Password(Password),
		pi_Permissions(Permissons)
		
	{

	}

	enum en_Input_patterns { Log_in, Add, check };

	bool Is_empty() {
		return (pi_Mode == Empty_mode);
	}

	bool Mark_deleted() {
		return pi_Deleted;
	}

	void Set_UserName(string UserName) {
		pi_UserName = UserName;
	}

	string Get_UserName() {
		return pi_UserName;
	}

	__declspec(property(get = Get_UserName, put = Set_UserName)) string UserName;

	void Set_Password(string Password) {
		pi_Password = Password;
	}

	string Get_Password() {
		return pi_Password;
	}

	__declspec(property(get = Get_Password, put = Set_Password)) string Password;

	void Set_Permissions(short Permissons) {
		pi_Permissions = Permissons;
	}

	short Get_Permissions() {
		return pi_Permissions;
	}

	__declspec(property(get = Get_Permissions, put = Set_Permissions)) short Permissions;

	static cl_User Find_User(string UserNAme) {
		cl_User *User;
		vector <cl_User> v_User;

		pi_load_data_from_file_to_vector(The_File, v_User);

		User = NULL;
		if (pi_search_for_user(UserNAme, User, v_User)) {
			return *User;
		}
		else
			return pi_Get_empty_user_object();
	}

	static cl_User Find_User(string UserName, string Password) {
		cl_User *User;
		vector <cl_User> v_User;

		pi_load_data_from_file_to_vector(The_File, v_User);

		User = NULL;
		if (pi_search_for_user(UserName, User, v_User, Password))
			return *User;
		else
			return pi_Get_empty_user_object();
	}

	static bool Is_user_exist(string UserName) {
		cl_User User = cl_User::Find_User(UserName);
		return !User.Is_empty();
	}

	static cl_User Get_add_new_user_object(string UserName) {
		return cl_User("", "", "", "", UserName, "", 0, Add_mode);
	}

	enum en_Save_result { Save_faild_empty_object = 0, Save_faild_account_number_object, Save_succeeded };

	en_Save_result Save() {
		switch (pi_Mode)
		{
		case cl_User::Empty_mode:
			return Save_faild_empty_object;
		case cl_User::Update_mode:
			pi_Update();
			return Save_succeeded;
		case cl_User::Add_mode:
		{
			if (cl_User::Is_user_exist(pi_UserName))
				return Save_faild_account_number_object;
			pi_Add_new();
			return Save_succeeded;
		}

		}
	}

	bool Delete() {
		cl_User *User;
		vector <cl_User> v_User;
		pi_load_data_from_file_to_vector(The_File, v_User);
		if (cl_User::pi_search_for_user(pi_UserName, User, v_User)) {
			pi_Deleted = true;
			*User = *this;
			pi_load_data_from_vector_to_file(v_User);
			*this = Get_add_new_user_object("");
			return true;
		}
		return false;
	}

	static vector <cl_User> Get_user_list() {
		vector <cl_User> v_User;
		pi_load_data_from_file_to_vector(The_File, v_User);
		return v_User;
	}

	static vector <string> Get_Register_list() {
		vector <string> v_Line;
		fstream MyFile;
		MyFile.open(Register_login_file, ios::in);
		if (MyFile.is_open()) {

			string line;
			while (getline(MyFile, line)) {
				v_Line.push_back(line);
			}

			MyFile.close();
		}
		return v_Line;
	}

	bool Check_Permissions(en_Permissons Permisson) {
		return (Permisson & pi_Permissions) != 0;
	}

	void Login_register() {
		fstream MyFile;
		MyFile.open(Register_login_file, ios::out | ios::app);
		if (MyFile.is_open()) {
			MyFile << pi_info_to_string("#//#") << endl;
			MyFile.close();
		}
	}

	
};

