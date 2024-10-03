#pragma once

#include <iomanip>
#include "cl_Screen.h"
#include "cl_Currency.h"

class cl_CurrentiesListScreen : protected cl_Screen {

	static void pi_print_Currency_data(cl_Currency &Currency) {
		cout << "| " << left << setw(30) << Currency.Country;
		cout << "| " << left << setw(10) << Currency.Currenct_code;
		cout << "| " << left << setw(40) << Currency.Currenct_name;
		cout << "| " << Currency.Rate << endl;
	}

public:

	static void Show_Currency_list() {

		vector <cl_Currency> v_Currency = cl_Currency::Get_Currency_list();

		cl_Screen::po_Draw_screen_header("\t     Currency List Screen", "\t      (" + to_string(v_Currency.size()) + ") Currency.");

		cout << "_______________________________________________________________________________________________________\n\n";
		cout << "| " << left << setw(30) << "Country" << "| " << left << setw(10) << "Code" << "| " << left << setw(40) << "Name" << "| " << left << setw(14) << "Rate/(1$)" << endl;
		cout << "_______________________________________________________________________________________________________\n\n";
		if (v_Currency.size() != 0) {
			for (cl_Currency &Currency : v_Currency)
				pi_print_Currency_data(Currency);
			cout << "_______________________________________________________________________________________________________\n\n";
		}
		else
			cout << cl_string::Tabs(3) + "No Currency Available in the system!\n";
		cout << "\n\n\nPress any key to go back to Menue...";
		system("pause>0");
	}


};

