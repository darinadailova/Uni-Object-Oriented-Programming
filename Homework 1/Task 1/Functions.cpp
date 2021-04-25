#include "Functions.hpp"

int strlength(const char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        count++;
    }

    return count;
}

bool stringcmp(const char* str1, const char* str2) {
    if (strlength(str1) != strlength(str2)) return false;

    int size = strlength(str1);
    for (int i = 0; i < size; i++) {
        if (str1[i] != str2[i]) return false; 
    }
   
    return true;
}
