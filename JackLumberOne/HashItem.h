template<typename T>

class HashItem
{
public:
	HashItem() :m_key(-1){}
	~HashItem(){}

	int GetKey(){ return m_key; }
	void SetKey(int k){ m_key = k; }

	T& GetObject(){ return m_obj; }
	void SetObject(const T &obj){ m_obj = obj; }

	bool operator ==(HashItem &item)
	{
		if (m_key == item.GetKey())
		{
			return true;
		}
		return false;
	}

	void operator=(HashItem item)
	{
		m_key = item.GetKey();
		m_obj = item.GetObject();
	}
private:
	int m_key;
	T m_obj;
};