#pragma once

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class cl_string
{
	string pi_Value;

public:
	cl_string():pi_Value("") {

	}
	
	cl_string(string Value) :pi_Value(Value)
	{
	}

	void Set_value(string Value) {
		pi_Value = Value;
	}

	string Get_Value() {
		return pi_Value;
	}

	__declspec(property(get = Get_Value, put = Set_value)) string Value;

	static vector <string> sepreate_the_words_and_put_in_vector(string sent, string character = " ") {
		vector <string> v_words;
		int counter = 0;
		short pos;
		while ((pos = sent.find(character)) != std::string::npos) {
			if (pos != 0) {
				v_words.push_back(sent.substr(0, pos));
				counter++;

			}
			sent.erase(0, pos + character.length());
		}
		if (sent != "")
			v_words.push_back(sent.substr(0, pos));
		return v_words;
	}

	vector <string> sepreate_the_words_and_put_in_vector() {
		return sepreate_the_words_and_put_in_vector(pi_Value);
	}

	static string Trim_left(string sent) {
		for (int x = 0; x < sent.length(); x++) {
			if (sent[x] != ' ') {
				sent.erase(0, x);
				break;
			}
		}
		return sent;
	}

	string Trim_left() {
		return Trim_left(pi_Value);
	}

	static string Trim_right(string sent) {
		for (int x = sent.length() - 1; x >= 0; x--) {
			if (sent[x] != ' ') {
				sent.erase(x + 1, sent.length() - 1);
				break;
			}
		}

		return sent;
	}

	string Trim_right() {
		return Trim_right(pi_Value);
	}
	
	static string Trim(string sent) {
		return Trim_left(Trim_right(sent));
	}

	string Trim() {
		return Trim(pi_Value);
	}

	static string conct_the_words_and_put_in_string(vector <string> v_words, string character = " ") {
		string String = "";

		for (int x = 0; x < v_words.size(); x++) {
			if (x != 0)
				String += character;
			String += v_words[x];
		}
		return String;
	}

	static string conct_the_words_and_put_in_string(string words[], short length, string character = " ") {
		string String = "";

		for (int x = 0; x < length; x++) {

			String += words[x] + character;
		}
		return String.substr(0, String.length() - character.length());
	}

	static string conct_the_words_and_put_in_string_revers(vector <string> v_words, string character = " ") {
		string String = "";

		for (int x = v_words.size() - 1; x >= 0; x--) {
			if (x != v_words.size() - 1)
				String += character;
			String += v_words[x];
		}
		return String;
	}

	static string reversing_words(string sent, string character = " ") {
		return conct_the_words_and_put_in_string_revers(sepreate_the_words_and_put_in_vector(sent, character), character);
	}

	string reversing_words(string character = " ") {
		return reversing_words(pi_Value, character);
	}

	static string Replace_words(string sent, string S_to_replace, string s_replace_to) {
		string word;
		short pos;
		pos = sent.find(S_to_replace);
		while (pos != string::npos) {
			word = sent.substr(0, pos) + s_replace_to;
			sent = sent.erase(0, pos + S_to_replace.length());
			sent = word + sent;
			pos = sent.find(S_to_replace);
		}
		return sent;
	}

	string Replace_words(string S_to_replace, string s_replace_to) {
		return Replace_words(pi_Value, S_to_replace, s_replace_to);
	}

	static string Read_string(string s1) {
		string s2;
		cout << s1;
		getline(cin >> ws, s2);
		return s2;
	}

	static string Tabs(int number) {
		string TABS = "";
		for (int x = 1; x <= number; x++)
			TABS += '\t';
		return TABS;
	}

	static string Upper_letter_string(string word) {
		for (short x = 0; x < word.length(); x++) {
			word[x] = toupper(word[x]);
		}
		return word;
	}

	string Upper_letter_string() {
		return Upper_letter_string(pi_Value);
	}

	static string Lower_letter_string(string word) {
		for (short x = 0; x < word.length(); x++) {
			word[x] = tolower(word[x]);
		}
		return word;
	}

	string Lower_letter_string() {
		return Lower_letter_string(pi_Value);
	}

};

