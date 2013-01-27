// CPPTasks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "strings.h"


int _tmain(int argc, _TCHAR* argv[])
{
	char* c = String("123");
	Reverse(c);
	MemFlush(c);
	return 0;
}

