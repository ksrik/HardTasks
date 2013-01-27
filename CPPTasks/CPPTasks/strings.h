#pragma once

#include "stdafx.h"

const int CHARSET_SIZE = 256;

char* String(const char* source);

/*
Implement an algorithm to determine if a string has all unique characters. 
What if you can not use additional data structures?
*/
bool IsAllUnique(const char* str);

/*
1.2 Write code to reverse a C-Style String. 
(C-String means that �abcd� is represented as five characters, including the null character.)
*/
void Reverse(char* str);

/*
Design an algorithm and write code to remove the duplicate characters in a 
string without using any additional buffer. NOTE: One or two additional variables are fine. 
An extra copy of the array is not.
FOLLOW UP
Write the test cases for this method.
*/
void RemoveDuplicates(char* str);

/*
Design an algorithm and write code to remove the duplicate characters in a 
string without using any additional buffer. NOTE: One or two additional variables are fine. 
An extra copy of the array is not.
FOLLOW UP
Write the test cases for this method.

With Additional Memory of Constant Size
*/
void RemoveDuplicates_M(char* str);

/*
Write a method to decide if two strings are anagrams or not.
*/
bool IsAnagrams(const char* str1, const char* str2);

