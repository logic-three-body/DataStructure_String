#define _CRT_SECURE_NO_WARNINGS //put in first line;
// strngbad. cpp -- String class methods
#include <cstring>
// string.h for some
#include "string1.h"
using std::cout;
// initializing static class member
int String::num_strings = 0;
// class methods
// construct String from C string
String::String()
{
	len = 0;
	str = new char[1];
	//str[0] = '\0';	//default string
	str = nullptr;//C++ null pointer
	//str = NULL;//C marco null pointer
	//str = 0;//vague null pointer
	//str = (void*)0;
	++num_strings;
}

String::String(const char * s)
{
	len = std::strlen(s);
	// set size
	str = new char[len + 1];
	// allot storage

	/*   instruction:As strlen() couldn't include the '\0' in the return num
		So it's necessary to add one to the len as to allot proper storage*/

	std::strcpy(str, s);
	// initialize pointer
	num_strings++;
	// set object count
	cout << num_strings << ": \"" << str
		<< "\" object created\n";
	// For Your Information
}

/*
String::String()
// default constructor
{
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++");
	// default string
	num_strings++;
	cout << num_strings << "; \"" << str
		<< "\" default object created\n"; // FYI
}
*/


String ::~String()
// necessary destructor
{
	
	
	--num_strings;
	// required
	
	delete[] str;
	// required
}

int * String::compute_prefix_function(const char * pattern)
{
	int m = strlen(pattern);
	int *next = new int[m];
	next[0] = 0;
	int k = 0;
	int q;

	for (q = 1; q < m; q++)
	{
		while (k > 0 && (pattern[k] != pattern[q]))
			k = next[k - 1];
		if (pattern[k] == pattern[q])
			k++;
		next[q] = k;
	}
	return next;
}

int * String::compute_prefix_function(const String &pattern)
{
	int m = pattern.length();
	int *next = new int[m];
	next[0] = 0;
	int k = 0;
	int q;

	for (q = 1; q < m; q++)
	{
		while (k > 0 && (pattern[k] != pattern[q]))
			k = next[k - 1];
		if (pattern[k] == pattern[q])
			k++;
		next[q] = k;
	}
	return next;
}

int String::KMP_match(const char *pattern)
{
	int n = len;
	int m = strlen(pattern);
	int *next = compute_prefix_function(pattern);
	int q = 0;
	int i;

	for (i = 0; i < n; i++)
	{
		while (q > 0 && (pattern[q] != str[i]))
			q = next[q - 1];
		if (pattern[q] == str[i])
			q++;
		if (q == m)
			return i + 1 - m;
	}
	delete[] next;
	return -1;
}

int String::KMP_match(const String &pattern)
{
	int n = len;
	int m = pattern.len;
	int *next = compute_prefix_function(pattern);
	int q = 0;
	int i;

	for (i = 0; i < n; i++)
	{
		while (q > 0 && (pattern[q] != str[i]))
			q = next[q - 1];
		if (pattern[q] == str[i])
			q++;
		if (q == m)
			return i + 1 - m;
	}
	delete[] next;
	return -1;
}

String & String::operator=(const String &st)//deep copy
{
	// TODO: 在此处插入 return 语句
	if (this == &st) //judge object assigned to itself
		return *this;//all done
	delete[]str;//free old string
	len = st.len;
	str = new char[len + 1];//get space for new string
	std::strcpy(str, st.str);//copy
	return *this;//return reference to invoking object
}

String::String(const String &st)//deep copy
{
	++num_strings;//handle static num update
	len = st.len;//same length
	str = new char[len + 1];//allot space
	std::strcpy(str, st.str);//copy string to new location
	cout << num_strings << ":\"" << str << "\"object created\n";//For information

}

 int String::length() const
{
	return len;
}

char & String::operator[](int i)
{
	// TODO: 在此处插入 return 语句
	return str[i];
}

//for use with const String objects
const char&String::operator[](int i)const
{
	return str[i];
}

String & String::operator=(const char *s)
{
	// TODO: 在此处插入 return 语句
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
	++num_strings;
}

int String::HowMany()
{
	return num_strings;
}

std::ostream & operator<<(std::ostream & os, const String & st)
{
	os << st.str;
	return os;
}

std::istream & operator>>(std::istream & is, String & st)
{
	// TODO: 在此处插入 return 语句
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is&&is.get() != '\n')
		continue;
	return is;
}

bool operator<(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
	//return (operator<(st2,st1));
	return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str,st2.str)==0);
}


