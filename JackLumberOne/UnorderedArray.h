#pragma once
#include"Array.h"
template <class T>

class UnorderedArray : public Array<T>
{
public:
	UnorderedArray(int size, int growBy = 1) :Array(size, growBy)
	{}
	~UnorderedArray()
	{
		
	}
};

