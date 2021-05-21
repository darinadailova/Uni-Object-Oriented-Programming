/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Darina Dailova
* @idnumber 62583
* @task 2
* @compiler VC
*/

#include "Functions.hpp"

int strlength(const char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        count++;
    }

    return count;
}

void stringcpy(char str1[], const char str2[]) {
    int size2 = strlength(str2);
    int i = 0;
    for (; i < size2; i++) {
        str1[i] = str2[i];
    }

    str1[i++] = '\0';
}