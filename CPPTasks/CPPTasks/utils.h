#pragma once

#include "stdafx.h"

const int PTR_SIZE = sizeof(void*);
const int CHAR_SIZE = sizeof(char);
const int BOOL_SIZE = sizeof(bool);
const int INT_SIZE = sizeof(int);

template<typename T> T* MemCopy(int size, const T* source)
{
	if (!source || size <= 0)
	{
		return NULL;
	}

	T* buf = new T[size];
	memcpy(buf, source, sizeof(T)*size);

	return buf;
}

template<typename T> void MemFlush(T*& buf);
template<typename T> T* MemAlloc(int size, T* buf = NULL, bool clean = true, bool flush = false)
{
	if (buf && !flush)
	{		
		if (!clean) 
		{
			return buf;
		}
		else
		{
			memset(buf, NULL, sizeof(T) * size);
			return buf;
		}
	}

	if (size <= 0)
	{
		return NULL;
	}

	if (buf)
	{
		MemFlush(buf);
	}
	
	buf = new T[size];
	if (clean)
	{
		memset(buf, NULL, sizeof(T) * size);
	}

	return buf;
}

template<typename T> void MemFlush(T*& buf)
{
	if (buf)
		delete[] buf;
	buf = NULL;
}
