#include "stdafx.h"

char* String(const char* source)
{
	int sz = strlen(source) + 1;
	char* buf = MemCopy<char>(sz, source);
	return buf;
}

bool IsAllUnique(const char* str)
{
	if (!str)
		return true;

	bool *chars = MemAlloc<bool>(CHARSET_SIZE);
	char *pc = const_cast<char*>(str);
	bool res = true;
	while (*pc) 
	{
		char c = *pc;		
		if (chars[c]) 
		{
			res = false;
			break;
		}
		chars[c] = true;
		pc++;
	}	
	MemFlush(chars);
	return res;
}

void Reverse(char* str)
{
	if (!str)
		return;

	char* end = str;
	char tmp;
	while (*end)
	{
		end++;
	}
	end--;
	while (str < end)
	{
		tmp = *str;
		*str++ = *end;
		*end-- = tmp;
	}
}

void RemoveDuplicates(char* str)
{
	if (!str)
		return;

	int len = strlen(str);
	if (len < 2)
		return;

	int tail = 1;

	for (int i = 1; i<len; i++)
	{
		int j;
		for (j = 0; j<tail; j++)
		{
			if (str[i] == str[j])
				break;
		}
		if (j == tail)
			str[tail] = str[i];
		tail++;
	}
	str[tail] = 0;
}

void RemoveDuplicates_M(char* str)
{
		if (!str)
		return;

	int len = strlen(str);
	if (len < 2)
		return;

	bool* hit = MemAlloc<bool>(CHARSET_SIZE);

	hit[str[0]] = true;
	int tail = 1;
	for (int i = 1; i < len; i++)
	{
		if (!hit[str[i]])
		{
			str[tail] = str[i];
			tail++;
			hit[str[i]] = true;
		}
	}

	delete[] hit;
}

bool IsAnagrams(const char* s1, const char* s2)
{
	int l1 = strlen(s1);
	int l2 = strlen(s2);

	if (l1 != l2)
		return false;

	int numUniqueChars = 0;
	int numCompletedT = 0;

	return false;
}

/*
public static boolean anagram(String s, String t) {
2 if (s.length() != t.length()) return false;
3 int[] letters = new int[256];
4 int num_unique_chars = 0;
5 int num_completed_t = 0;
6 char[] s_array = s.toCharArray();
7 for (char c : s_array) { // count number of each char in s.
8 if (letters[c] == 0) ++num_unique_chars;
9 ++letters[c];
10 }
11 for (int i = 0; i < t.length(); ++i) {
12 int c = (int) t.charAt(i);
13 if (letters[c] == 0) { // Found more of char c in t than in s.
14 return false;
15 }
16 --letters[c];
17 if (letters[c] == 0) {
18 ++num_completed_t;
19 if (num_completed_t == num_unique_chars) {
20 // it’s a match if t has been processed completely
21 return i == t.length() - 1;
22 }
23 }
24 }
25 return false;
26 }
*/
