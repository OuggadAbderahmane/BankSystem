#pragma once
#include "cl_Date.h"

class cl_Validation
{
public:
	static double Read_and_check_number(string Your_message_when_fail_input = "") {
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
	static double Read_positve_number(string message) {
		int number;
		cout << message;
		number = Read_and_check_number("Please enter a number :");
		while (number <= 0)
		{
			cout << "please enter again :";
			cin >> number;
		}
		return number;
	}
	static bool Check_is_validate(cl_Date Date) {
		if (Date.Month > 12 || Date.Month <1 || Date.Day <1 || Date.Year <1)
			return false;
		else
			return (Date.Day <= Date.Number_of_days_in_month());
	}
	static bool Check_is_between_them(int Number_to_check, int From, int To) {
		return(Number_to_check >= From && Number_to_check <= To);
	}
	static bool Check_is_between_them(double Number_to_check, double From, double To) {
		return(Number_to_check >= From && Number_to_check <= To);
	}
	static bool Check_is_between_them(cl_Date Date_to_check, cl_Date From, cl_Date To) {
		return (cl_Date::Is_date1_equal_to_date2(Date_to_check,From)) || cl_Date::Is_date1_equal_to_date2(Date_to_check, To) || 
			((cl_Date::Comparison_date1_date2(Date_to_check, From) == cl_Date::Before) && 
				((cl_Date::Comparison_date1_date2(Date_to_check, To) == cl_Date::After))) ||((cl_Date::Comparison_date1_date2(Date_to_check, From) == cl_Date::After) &&
					((cl_Date::Comparison_date1_date2(Date_to_check, To) == cl_Date::Before)));
	}
	static int Read_number_between(int From, int To,string message) {
		int number;
		cout << message;
		number = Read_and_check_number("Please enter a number :");
		while (!Check_is_between_them(number, From, To))
		{
			cout << "Number is not within range.\nplease enter again :";
			number = Read_and_check_number();
		}
		return number;
	}
	static double Read_number_between(double From, double To, string message) {
		double number;
		cout << message;
		number = Read_and_check_number("Please enter a number :");
		while (!Check_is_between_them(number, From, To))
		{
			cout << "Number is not within range.\nplease enter again :";
			number = Read_and_check_number();
		}
		return number;
	}

};

