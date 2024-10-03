#pragma once
#pragma warning(disable : 4996)

#include<iostream>
#include<ctime>
#include<string>
#include<vector>
#include"Validations.h"

using namespace std;

class cl_Date
{
	short pi_Year;
	short pi_Month;
	short pi_Day;

	struct
	{
		short pi_Hour = -1;
		short pi_Minute = -1;
		short pi_Second = -1;
	};

	cl_Date(short Day, short Month, short Year,short Hour,short Minute,short Second) :pi_Day(Day), pi_Month(Month), pi_Year(Year),pi_Hour(Hour),pi_Minute(Minute),pi_Second(Second) {

	}

public:
	enum en_comparison { Before = -1, Equal, After };

	cl_Date() {
		time_t t = time(0);
		tm* now = localtime(&t);
		pi_Day = now->tm_mday;
		pi_Month = now->tm_mon + 1;
		pi_Year = now->tm_year + 1900;
	}

	cl_Date(string str_Date) {
		cl_Date Date;
		Date = String_to_date(str_Date);
		pi_Year = Date.Year;
		pi_Month = Date.Month;
		pi_Day = Date.Day;
	}

	cl_Date(short Day,short Month,short Year):pi_Day(Day),pi_Month(Month),pi_Year(Year) {

	}

	cl_Date(short Total, short Year) {
		pi_Year = Year;
		cl_Date Date = The_date_from_total_days(Total);
		pi_Year = Date.Year;
		pi_Month = Date.Month;
		pi_Day = Date.Day;
	}

	void Set_Year(short Year) {
		pi_Year = Year;
	}

	short Get_Year() {
		return pi_Year;
	}

	void Set_Month(short Month) {
		pi_Month = Month;
	}

	short Get_Month() {
		return pi_Month;
	}

	void Set_Day(short Day) {
		pi_Day = Day;
	}

	short Get_Day() {
		return pi_Day;
	}

	__declspec(property(get = Get_Year, put = Set_Year)) short Year;

	__declspec(property(get = Get_Month, put = Set_Month)) short Month;

	__declspec(property(get = Get_Day, put = Set_Day)) short Day;

	void Print() {
		cout << "Date : "+print_date()+'\n';
	}

	bool Is_normal_date() {
		return pi_Hour == -1;
	}

	static string print_date(cl_Date Date) {
		return to_string(Date.Get_Day()) + '/' + to_string(Date.Get_Month()) + '/' + to_string(Date.Get_Year());
	}

	string print_date() {
		if (Is_normal_date())
			return print_date(*this);
		else
			return to_string(pi_Day) + '/' + to_string(Month) + '/' + to_string(pi_Year) + " - " + to_string(pi_Hour) + ':' + to_string(pi_Minute) + ':' + to_string(pi_Second);
	}

	static cl_Date Get_system_date() {
		time_t t = time(0);
		tm* now = localtime(&t);
		return cl_Date(now->tm_mday,now->tm_mon + 1, now->tm_year + 1900);
	}

	static cl_Date Get_system_accurate_date() {
		time_t t = time(0);
		tm* now = localtime(&t);
		return cl_Date(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900,now->tm_hour,now->tm_min,now->tm_sec);
	}

	vector <string> Split_string(string word, string Caracter = "/") {
		vector <string> v_String;
		short size = word.find('/');
		while (size != string::npos) {
			v_String.push_back(word.substr(0, size));
			word = word.erase(0, size + 1);
			size = word.find('/');
		}
		v_String.push_back(word.substr(0, size));

		return v_String;

	}

	cl_Date String_to_date(string s_Date, string Caracter = "/") {
		cl_Date Date;
		vector <string> v_Date;
		v_Date = Split_string(s_Date);
		Date.Set_Day(stoi(v_Date[0]));
		Date.Set_Month(stoi(v_Date[1]));
		Date.Set_Year(stoi(v_Date[2]));

		return Date;
	}

	static string Five_spaces(short Number) {
		string space = "";
		for (short x = 0; x < Number; x++)
			space += "     ";
		return space;
	}

