template<typename T>

class LinkIterator
{
public :
	LinkIterator()
	{
		m_node = NULL;
	}
	~LinkIterator()
	{

	}

	void operator = (LinkNode<T> *node)
	{
		m_node = node;
	}

	T &operator*()
	{
		return m_node->m_data;
	}

	void operator++()
	{
		m_node = m_node->m_next;
	}
	void operator++(int)
	{
		m_node = m_node->m_next;
	}
	bool operator !=(LinkNode<T> *node)
	{
		return (m_node != node);
	}
	bool operator == (LinkNode<T> *node)
	{
		return (m_node == node);
	}

private:
	LinkNode<T> *m_node;
};