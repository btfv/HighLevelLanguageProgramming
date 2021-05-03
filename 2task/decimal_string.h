#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "string.h"

class decimal_string: public string {
protected:
	virtual std::istream& in(std::istream& is)
	{
		char* t = new char[100];
		is >> t;
		if (!check_string(t)) {
			return is;
		}
		beautify_string(t);
		resize_string(strlen(t) + 1);
		strcpy(str, t);
		return is;
	}
public:
	decimal_string() {};
	decimal_string(const char*);
	bool get_sign();
	friend decimal_string operator+(const decimal_string& left, const decimal_string& right);
	static bool check_string(const char*);
	~decimal_string() { };
	static void beautify_string(char*);
};
