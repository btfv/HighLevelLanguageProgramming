#define _CRT_SECURE_NO_WARNINGS

#include "decimal_string.h"

decimal_string::decimal_string(const char* string) {
	int i = 0;
	while (string[i] != '\0') {
		if (string[i] != '-' && string[i] != '+' && (string[i] < '0' || string[i] > '9')) {
			this->str = new char[1];
			this->str[0] = '\0';
			return;
		}
		i++;
	}
	this->str = new char[sizeof string];
	strcpy(this->str, string);
}