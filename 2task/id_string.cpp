#define _CRT_SECURE_NO_WARNINGS

#include "id_string.h"

id_string::id_string(const char* val) {
	if (!check_string(val)) {
		string::string();
		return;
	}
	str = new char[sizeof val];
	strcpy(str, val);
}
bool id_string::check_string(const char* value) {
	int i = 0;
	while (value[i] != '\0') {
		if (value[i] == '_' || (value[i] >= 97 && value[i] <= 122) || (value[i] >= 65 && value[i] <= 90)) {
			i++;
			continue;
		}
		return false;
	}
	return true;
}
id_string& id_string::operator=(const char* value) {
	if (!check_string(value)) {
		return *this;
	}
	delete[] this->str;
	this->str = new char[sizeof value];
	strcpy(this->str, value);
	return *this;
}
id_string operator+(const id_string& left, const id_string& right) {
	char* new_string = new char[strlen(left.str) + strlen(right.str) + 1];
	strcpy(new_string, left.str);
	strcat(new_string, right.str);
	return id_string(new_string);
}
void id_string::to_upper_case() {
	int i = 0;
	while (this->str[i] != '\0') {
		if (this->str[i] >= 65 && this->str[i] <= 90) {
			this->str[i] -= 32;
		}
		i++;
	}
}
id_string::~id_string() {
	delete[] this->str;
}