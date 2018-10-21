#include <iostream>
#include "MyString.h"
using namespace std;
int main() {
	// constructor convert from char* to MyString
	MyString s1("Le Cam ");
	// copy constructor
	MyString s2(s1);

	cout << "MyString s1: "<< s1 << endl;
	cout << "MyString s2: "<< s2 << endl;

	cout << "s1 == s2 : "<<(s1 == s2) << endl;
	cout << "s1 != s2 : "<< (s1 != s2) << endl;
	
	cout << "Assign s1 = 102160032_16T1_BT02" << endl;
	s1 = "102160032_16T1_BT02";
	cout << "Get character by operator[] at position = 2 of s1: " << s1[2] << endl;
	MyString s = s1 + " " + s2;
	cout << "Concatenation string by operator + (s = s1 + s2) : " << s << endl;

	cout << "Compare s1 and s2 by operator :" << endl;
	cout << "\t + (s1 > s2) = " << (s1 > s2) << endl;
	cout << "\t + (s1 >= s2) = " << (s1 >= s2) << endl;
	cout << "\t + (s1 < s2) = " << (s1 < s2) << endl;
	cout << "\t + (s1 <= s2) = " << (s1 <= s2) << endl;

	cout << "Concatenation string by operator += (s1 += \" EXERCISE_2_OOP_MyString\"): ";
	s1 += " EXERCISE_2_OOP_MyString";
	cout << s1 << endl;

	system("pause");
	return 0;
}