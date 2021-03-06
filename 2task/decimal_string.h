#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "string.h"

class decimal_string: public string {
protected:
	virtual std::istream& in(std::istream&);
public:
	decimal_string() {};
	decimal_string(const char*);
	bool get_sign();
	decimal_string operator+(const char*);
	friend decimal_string operator+(const decimal_string&, const decimal_string&);
	static bool check_string(const char*);
	~decimal_string();
	static void beautify_string(char*);
};
