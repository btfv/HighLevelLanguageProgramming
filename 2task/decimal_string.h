#pragma once

#include <iostream>
#include "string.h"

class decimal_string: public string {
public:
	decimal_string() : string() {};
	decimal_string(const char*);
	virtual ~decimal_string() { };
};
