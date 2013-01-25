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
