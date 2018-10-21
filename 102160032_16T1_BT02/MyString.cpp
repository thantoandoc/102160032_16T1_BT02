#include <iostream>
#include "MyString.h"
#define MAX 1024
using namespace std;


MyString::MyString()
{
	this->length = 0;
	this->str = new char('\0');
}

MyString::MyString(const char * a)
{
	if (a) {
		int n = 0;
		while (a[n] != '\0') n++;
		length = n;
		this->str = new char[length];
		for (int i = 0; i < length; i++) {
			(*this)[i] = a[i];
		}
	}
}

MyString::MyString(const MyString & s)
{
	length = s.length;
	this->str = new char[length];
	for (int i = 0; i < length; i++) {
		(*this)[i] = s[i];
	}

}

MyString::MyString(const char c)
{
	length = 1;
	this->str = new char[length];
	(*this)[0] = c;
}


MyString::~MyString()
{
	delete[] this->str;
}
int MyString::getLength() const
{
	return this->length;
}

bool MyString::isEmpty() const
{

	return length == 0;
}

void MyString::clear()
{
	this->length = 0;
	delete[] this->str;
	this->str = new char('\0');
}

void MyString::push_back(char c)
{
	MyString temp;
	temp.length = this->length + 1;
	temp.str = new char[temp.length];
	for (int i = 0; i < temp.length; i++) {
		if (i < length) {
			temp[i] = (*this)[i];
		}
		else {
			temp[i] = c;
		}
	}
	*this = temp;
}

void MyString::pop_back()
{
	MyString temp;
	temp.length = this->length - 1;
	temp.str = new char[temp.length];
	for (int i = 0; i < temp.length; i++) {
		temp[i] = (*this)[i];
	}
	*this = temp;
}

MyString & MyString::insert(const MyString & s)
{
	MyString temp;
	temp.length = length + s.length;
	temp.str = new char[temp.length];
	for (int i = 0; i < temp.length; i++) {
		if (i < length) {
			temp[i] = (*this)[i];
		}
		else {
			temp[i] = s[i - length];
		}
	}
	(*this) = temp;
	return (*this);
}

MyString & MyString::insert(int pos, const MyString & s)
{
	MyString temp;
	if (pos > length) pos = length;
	temp.length = length + s.length;
	temp.str = new char[temp.length];
	for (int i = 0, j = 0; i < temp.length; i++) {
		if (i ==  pos) {
			for (int k = 0; k < s.length; k++) temp[j++] = s[k];
		}	
		temp[j++] = (*this)[i];
	}
	(*this) = temp;
	return (*this);
}

char MyString::charAt(const int idx)
{
	return (idx < length && idx >= 0) ? *(this->str + idx) : '\0';
}

char & MyString::operator[](const int idx)
{
	static char temp = '\0';
	return (idx < length && idx >= 0) ? *(this->str + idx) : temp;
}

char MyString::operator[](const int idx) const
{
	static char temp = '\0';
	return (idx < length && idx >= 0) ? *(this->str + idx) : temp;
}

MyString MyString::substr(int i, int n) const
{
	MyString s;
	if (i >= length) return s;
	if (i + n > length) return s;
	s.length = (n >= 0) ? n : length - i;
	s.str = new char[s.length];
	for (int j = 0; j < s.length; j++) {
		s[j] = (*this)[i + j];
	}
	return s;
}

int MyString::find(const MyString & s) const
{
	for (size_t i = 0; i < length - s.length; i++) {
		if (this->substr(i, s.length) == s) return i;
	}
	return -1;
}

MyString & MyString::replace(int pos, int len, const MyString & s)
{
	(*this) = (*this).substr(0, pos) + s + (*this).substr(pos + len);
	return (*this);
}

MyString MyString::operator+(const MyString & s)
{
	MyString *temp = new MyString;
	temp->length = this->length + s.length;
	temp->str = new char[temp->length];
	for (int i = 0; i < this->length; i++) {
		(*temp)[i] = (*this)[i];
	}
	for (int i = 0; i < s.length; i++) {
		(*temp)[i + this->length] = s[i];
	}
	return *temp;
}
MyString MyString::operator&(const MyString & s)
{
	MyString *temp = new MyString;
	temp->length = this->length + s.length;
	temp->str = new char[temp->length];
	for (int i = 0; i < this->length; i++) {
		(*temp)[i] = (*this)[i];
	}
	for (int i = 0; i < s.length; i++) {
		(*temp)[i + this->length] = s[i];
	}
	return *temp;
}
MyString operator+(const char c, const MyString & s)
{
	return MyString(c) + s;
}

MyString operator+(const char * c, const MyString & s)
{
	return MyString(c) + s;
}

MyString operator&(const char c, const MyString & s)
{
	return MyString(c) & s;
}

