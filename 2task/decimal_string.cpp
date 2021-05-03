#define _CRT_SECURE_NO_WARNINGS

#include "decimal_string.h"
#include <algorithm>
decimal_string::decimal_string(const char* string) {
	if (!check_string(string)) {
		this->str = new char[1];
		this->str[0] = '\0';
		return;
	}
	char* t = new char[sizeof string];
	strcpy(t, string);
	beautify_string(t);
	resize_string(strlen(t) + 1);
	strcpy(this->str, t);
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

int max(int x, int y) {
	return x >= y ? x : y;
}

decimal_string operator+(const decimal_string& left, const decimal_string& right) {
	int x = left.str[0] == '-' || left.str[0] == '+';
	char* left_str = new char[strlen(left.str) - x + 1];
	for (int i = x; i <= strlen(left.str); i++) {
		left_str[i - x] = left.str[i];
	}
	decimal_string::reverse_string(left_str);
	
	x = right.str[0] == '+' || right.str[0] == '-';
	char* right_str = new char[strlen(right.str) - x + 1];
	for (int i = x; i <= strlen(right.str); i++) {
		right_str[i - x] = right.str[i];
	}
	decimal_string::reverse_string(right_str);

	char* new_str = new char[strlen(right_str) + strlen(left_str) + 2];

	char l;
	if (left.str[0] == '-' || left.str[0] == '+') {
		l = left.str[0];
	}
	else {
		l = '+';
	}
	char r;
	if (right.str[0] == '-' || right.str[0] == '+') {
		r = right.str[0];
	}
	else {
		r = '+';
	}
	
	int i = 0;
	if (l == '+' && r == '+') {
		bool rem = 0;
		int curr = 0;
		i = 0;
		while (i < strlen(left_str) || i < strlen(right_str)) {
			int left = i < strlen(left_str) ? left_str[i] - '0' : 0;
			int right = i < strlen(right_str) ? right_str[i] - '0' : 0;

			curr = left + right + rem;
			rem = 0;
			new_str[i] = curr % 10 + '0';
			rem = curr >= 10;
			i++;
		}
		if (rem) {
			new_str[i] = rem + '0';
			i++;
		}
	}
	else if (l == '+' && r == '-') {
		bool rem = 0;
		int curr = 0;
		i = 0;
		while (i < strlen(left_str) || i < strlen(right_str)) {
			int left = i < strlen(left_str) ? left_str[i] - '0' : 0;
			int right = i < strlen(right_str) ? right_str[i] - '0' : 0;
			curr = left - right - rem;
			rem = 0;
			if (curr < 0) {
				curr += 10;
				rem++;
			}
			new_str[i] = curr + '0';
			i++;
		}
		if (rem) {
			rem = 0;
			curr = 0;
			i = 0;
			while (i < strlen(left_str) || i < strlen(right_str)) {
				int left = i < strlen(left_str) ? left_str[i] - '0' : 0;
				int right = i < strlen(right_str) ? right_str[i] - '0' : 0;
				curr = right - left - rem;
				rem = 0;
				if (curr < 0) {
					curr += 10;
					rem++;
				}
				new_str[i] = curr + '0';
				i++;
			}
			new_str[i] = '-';
			i++;
		}
	}
	else if (l == '-' && r == '+') {
		bool rem = 0;
		int curr = 0;
		i = 0;
		while (i < strlen(left_str) || i < strlen(right_str)) {
			int left = i < strlen(left_str) ? left_str[i] - '0' : 0;
			int right = i < strlen(right_str) ? right_str[i] - '0' : 0;
			curr = right - left - rem;
			rem = 0;
			if (curr < 0) {
				curr += 10;
				rem++;
			}
			if (curr == 0 && (i + 1 == max(strlen(left_str), strlen(right_str)))) {
				break;
			}
			new_str[i] = curr + '0';
			i++;
		}
		if (rem) {
			rem = 0;
			curr = 0;
			i = 0;
			while (i < strlen(left_str) || i < strlen(right_str)) {
				int left = i < strlen(left_str) ? left_str[i] - '0' : 0;
				int right = i < strlen(right_str) ? right_str[i] - '0' : 0;
				curr = left - right - rem;
				rem = 0;
				if (curr < 0) {
					curr += 10;
					rem++;
				}
				if (curr == 0 && (i + 1 == max(strlen(left_str), strlen(right_str)))) {
					break;
				}
				new_str[i] = curr + '0';
				i++;
			}
			new_str[i] = '-';
			i++;
		}
	}
	else if (l == '-' && r == '-') {
		bool rem = 0;
		int curr = 0;
		i = 0;
		while (i < strlen(left_str) || i < strlen(right_str)) {
			int left = i < strlen(left_str) ? left_str[i] - '0' : 0;
			int right = i < strlen(right_str) ? right_str[i] - '0' : 0;

			curr = left + right + rem;
			rem = 0;
			new_str[i] = curr % 10 + '0';
			rem = curr >= 10;
			i++;
		}
		if (rem) {
			new_str[i] = rem + '0';
			i++;
		}
		new_str[i] = '-';
		i++;
	}
	new_str[i] = '\0';
	delete[] right_str;
	delete[] left_str;
	decimal_string::reverse_string(new_str);
	return decimal_string(new_str);
}

void decimal_string::beautify_string(char* str) {
	int shift = 0;
	int i = 0;
	int length = strlen(str);

	if (str[0] == '-' || str[0] == '+') {
		i = 1;
		while (str[i] != '\0' && str[i] == '0') {
			i++;
		}
		shift = i - 1;
		if (shift == length) {
			shift--;
		}

		if (shift == 0) {
			return;
		}
		i = 1;
		while (str[i + shift] != '\0') {
			str[i] = str[i + shift];
			i++;
		}
		str[i] = str[i + shift];
	}
	else {
		i = 0;
		while (str[i] != '\0' && str[i] == '0') {
			i++;
		}
		shift = i;
		if (shift == length) {
			shift--;
		}

		if (shift == 0) {
			return;
		}
		i = 0;
		while (str[i + shift] != '\0') {
			str[i] = str[i + shift];
			i++;
		}
		str[i] = str[i + shift];
	}
}

std::istream& decimal_string::in(std::istream& is)
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

decimal_string decimal_string::operator+(const char* str) {
	decimal_string right(str);
	return *this + right;
}
decimal_string::~decimal_string() {
	delete[] this->str;
}