#pragma once
template <class T>

class Array
{
public:
	Array(int size, int growBy = 1) : m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}
	~Array()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;
		}
	}
	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--;
		}
	}
	void remove(int index)
	{
		if (index >= m_maxSize)
		{
			return;
		}
		if (std::is_pointer(m_array[index]))
			delete m_array[index];
		for (int k = index; k < m_maxSize - 1; k++)
			m_array[k] = m_array[k + 1];

		m_maxSize--;

		if (m_numElements >= m_maxSize)
			m_numElements = m_maxSize - 1;
	}
	void clear()
	{
		m_numElements = 0;
	}
	int GetSize() { return m_numElements; }
	int GetMaxSize() { return m_maxSize; }
	int GetGrowSize() { return m_growSize; }
	virtual T& operator[](int index)
	{
		return m_array[index];
	}
	virtual void push(T val)
	{
		if (m_numElements >= m_maxSize)
		{
			Expand();
		}
		m_array[m_numElements] = val;
		m_numElements++;
	}
	virtual int search(T val)
	{
		for (int i = 0; i < m_numElements; i++)
		{
			if (m_array[i] == val)
				return i;
		}

		return -1;
	}
protected:
	bool Expand()
	{
		if (m_growSize <= 0)
			return false;

		T *temp = new T[m_maxSize + m_growSize];

		memcpy(temp, m_array, sizeof(T)* m_maxSize);

		delete[] m_array;
		m_array = temp;

		m_maxSize += m_growSize;

		return true;
	}

	T *m_array;

	int m_maxSize;
	int m_growSize;
	int m_numElements;
};