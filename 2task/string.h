#pragma once
#include <iostream>

class string {
protected:
	char* str;

	virtual std::ostream& out(std::ostream& os)
	{
		return os << str;
	}
	virtual std::istream& in(std::istream& is)
	{
		return is >> str;
	}
public:
	string();
	virtual ~string();
	string(char* val);
	string(const string& source);
	int get_length();
	virtual string& operator=(char*);
	char operator[](int);
	friend std::ostream& operator<< (std::ostream&, string&);
	friend std::istream& operator>> (std::istream&, string&);
	void resize_string(const int new_size) {
		delete[] this->str;
		this->str = new char[new_size];
	}
};