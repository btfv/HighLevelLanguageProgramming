#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "string.h"

class id_string : public string {
protected:
	virtual std::istream& in(std::istream&);
public:
	id_string() {};
	id_string(const char*);
	~id_string();
	void to_upper_case();
	static bool check_string(const char	*);
	id_string& operator=(const char*);
	friend id_string operator+(const id_string&, const id_string&);
};
