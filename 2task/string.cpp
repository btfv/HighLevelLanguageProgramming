#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <assert.h>
#include "string.h"

string::string() {
	this->str = new char[1];
	this->str[0] = '\0';
};

string::string(char* val) {
	if (val == nullptr) {
		str = new char[1];
		str[0] = '\0';
	}
	else {
		str = new char[sizeof val];
		strcpy(str, val);
	}
};

string::string(const string& source)
{
	this->str = new char[sizeof source.str];
	strcpy(this->str, source.str);
}

string::~string() {};

string& string::operator=(char* value) {
	delete[] this->str;
	this->str = new char[sizeof value];
	strcpy(this->str, value);
	return *this;
}

char string::operator[](int index) {
	assert(index >= 0 && index < get_length());
	return this->str[index];
}

std::ostream& operator<< (std::ostream& stream, string string) {
	return string.out(stream);
}
std::istream& operator>> (std::istream& stream, string string) {
	return string.in(stream);
}

int string::get_length() {
	return strlen(this->str);
}

void string::reverse_string(char* str) {
	int i = 0;
	int j = static_cast<int>(strlen(str)) - 1;
	char x;
	while (j - i > 0) {
		x = str[i];
		str[i] = str[j];
		str[j] = x;
		i++;
		j--;
	}
}