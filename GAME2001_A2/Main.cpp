// Julian Yao, 101419348
#include <iostream>
#include "PriorityQueue.h"
using namespace std;

template<class T>
class less_cmp 
{
public:
	inline bool operator()(T lVal, T rVal)
	{
		return lVal < rVal;
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

int main()
{
	cout << "Priority queue data structure example!" << endl << endl;

	const int SIZE = 5;
	PriorityQueue<PriorityQueueData<string>, less_cmp<PriorityQueueData<string>>> stringQue(SIZE);
	PriorityQueue<PriorityQueueData<int>, less_cmp<PriorityQueueData<int>>> intQue(SIZE);

	stringQue.push(PriorityQueueData<string>(5, "String1"));
	stringQue.push(PriorityQueueData<string>(1, "String2"));
	stringQue.push(PriorityQueueData<string>(3, "String3"));
	stringQue.push(PriorityQueueData<string>(2, "String4"));
	stringQue.push(PriorityQueueData<string>(4, "String5"));

	intQue.push(PriorityQueueData<int>(5, 1));
	intQue.push(PriorityQueueData<int>(1, 2));
	intQue.push(PriorityQueueData<int>(3, 3));
	intQue.push(PriorityQueueData<int>(2, 4));
	intQue.push(PriorityQueueData<int>(4, 5));

	// Display the priority queue
	cout << "Priority queue content (Size - " << stringQue.GetSize() << ") : " << endl;

	while (stringQue.isEmpty() == false)
	{
		cout << "  Priority: " << stringQue.front().GetPriority();
		cout << "  ID: " << stringQue.front().GetData();
		cout << endl;

		stringQue.pop();
	}
	cout << endl;
	if (stringQue.isEmpty() == true)
	{
		cout << "The container is empty." << endl;
	}
	else
	{
		cout << "The container is NOT empty." << endl;
	}

	// Display the priority queue
	cout << "Priority queue content (Size - " << intQue.GetSize() << ") : " << endl;

	while (intQue.isEmpty() == false)
	{
		cout << "  Priority: " << intQue.front().GetPriority();
		cout << "  ID: " << intQue.front().GetData();
		cout << endl;

		intQue.pop();
	}
	cout << endl;
	if (intQue.isEmpty() == true)
	{
		cout << "The container is empty." << endl;
	}
	else
	{
		cout << "The container is NOT empty." << endl;
	}

	return 0;
}