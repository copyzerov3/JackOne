#include "Array.h"

template <class T>

class OrderedArray:public Array<T>
{
public:
	OrderedArray(int size, int growBy = 1) :Array(size, growBy)
	{

	}
	~OrderedArray()
	{

	}
	void push(T val)
	{
		int i = 0;
		if (m_numElements >= m_maxSize)
		{
			Expand();
		}

		for (i = 0; i < m_numElements; i++)
		{
			if (m_array[i] > val)
				break;
		}
		for (int k = m_numElements; k > i; k--)
		{
			m_array[k] = m_array[k - 1];
		}
		m_array[i] = val;
		m_numElements++;
	}
	int search(T searchKey)
	{
		int lowerBound = 0;
		int upperBound = m_numElements - 1;
		int current = 0;

		while (1)
		{
			current = (lowerBound + upperBound) >> 1;

			if (m_array[current] == searchKey)
			{
				return current;
			}
			else if (lowerBound > upperBound)
			{
				return -1;
			}
			else
			{
				if (m_array[current] < searchKey)
				{
					lowerBound = current + 1;
				}
				else
					upperBound = current - 1;
			}
		}
		return -1;
	}
};