	static string Days_name(short index) {

		string Days[7]{ "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return Days[index];
	}

	static short Day_of_the_week(cl_Date Date) {
		Date.Set_Day(1);
		short a, y, m, d;
		a = (14 - Date.Get_Month()) / 12;
		y = Date.Get_Year() - a;
		m = Date.Get_Month() + 12 * a - 2;

		d = (Date.Get_Day() + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
		return d;
	}

	static bool Leap_year(short Year) {
		return  (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
	}

	bool Leap_year() {
		return Leap_year(pi_Year);
	}
	 
	static short Number_of_days_in_year(short Year) {
		return Leap_year(Year) ? 366 : 365;
	}

	short Number_of_days_in_year() {
		return Number_of_days_in_year(pi_Year);
	}
	 
	static short Number_of_hours_in_year(short Year) {
		return Number_of_days_in_year(Year) * 24;
	}

	short Number_of_hours_in_year() {
		return Number_of_hours_in_year(pi_Year);
	}
	 
	static int Number_of_minutes_in_year(short Year) {
		return Number_of_hours_in_year(Year) * 60;
	}

	int Number_of_minutes_in_year() {
		return Number_of_minutes_in_year(pi_Year);
	}
	 
	static int Number_of_seconds_in_year(short Year) {
		return Number_of_minutes_in_year(Year) * 60;
	}

	int Number_of_seconds_in_year() {
		return Number_of_seconds_in_year(pi_Year);
	}
	 
	static short Number_of_days_in_month(short Year, short Month) {

		switch (Month)
		{
		case 2:
			return (Leap_year(Year)) ? 29 : 28;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		}
		return 30;
	}

	short Number_of_days_in_month() {
		return Number_of_days_in_month(pi_Year, pi_Month);
	}
	 
	static short Number_of_hours_in_month(short Year, short Month) {
		return Number_of_days_in_month(Year, Month) * 24;
	}

	short Number_of_hours_in_month() {
		return Number_of_hours_in_month(pi_Year, pi_Month);
	}
	 
	static int Number_of_minutes_in_month(short Year, short Month) {
		return Number_of_hours_in_month(Year, Month) * 60;
	}

	int Number_of_minutes_in_month() {
		return Number_of_minutes_in_month(pi_Year, pi_Month);
	}
	 
	static int Number_of_seconds_in_month(short Year, short Month) {
		return Number_of_minutes_in_month(Year, Month) * 60;
	}

	int Number_of_seconds_in_month() {
		return Number_of_seconds_in_month(pi_Year, pi_Month);
	}

	static void Print_month_calendar(cl_Date Date) {
		string Months[]{ "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		bool now = false;
		short x = 1;
		short index = Day_of_the_week(Date);
		cout << "\n  _______________" + Months[Date.Get_Month() - 1] + "_______________\n\n  ";
		for (short x = 0; x < 7; x++)
			cout << Days_name(x) + "  ";
		cout << endl << "  ";
		cout << Five_spaces(index);
		while (x <= (Number_of_days_in_month(Date.Get_Year(), Date.Get_Month()))) {
			printf("%*d  ", 3, x);
			if ((x + index) % 7 == 0)
				cout << endl << "  ";
			x++;
		}
		cout << "\n  _________________________________\n\n";
	}

	void Print_month_calendar() {
		Print_month_calendar(*this);
	}

	static void Print_year_calendar(short Year) {
		cout << "\n  _________________________________\n\n";
		cout << "\t  calendar = " << Year << '\n';
		cout << "\n  _________________________________\n\n";
		cl_Date Date;
		for (short x = 1; x <= 12; x++) {
			Print_month_calendar(Date);
		}
	}

	void Print_year_calendar() {
		Print_year_calendar(pi_Year);
	}

	static short Total_days_from_the_beginning_of_year(cl_Date Date) {
		short Total = 0;
		for (short x = 1; x < Date.Get_Month(); x++) {
			Total += Number_of_days_in_month(Date.Get_Year(), x);
		}
		return Total + Date.Get_Day();
	}

	short Total_days_from_the_beginning_of_year() {
		return Total_days_from_the_beginning_of_year(*this);
	}

	static cl_Date The_date_from_total_days(cl_Date Date1, short Total) {
		cl_Date Date;
		Date.Set_Year(Date1.Get_Year());
		Date.Set_Day(1);
		Date.Set_Month(1);
		short Days_of_the_month;
		short x = 1;
		while (true) {
			if ((Days_of_the_month = Number_of_days_in_month(Date.Get_Year(), x)) < Total) {
				Date.Set_Month(Date.Get_Month()+1);
				Total -= Days_of_the_month;
			}
			else {
				Date.Set_Day(Total);
				return Date;
			}
			x++;
		}
	}

	cl_Date The_date_from_total_days(short Total) {
		return The_date_from_total_days(*this, Total);
	}

	static cl_Date DateAddDays(short Days, cl_Date Date) {
		short RemainingDays = Days + Total_days_from_the_beginning_of_year(Date);
		short MonthDays = 0;
		Date.Month = 1;
		while (true) {
			MonthDays = Number_of_days_in_month(Date.Year, Date.Month);
			if (RemainingDays > MonthDays) {
				RemainingDays -= MonthDays;
				Date.Month++;
				if (Date.Month > 12) {
					Date.Month = 1;
					Date.Year++;
				}
			}
			else {
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;
	}

	cl_Date DateAddDays(short Days) {
		return DateAddDays(Day, *this);
	}

	static bool Is_date1_less_than_date2(cl_Date Date1, cl_Date Date2) {
		return(Date1.Year > Date2.Year) ? false : ((Date1.Year != Date2.Year) ? true : ((Date1.Month > Date2.Month) ? false : ((Date1.Month != Date2.Month) ? true : ((Date1.Day >= Date2.Day) ? false : true))));
	}

	bool Is_date1_less_than_date2(cl_Date Date2) {
		return Is_date1_less_than_date2(*this, Date2);
	}

	static bool Is_date1_equal_to_date2(cl_Date Date1, cl_Date Date2) {
		return(Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day);
	}

	bool Is_date1_equal_to_date2(cl_Date Date2) {
		return Is_date1_equal_to_date2(*this, Date2);
	}

	static bool Is_last_day_in_month(cl_Date Date) {
		return Date.Day == Number_of_days_in_month(Date.Year, Date.Month);
	}

	bool Is_last_day_in_month() {
		return Is_last_day_in_month(*this);
	}

	static bool Is_last_month_in_year(cl_Date Date) {
		return Date.Month == 12;
	}

	bool Is_last_month_in_year() {
		return Is_last_month_in_year(*this);
	}

	static cl_Date Adding_a_day_to_date(cl_Date Date1) {
		cl_Date Date2 = Date1;
		if (!Is_last_day_in_month(Date2))
			Date2.Day++;
		else if (!Is_last_month_in_year(Date2)) {
			Date2.Month++;
			Date2.Day = 1;
		}
		else {
			Date2.Year++;
			Date2.Day = 1;
			Date2.Month = 1;
		}
		return Date2;
	}

	cl_Date Adding_a_day_to_date() {
		return Adding_a_day_to_date(*this);
	}

	static void Sawp_dates(cl_Date &Date1, cl_Date &Date2) {
		cl_Date Temp = Date1;
		Date1 = Date2;
		Date2 = Temp;
	}

	void Sawp_dates(cl_Date &Date2) {
		return Sawp_dates(*this, Date2);
	}

	static short difference_in_days(cl_Date Date1, cl_Date Date2, bool Include_end_day = false) {
		short sawp_value = 1;
		if (!Is_date1_less_than_date2(Date1, Date2)) {
			sawp_value = -1;
			Sawp_dates(Date1, Date2);
		}
		short counter = 0;
		while (!Is_date1_equal_to_date2(Date1, Date2)) {
			Date1 = Adding_a_day_to_date(Date1);
			counter++;
		}
		return Include_end_day ? ++counter *sawp_value : counter *sawp_value;
	}

	short difference_in_days(cl_Date Date2, bool Include_end_day = false) {
		return difference_in_days(*this, Date2, Include_end_day);
	}

	static bool Is_date1_After_date2(cl_Date Date1, cl_Date Date2) {
		return !Is_date1_less_than_date2(Date1, Date2) && !Is_date1_equal_to_date2(Date1, Date2);
	}

	bool Is_date1_After_date2(cl_Date Date2) {
		return Is_date1_After_date2(*this, Date2);
	}

	static en_comparison Comparison_date1_date2(cl_Date Date1, cl_Date Date2) {
		return Is_date1_less_than_date2(Date1, Date2) ? Before : (Is_date1_equal_to_date2(Date1, Date2) ? Equal : After);
	}

	en_comparison Comparison_date1_date2(cl_Date Date2) {
		return Comparison_date1_date2(*this, Date2);
	}

};

