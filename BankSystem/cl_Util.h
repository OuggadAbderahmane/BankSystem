#pragma once
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include"cl_Validation.h"

using namespace std;

class cl_Util
{
public:

	static enum en_is_it_prime {
		Prime,
		Not_prime
	};
	static enum en_is_it_profect_number {
		Profect,
		Not_profect
	};
	static enum en_Is_palindrome
	{
		Palindrome,
		Not_palindrome
	};
	static enum en_rondom {
		Small_letter,
		Capitl_letter,
		Special_character,
		Digit
	};	

	static void Srand() {
		srand((unsigned)time(NULL));
	}
	static void Print_Vector(vector <int> &Array, int length) {
		for (int x = 0; x < length; x++)
			cout << Array[x] << ' ';
	}
	static void Print_array(int Array[], int length) {
		for (int x = 0; x < length; x++)
			cout << Array[x] << ' ';
	}
	static void Swap(short &number1, short &number2) {
		short tmp;
		tmp = number1;
		number1 = number2;
		number2 = tmp;
	}
	static void Swap(int &number1, int &number2) {
		int tmp;
		tmp = number1;
		number1 = number2;
		number2 = tmp;
	}
	static void Swap(float &number1, float &number2) {
		float tmp;
		tmp = number1;
		number1 = number2;
		number2 = tmp;
	}
	static void Swap(double &number1, double &number2) {
		double tmp;
		tmp = number1;
		number1 = number2;
		number2 = tmp;
	}
	static en_is_it_prime prime_number(int Number) {
		if (Number < 1)
			return Not_prime;
		else if (Number == 1)
			return Prime;
		for (int x = 2; x <= sqrt(Number); x++) {
			if (Number % x == 0)
				return Not_prime;
		}

		return Prime;

	}
	static int Sum_all_divisors_fo_number(int number) {
		int Sum = 0;
		for (int x = 1; x < number; x++)
			if (number % x == 0)
				Sum += x;
		return Sum;
	}
	static en_is_it_profect_number Number_is_profect_or_not(int number) {
		if (Sum_all_divisors_fo_number(number) == number)
			return Profect;
		else
			return Not_profect;
	}
	static int reversed_number(int number) {
		int New_number = 0;
		while (number > 0) {
			New_number *= 10;
			New_number += number % 10;
			number /= 10;
		}
		return New_number;
	}
	static en_Is_palindrome Is_it_a_palindrome_number(int number) {
		if (number == reversed_number(number))       
			return Palindrome;
		else
			return Not_palindrome;
	}
	static string Encrypt_word(string word, short code_number = 1) {
		for (int x = 0; x < word.length(); x++) {
			if ((word[x] >= 65 && word[x] >= 88) || (word[x] >= 90 && word[x] >= 114))
				word[x] += code_number;
			else if ((word[x] >= 89 && word[x] >= 90) || (word[x] >= 115 && word[x] >= 116))
				word[x] -= 26 - code_number;
			else
				word[x] += code_number;
		}
		return word;
	}
	static string Decrypt_word(string word, short code_number = 1) {
		for (int x = 0; x < word.length(); x++) {
			if ((word[x] >= 65 && word[x] >= 88) || (word[x] >= 97 && word[x] >= 120))
				word[x] -= code_number;
			else if ((word[x] >= 89 && word[x] >= 90) || (word[x] >= 121 && word[x] >= 122))
				word[x] += 26 - code_number;
			else 
				word[x] -= code_number;
		}
		return word;
	}
	static int Random_number(int from, int to) {
		return (rand() % (to - from + 1)) + from;
	}
	static char return_random_you_want(en_rondom want) {
		if (want == Capitl_letter)
			return Random_number(65, 90);
		else if (want == Small_letter)
			return Random_number(97, 122);
		else if (want == Special_character)
			return Random_number(33, 47);
		else if (want == Digit)
			return Random_number(0, 9);
	}
	static string Four_random_characters(en_rondom want) {
		string word = "";
		for (int x = 0; x < 4; x++)
			word += return_random_you_want(want);

		return word;
	}
	static string Make_keys_x_code(en_rondom want, short Code_number = 4) {
		string word = "";
		for (int x = 1; x <= Code_number; x++) {
			word += Four_random_characters(want);
			if (x != Code_number)
				word += '-';
		}
		return word;
	}
	static void Copy_to_string_vector(vector <string> &Array_destination, int length, short Code_number = 4) {
		for (int x = 0; x < length; x++)
			Array_destination.push_back(Make_keys_x_code(Capitl_letter));
	}
	static void Print_keys(int number) {
		vector <string> word;
		Copy_to_string_vector(word, number);
		for (int x = 0; x < number; x++)
			cout << "Key [" << x + 1 << "] : " << word[x] << "\n";

	}
	static void Fill_array(int Array[], int &length) {
		length = cl_Validation::Read_positve_number("Enter how many elements you want :");
		for (int x = 0; x < length; x++) {
			Array[x] = cl_Validation::Read_positve_number("Element [" + to_string(x + 1) + "] : ");
		}
	}
	static int How_many_times_repeated_in_array(int Array[], int length, int digit) {
		int counter = 0;
		for (int x = 0; x < length; x++)
			if (Array[x] == digit)
				counter++;
		return counter;
	}
	static int How_many_times_repeated_in_array(string Array[], int length, string word) {
		int counter = 0;
		for (int x = 0; x < length; x++)
			if (Array[x] == word)
				counter++;
		return counter;
	}
	static void Fill_array_with_random_numbers_from_1_to_100(vector <int> &Array, int &length) {
		Array.clear();
		length = cl_Validation::Read_positve_number("Enter how many elements you want :");
		for (int x = 0; x < length; x++)
			Array.push_back(Random_number(1, 100));
	}
	static void Fill_array_with_random_numbers_from_1_to_100(int Array[], int &length) {

		length = cl_Validation::Read_positve_number("Enter how many elements you want :");
		for (int x = 0; x < length; x++)
			Array[x] = Random_number(1, 100);
	}
	static double Max_number_in_Vecter(vector <double> &Vector, int length) {
		double max = Vector[0];
		for (double &x : Vector)
			if (max < x)
				max = x;
		return max;
	}
	static double Max_number_in_arrey(double Array[], int length) {
		double max = Array[0];
		for (int x = 1; x < length; x++)
			if (max < Array[x])
				max = Array[x];
		return max;
	}
	static double Min_number_in_Vecter(vector <double> &Vector, int length) {
		double min = Vector[0];
		for (double x = 1; x < length; x++)
			if (min > Vector[x])
				min = Vector[x];
		return min;
	}
	static double Min_number_in_arrey(double Array[], int length) {
		double min = Array[0];
		for (int x = 1; x < length; x++)
			if (min > Array[x])
				min = Array[x];
		return min;
	}
	static int Max_number_in_Vecter(vector <int> &Vector, int length) {
		int max = Vector[0];
		for (int &x : Vector)
			if (max < x)
				max = x;
		return max;
	}
	static int Max_number_in_arrey(int Array[], int length) {
		int max = Array[0];
		for (int x = 1; x < length; x++)
			if (max < Array[x])
				max = Array[x];
		return max;
	}
	static int Min_number_in_Vecter(vector <int> &Vector, int length) {
		int min = Vector[0];
		for (int x = 1; x < length; x++)
			if (min > Vector[x])
				min = Vector[x];
		return min;
	}
	static int Min_number_in_arrey(int Array[], int length) {
		int min = Array[0];
		for (int x = 1; x < length; x++)
			if (min > Array[x])
				min = Array[x];
		return min;
	}
	static void Shuffle_array(int Array_source[], int length) {
		for (int x = 0; x < length; x++) {
			Swap(Array_source[x], Array_source[Random_number(0, length - 1)]);
		}
	}
	static void Shuffle_Vector(vector <int> &Vector_source) {
		for (int x = 0; x < Vector_source.size(); x++) {
			Swap(Vector_source[x], Vector_source[Random_number(0, Vector_source.size() - 1)]);
		}
	}
	static void Shuffle_array(double Array_source[], int length) {
		for (int x = 0; x < length; x++) {
			Swap(Array_source[x], Array_source[Random_number(0, length - 1)]);
		}
	}
	static void Shuffle_Vector(vector <double> &Vector_source) {
		for (int x = 0; x < Vector_source.size(); x++) {
			Swap(Vector_source[x], Vector_source[Random_number(0, Vector_source.size() - 1)]);
		}
	}
};

