#define _CRT_SECURE_NO_WARNINGS

#include "decimal_string.h"

decimal_string::decimal_string(const char* string) {
	if (!check_string(string)) {
		this->str = new char[1];
		this->str[0] = '\0';
		return;
	}
	this->str = new char[sizeof string];
	strcpy(this->str, string);
}

bool decimal_string::get_sign() {
	if (str[0] == '-') {
		return false;
	}
	return true;
}
bool decimal_string::check_string(const char* string) {
	int i = 0;
	if (string[i] != '-' && string[i] != '+' && (string[i] < '0' || string[i] > '9')) {
		return false;
	}
	i++;
	while (string[i] != '\0') {
		if (string[i] < '0' || string[i] > '9') {
			return false;
		}
		i++;
	}
	return true;
}

decimal_string operator+(const decimal_string& left, const decimal_string& right) {
	/* Тут длинная арифметика, которую я писать не буду. Извините. */
	return left;
}