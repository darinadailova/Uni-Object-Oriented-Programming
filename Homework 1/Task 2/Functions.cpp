#include "Functions.hpp"

int strLength(const char* str) {
	if (str == nullptr) return 0;

	int count = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		count++;
	}

	return count;
}

void strCopy(char* str1, const char* str2) {
	int i = 0;
	for (; str2[i] != '\0'; i++) {
		str1[i] = str2[i];
	}
	i++;
	str1[i] = '\0';
}
