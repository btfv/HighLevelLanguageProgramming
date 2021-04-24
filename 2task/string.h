#pragma once
#include <iostream>

class string {
protected:
	char* str;
public:
	string();
	virtual ~string();
	string(char* val);
	string(const string& source);
	int get_length();
	virtual string& operator=(char*);
	char operator[](int);
	friend std::ostream& operator<< (std::ostream&, const string&);
};