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

	bool* chars = MemAlloc<bool>(CHARSET_SIZE);
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
	MemFlush<bool>(chars);
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

	MemFlush<bool>(hit);
}

bool IsAnagrams(const char* s1, const char* s2)
{
	int l1 = strlen(s1);
	int l2 = strlen(s2);

	if (l1 != l2)
		return false;

	int* letters = MemAlloc<int>(CHARSET_SIZE);

	int numUniqueChars = 0;
	int numCompletedT = 0;

	for (int i=0;i<l1;i++)
	{
		char c = s1[i];
		if (letters[c] == 0)
		{
			numUniqueChars++;
		}
		letters[c]++;
	}
	bool res = true;
	for (int i=0;i<l2;i++)
	{
		char c = s2[i];
		if (letters[c] == 0) 
		{
			res = false;
			break;
		}
		letters[c]--;		
	}

	MemFlush<int>(letters);
	return res;
}