MyString operator&(const char * c, const MyString & s)
{
	return MyString(c) & s;
}

MyString & MyString::operator+=(const MyString & s)
{
	MyString *temp = new MyString;
	temp->length = this->length + s.length;
	temp->str = new char[temp->length];
	for (int i = 0; i < this->length; i++) {
		(*temp)[i] = (*this)[i];
	}
	for (int i = 0; i < s.length; i++) {
		(*temp)[i + this->length] = s[i];
	}
	*this = *temp;
	return *this;
}

MyString MyString::append(const MyString & s)
{
	MyString *temp = new MyString;
	temp->length = this->length + s.length;
	temp->str = new char[temp->length];
	for (int i = 0; i < this->length; i++) {
		(*temp)[i] = (*this)[i];
	}
	for (int i = 0; i < s.length; i++) {
		(*temp)[i + this->length] = s[i];
	}
	return *temp;
}

const MyString& MyString::operator=(const MyString & s)
{
	length = s.length;
	delete[] this->str;
	this->str = new char[this->length];
	for (int i = 0; i < length; i++) {
		(*this)[i] = s[i];
	}
	return (*this);
}

MyString & MyString::assign(const MyString & s)
{
	length = s.length;
	delete[] this->str;
	this->str = new char[this->length];
	for (int i = 0; i < length; i++) {
		(*this)[i] = s[i];
	}
	return (*this);
}

MyString & MyString::assign(int n, const char c)
{
	length = n;
	str = new char[length];
	for (int i = 0; i < n; i++) (*this)[i] = c;
	return (*this);
}

bool MyString::operator==(const MyString & s) const
{
	if (length != s.length) return false;
	for (int i = 0; i < length; i++) {
		if ((*this)[i] != s[i]) return false;
	}
	return true;
}

bool MyString::operator!=(const MyString & s) const
{
	if (length != s.length) return true;
	for (int i = 0; i < length; i++) {
		if ((*this)[i] != s[i]) return true;
	}
	return false;
}

bool MyString::operator>(const MyString & s) const
{
	int minLength = (length < s.length) ? length : s.length;
	for (int i = 0; i < minLength; i++) {
		if ((*this)[i] > s[i]) return true;
		if ((*this)[i] < s[i]) return false;
	}
	if ((*this).length > s.length) return true;
	return false;
}

bool MyString::operator>=(const MyString & s) const
{
	int minLength = (length < s.length) ? length : s.length;
	for (int i = 0; i < minLength; i++) {
		if ((*this)[i] > s[i]) return true;
		if ((*this)[i] < s[i]) return false;
	}
	if ((*this).length >= s.length) return true;
	return false;
}

bool MyString::operator<(const MyString & s) const
{
	int minLength = (length < s.length) ? length : s.length;
	for (int i = 0; i < minLength; i++) {
		if ((*this)[i] < s[i]) return true;
		if ((*this)[i] > s[i]) return false;
	}
	if ((*this).length < s.length) return true;
	return false;
}

bool MyString::operator<=(const MyString & s) const
{
	int minLength = (length < s.length) ? length : s.length;
	for (int i = 0; i < minLength; i++) {
		if ((*this)[i] < s[i]) return true;
		if ((*this)[i] > s[i]) return false;
	}
	if ((*this).length <= s.length) return true;
	return false;
}

int MyString::compare(const MyString & s) const
{
	if ((*this) > s) return 1;
	if ((*this) < s) return -1;
	return 0;
}


bool operator==(const char c, const MyString & s)
{
	return MyString(c) == s;
}

bool operator==(const char * c, const MyString & s)
{
	return MyString(c) == s;
}

bool operator!=(const char c, const MyString & s)
{
	return MyString(c) != s;
}

bool operator!=(const char * c, const MyString & s)
{
	return MyString(c) != s;
}

bool operator>(const char c, const MyString & s)
{
	return MyString(c) > s;
}

bool operator>(const char * c, const MyString & s)
{
	return MyString(c) > s;
}

bool operator>=(const char c, const MyString & s)
{
	return MyString(c) >= s;
}
bool operator>=(const char* c, const MyString & s)
{
	return MyString(c) >= s;
}

bool operator<(const char c, const MyString & s)
{
	return MyString(c) < s;
}
bool operator<(const char *c, const MyString & s)
{
	return MyString(c) < s;
}

bool operator<=(const char c, const MyString & s)
{
	return MyString(c) < s;
}
bool operator<=(const char *c, const MyString & s)
{
	return MyString(c) < s;
}

istream & operator >> (istream & in, MyString & s) {
	char* c = new char[MAX];
	in.get(c, MAX);
	s = MyString(c);
	delete[] c;
	return in;
}

ostream & operator << (ostream & o, MyString & s) {
	for (int i = 0; i < s.length; i++) {
		o << s[i];
	}
	return o;
}