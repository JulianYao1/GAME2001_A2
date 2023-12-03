#pragma once
#include <cassert>

template <class T> class LinkIterator;
template <class T> class LinkedList;

template <class T>
class LinkNode
{
public:
	friend class LinkIterator<T>;
	friend class LinkedList<T>;
private:
	T m_data;
	LinkNode* m_next;	
	LinkNode* m_previous;
};

template <class T>
class LinkIterator
{
public:
	friend class LinkedList<T>;

	LinkIterator()
	{
		m_node = nullptr;
	}
	~LinkIterator() {}
	
	void operator=(LinkNode<T>* node)
	{
		m_node = node;
	}
	
	{
		assert(m_node != nullptr);
		return m_node->m_data;
	}
	
	void operator++()
	{
		assert(m_node != nullptr);
		m_node = m_node->m_next;
	}
	void operator++(int) 
	{
		assert(m_node != nullptr);
		m_node = m_node->m_next;
	}
	
	void operator--()	
	{
		assert(m_node != nullptr);
		m_node = m_node->m_previous;
	}
	void operator--(int)	
	{
		assert(m_node != nullptr);
		m_node = m_node->m_previous;
	}
	
	bool operator!=(LinkNode<T>* node)
	{
		return (m_node != node);
	}
	bool operator==(LinkNode<T>* node)
	{
		return (m_node == node);
	}
	bool isValid()
	{
		return (m_node != NULL);
	}

private:
	LinkNode<T>* m_node;
};


template <class T>
class LinkedList
{
public:
	LinkedList() : m_size(0), m_root(nullptr), m_lastNode(nullptr) {}
	~LinkedList()
	{
		while (m_root)
		{
			Pop_Back();
		}
	}
	
	LinkNode<T>* Begin()
	{
		assert(m_root != nullptr);
		return m_root;
	}
	LinkNode<T>* End()
	{
		return nullptr;
	}
	LinkNode<T>* Last()
	{
		assert(m_lastNode != nullptr);
		return m_lastNode;
	}
	
	void Insert_Before(LinkIterator<T>& it, T newData)
	{
		assert(it.m_node != nullptr);

		LinkNode<T>* node = new LinkNode<T>;
		assert(node != nullptr);

		node->m_data = newData;
		node->m_next = it.m_node;
		node->m_previous = it.m_node->m_previous;

		if (node->m_previous != nullptr)
		{
			node->m_previous->m_next = node;
		}

		it.m_node->m_previous = node;

		if (it.m_node == m_root)
		{
			m_root = node;
		}

		m_size++;
	}

	void Insert_After(LinkIterator<T>& it, T newData)
	{
		assert(it.m_node != nullptr);

		LinkNode<T>* node = new LinkNode<T>;
		assert(node != nullptr);

		node->m_data = newData;
		node->m_next = it.m_node->m_next;
		node->m_previous = it.m_node;

		if (node->m_next != nullptr)
		{
			node->m_next->m_previous = node;
		}

		it.m_node->m_next = node;

		if (it.m_node == m_lastNode)
		{
			m_lastNode = node;
		}

		m_size++;
	}

	
	void Push_Front(T newData)
	{
		LinkNode<T>* node = new LinkNode<T>;

		assert(node != nullptr);
		node->m_data = newData;
		node->m_next = nullptr;
		node->m_previous = nullptr;

		if (m_root != nullptr)
		{
			node->m_next = m_root;
			m_root->m_previous = node;
			m_root = node;
		}
		else
		{
			m_root = node;
			m_lastNode = node;
		}

		m_size++;
	}
	void Pop_Front()
	{
		assert(m_root != nullptr);

		LinkNode<T>* temp = m_root;

		m_root = m_root->m_next;

		if (m_root != nullptr)
		{
			m_root->m_previous = nullptr;
		}
		else
		{
			m_lastNode = nullptr;
		}

		delete temp;
		temp = nullptr;

		m_size = (m_size == 0 ? m_size : m_size - 1);
	}
	void Push_Back(T newData)
	{
		LinkNode<T>* node = new LinkNode<T>;

		assert(node != nullptr);
		node->m_data = newData;
		node->m_next = nullptr;
		node->m_previous = nullptr;

		if (m_lastNode != nullptr) 
		{
			m_lastNode->m_next = node;
			node->m_previous = m_lastNode;
		}
		else
		{
			m_root = node;
		}

		m_lastNode = node;

		m_size++;
	}
	void Pop_Back()
	{
		assert(m_root != nullptr);

		if (m_root->m_next == nullptr)
		{
			delete m_root;
			m_root = nullptr;
			m_lastNode = nullptr;
		}
		else 
		{
			LinkNode<T>* prevNode = m_lastNode->m_previous;

			prevNode->m_next = nullptr;
			delete m_lastNode;
			m_lastNode = prevNode;
			prevNode = nullptr;
		}

		m_size = (m_size == 0 ? m_size : m_size - 1);
	}
	int GetSize()
	{
		return m_size;
	}
private:
	int m_size;				
	LinkNode<T>* m_root;	
	LinkNode<T>* m_lastNode;
};
