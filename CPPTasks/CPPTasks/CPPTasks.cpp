// CPPTasks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "strings.h"


int _tmain(int argc, _TCHAR* argv[])
{
	char *c = new char[4];
	strcpy_s("123",c);
	Reverse(c);
	delete[] c;
	return 0;
}

