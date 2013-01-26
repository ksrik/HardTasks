#include "stdafx.h"

const int CHARSET_SIZE = 256;
const int PTR_SIZE = sizeof(void*);
const int CHAR_SIZE = sizeof(char);

bool IsAllUnique(const char* str)
{
	if (!str)
		return true;

	bool *chars = new bool[CHARSET_SIZE];
	memset(chars, 0, CHAR_SIZE * CHARSET_SIZE);
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
	delete[] chars;
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
		++end;
	}
	--end;
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

/*
public static void removeDuplicates(char[] str) {
2 if (str == null) return;
3 int len = str.length;
4 if (len < 2) return;
5
6 int tail = 1;
7
8 for (int i = 1; i < len; ++i) {
9 int j;
10 for (j = 0; j < tail; ++j) {
11 if (str[i] == str[j]) break;
12 }
13 if (j == tail) {
14 str[tail] = str[i];
15 ++tail;
16 }
17 }
18 str[tail] = 0;
19 }
*/
