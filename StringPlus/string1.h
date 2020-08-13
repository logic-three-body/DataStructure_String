#pragma once
//-strngbad.h -- flawed -string class definition
#include <iostream>
#ifndef STRING1_H_
#define STRING1_H_
class String
{
private:
	char * str;
	// pointer to string
	int len;
	//: length - of string
	static int num_strings;//all the object would share just one this static member
	static const int CINLIM = 80;//cin put limit
//.number of objects.
public:
	String(const char *s); // constructor
	String();
	// default constructor
	~String();
	// destructor.


	int length() const;

	char &operator[](int i);
	const char & operator[](int i) const;

	String&operator=(const String &);//copy function
	String(const String&);//copy function
	String & operator=(const char*);

	   // friend function
	friend std::ostream & operator<<(std::ostream & os,
		const  String & st);
	friend std::istream&operator>>(std::istream&is, String&st);
	//friend String &operator=(String st1,const String& st2);
	friend bool operator<(const String&,const String&);
	friend bool operator>(const String&, const String&);
	friend bool operator==(const String&, const String&);

	//static function
	static int HowMany();
};
#endif
