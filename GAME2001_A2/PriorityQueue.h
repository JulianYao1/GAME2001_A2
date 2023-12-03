#pragma once

#include "LinkedList.h"

template<class T, class CMP>
class PriorityQueue
{
public:
	PriorityQueue(int size)
	{
		assert(size > 0);
		m_size = size;
	}
	~PriorityQueue() {}

	void push(T val)
	{
		assert(m_elements.GetSize() < m_size);

		if (m_elements.GetSize() == 0)
		{
			m_elements.Push_Back(val);
		}
		else
		{
			LinkIterator<T> it;
			it = m_elements.Begin();

			CMP cmp;	

			while (it.isValid())
			{
				if (cmp(val, *it))
				{
					break;	
				}

				it++;
			}

			if (it.isValid())
			{
				m_elements.Insert_Before(it, val);
			}
			else
			{
				m_elements.Push_Back(val);
			}
		}
	}

	void pop()
	{
		m_elements.Pop_Front();
	}

	T& front()
	{
		LinkIterator<T> it;
		it = m_elements.Begin();

		return *it;
	}
	T& back()
	{
		LinkIterator<T> it;
		it = m_elements.Last();

		return *it;
	}

	int GetSize()
	{
		return m_elements.GetSize();
	}

	int GetMaxSize()
	{
		return m_size;
	}

	bool isEmpty()
	{
		return (m_elements.GetSize() == 0);
	}

	void Resize(int size)
	{
		assert(size > 0);
		m_size = size;
	}

private:
	LinkedList<T> m_elements;
	int m_size;
};

template<class T>
class less_cmp
{
public:
	inline bool operator()(T lVal, T rVal)
	{
		return lVal < rVal;
	}
};

template<class T>
class greater_cmp
{
public:
	inline bool operator()(T lVal, T rVal)
	{
		return !(lVal < rVal);
	}
};

template <class T>
class PriorityQueueData
{
public:
	PriorityQueueData() : m_priority(0), m_data() {}
	PriorityQueueData(int p, T data) : m_priority(p), m_data(data) {}
	~PriorityQueueData() {}

	int GetPriority()
	{
		return m_priority;
	}
	T GetData()
	{
		return m_data;
	}

	bool operator<(PriorityQueueData& m)
	{
		if (m_priority < m.GetPriority())
		{
			return true;
		}

		return false;
	}
	bool operator>(PriorityQueueData& m)
	{
		return !(*this < m);
	}
private:
	int m_priority;
	T m_data;
};