#pragma once
#include<iostream>

using namespace std;

class cl_Person {
	string pi_First_name;
	string pi_Last_name;
	string pi_Email;
	string pi_Phone;

public:
	cl_Person(string First_name, string Last_name, string Email, string Phone) : pi_First_name(First_name), pi_Last_name(Last_name), pi_Email(Email), pi_Phone(Phone)
	{

	}

	void Set_First_name(string First_name) {
		pi_First_name = First_name;
	}

	string Get_First_name() {
		return pi_First_name;
	}

	__declspec(property(get = Get_First_name, put = Set_First_name)) string First_name;

	void Set_Last_name(string Last_name) {
		pi_Last_name = Last_name;
	}

	string Get_Last_name() {
		return pi_Last_name;
	}

	__declspec(property(get = Get_Last_name, put = Set_Last_name)) string Last_name;

	void Set_Email(string Email) {
		pi_Email = Email;
	}

	string Get_Email() {
		return pi_Email;
	}

	__declspec(property(get = Get_Email, put = Set_Email)) string Email;

	void Set_Phone(string Phone) {
		pi_Phone = Phone;
	}

	string Get_Phone() {
		return pi_Phone;
	}

	__declspec(property(get = Get_Phone, put = Set_Phone)) string Phone;

	string Full_name() {
		return pi_Last_name + ' ' + pi_First_name;
	}

};
