#pragma once

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

namespace Validations {

	double Read_and_check_number(string Your_message_when_fail_input = "Please Enter a number") {
		double Number;
		cin >> Number;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Your_message_when_fail_input;
			cin >> Number;
		}
		return Number;
	}
	char Read_and_check_char(string Your_message_when_fail_input = "") {
		char Number;
		cin >> Number;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Your_message_when_fail_input;
			cin >> Number;
		}
		return Number;
	}

}