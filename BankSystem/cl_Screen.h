#pragma once
#include<iostream>
#include"cl_string.h"
#include"cl_Validation.h"
#include"cl_User.h"
#include"cl_Person.h"
#include"Global.h"
#include"cl_Date.h"

using namespace std;

class cl_Screen
{
protected:

	static void po_Draw_screen_header(string Title, string Subtitle = "") {
		system("cls");
		cout << cl_string::Tabs(5) + "___________________________________________";
		cout << "\n\n   " << cl_string::Tabs(5) + Title;
		if (Subtitle != "")
			cout << "\n    " + cl_string::Tabs(5) + Subtitle;
		cout << "\n"+cl_string::Tabs(5) + "___________________________________________\n\n";
		cout << "\n" + cl_string::Tabs(5) + "User:"+Currently_User.UserName + "\n";
		cout << "\n" + cl_string::Tabs(5) + "Date:" + cl_Date::print_date(cl_Date()) + "\n\n";
	}

	static bool Check_access_rights(cl_User::en_Permissons Permissons) {
		if (!Currently_User.Check_Permissions(Permissons)) {
			system("cls");
			cout << cl_string::Tabs(5) << "___________________________________________";
			cout << "\n\n" + cl_string::Tabs(5) + "  Access Denied! Contact your Admin.";
			cout << "\n" + cl_string::Tabs(5) << "___________________________________________";
			cout << "\n\n\nPress any key to go back to Menue...";
			system("pause>0");
			return false;
		}
		else
			return true;
	}
	
};

