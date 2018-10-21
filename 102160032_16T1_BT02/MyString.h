#pragma once
#include <iostream>
using namespace std;
class MyString
{
private:
	char * str;
	int length;
public:
	MyString();
	MyString(const char *);
	MyString(const MyString &);
	MyString(const char);
	~MyString();
	int getLength() const;
	bool isEmpty() const;
	void clear();
	void push_back(char c);
	void pop_back();
	MyString & insert(const MyString &); // insert string s into last position of string 
	MyString & insert(int , const MyString &); // insert string s into K_position

	/*get element*/
	char charAt(const int idx);
	char& operator[] (const int idx);
	char operator[] (const int idx) const;

	/*substring*/
	MyString substr(int i, int n = -1) const; // generate a substring from i position with length = n
	int find(const MyString &) const;

	/*replace string*/
	MyString & replace(int pos, int len, const MyString & s);

	/*string concatenation*/
	MyString  operator+ (const MyString &);
	friend MyString operator+ (const char, const MyString &);
	friend MyString operator+ (const char*, const MyString &);

	MyString  operator& (const MyString &);
	friend MyString operator& (const char, const MyString &);
	friend MyString operator& (const char*, const MyString &);

	MyString & operator+= (const MyString &);
	MyString append(const MyString &);

	/*string assignment*/
	const MyString & operator= (const MyString &);
	MyString& assign(const MyString &);
	MyString& assign(int, const char);

	/* operator compare */
	bool operator== (const MyString &) const;
	friend bool operator== (const char, const MyString &);
	friend bool operator== (const char *, const MyString &);

	bool operator!= (const MyString &) const;
	friend bool operator!= (const char, const MyString &);
	friend bool operator!= (const char *, const MyString &);

	bool operator > (const MyString &) const;
	friend bool operator> (const char, const MyString &);
	friend bool operator> (const char *, const MyString &);

	bool operator>= (const MyString &) const;
	friend bool operator>= (const char, const MyString &);
	friend bool operator>= (const char *, const MyString &);


	bool operator < (const MyString &) const;
	friend bool operator< (const char, const MyString &);
	friend bool operator< (const char *, const MyString &);

	bool operator<= (const MyString &) const;
	friend bool operator<= (const char, const MyString &);
	friend bool operator<= (const char *, const MyString &);

	int compare(const MyString &) const;

	friend istream & operator >> (istream & in,MyString & );
	friend ostream & operator << (ostream & o, MyString & );
};

