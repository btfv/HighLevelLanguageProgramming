#pragma once
#include <iostream>

class string {
protected:
	char* str;

	virtual std::ostream& out(std::ostream&);
	virtual std::istream& in(std::istream&);
public:
	string();
	virtual ~string();
	string(char* val);
	string(const string& source);
	int get_length();
	virtual string& operator=(char*);
	char operator[](int);
	friend std::ostream& operator<< (std::ostream&, string);
	friend std::istream& operator>> (std::istream&, string);
	void resize_string(const int);
	static void reverse_string(char*);
};