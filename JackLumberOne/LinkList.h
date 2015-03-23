#include "LinkNode.h"
template <typename T>
class LinkList
{
public:
	LinkList() :m_size(0), m_root(0), m_lastNode(0)
	{

	}
	~LinkList()
	{
		while (m_root != NULL)
		{
			Pop();
		}
	}
	LinkNode<T> *Begin()
	{
		return m_root;
	}
	LinkNode<T> *End()
	{
		return NULL;
	}

	void Push(T newData)
	{
		LinkNode<T> *node = new LinkNode < T > ;

		node->m_data = newData;
		node->m_next = NULL;
		if (m_lastNode != NULL)
		{
			m_lastNode->m_next = node;
			m_lastNode = node;
		}
		else
		{
			m_root = node;
			m_lastNode = node;
		}
		m_size++;
	}
	void Pop()
	{
		if (m_root->m_next == NULL)
		{
			delete m_root;
			m_root = NULL;
		}
		else
		{
			LinkNode<T> *prevNode = m_root;

			while (prevNode->m_next != NULL && prevNode->m_next != m_lastNode)
			{
				prevNode = prevNode->m_next;
			}
			delete m_lastNode;
			prevNode->m_next = NULL;
			m_lastNode = prevNode;
		}
		m_size = (m_size == 0 ? m_size : m_size - 1);
	}
	void PushFront(T newData)
	{
		LinkNode<T> *node = new LinkNode < T > ;

		node->m_data = newData;
		node->m_next = NULL;
		
		if (m_root != NULL)
		{
			node->m_next = m_root;
			m_root = node;
		}
		else
		{
			m_root = node;
			m_lastNode = node;
		}
		m_size++;
	}
	void PopFront()
	{
		LinkNode<T> *temp = m_root;

		m_root = m_root->m_next;
		delete temp;
		m_size = (m_size == 0 ? m_size : m_size - 1);
	}
	int GetSize()
	{
		return m_size;
	}
private:
	int m_size;
	LinkNode<T> *m_root;
	LinkNode<T> *m_lastNode;
};