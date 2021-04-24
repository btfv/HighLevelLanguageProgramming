#pragma once

#include <iostream>
#include "string.h"

class id_string : public string {
public:
	id_string() : string() {};
	id_string(const char*);
	~id_string();
	void to_upper_case();
	static bool check_string(const char	*);
	virtual id_string& operator=(const char*);
	friend id_string operator+(const id_string&, const id_string&);
};
