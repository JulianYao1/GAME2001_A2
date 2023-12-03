// Julian Yao, 101419348
#include <iostream>
#include "PriorityQueue.h"
using namespace std;

int main()
{
	cout << "Test for priority queue." << endl << endl;
	const int ListSize = 10;

	// Create a PriorityQueue containing integers with the size of 10, priorities are ordered from lesser to greater.
	PriorityQueue < PriorityQueueData<int>, less_cmp<PriorityQueueData<int>>> intQueue(ListSize);
	
	// (int priority, T data)
	intQueue.push(PriorityQueueData<int>(5, 1));
	intQueue.push(PriorityQueueData<int>(2, 2));
	intQueue.push(PriorityQueueData<int>(3, 3));
	intQueue.push(PriorityQueueData<int>(1, 4));
	intQueue.push(PriorityQueueData<int>(3, 5));
	intQueue.push(PriorityQueueData<int>(5, 6));
	intQueue.push(PriorityQueueData<int>(7, 7));
	intQueue.push(PriorityQueueData<int>(9, 8));
	intQueue.push(PriorityQueueData<int>(2, 9));
	intQueue.push(PriorityQueueData<int>(3, 10));

	cout << "Priority Queue (int) from lesser to greater: " << endl;
	while (!intQueue.isEmpty())
	{
		cout << "Priority [" << intQueue.front().GetPriority() << "]  Data: " << intQueue.front().GetData() << endl;
		intQueue.pop();
	}
	cout << endl;



	// Create a PriorityQueue containing strings with the size of 10, priorities are ordered from greater to lesser.
	PriorityQueue < PriorityQueueData<string>, greater_cmp<PriorityQueueData<string>>> stringQueue(ListSize);

	stringQueue.push(PriorityQueueData<string>(5, "string1"));
	stringQueue.push(PriorityQueueData<string>(2, "string2"));
	stringQueue.push(PriorityQueueData<string>(3, "string3"));
	stringQueue.push(PriorityQueueData<string>(2, "string4"));
	stringQueue.push(PriorityQueueData<string>(4, "string5"));
	stringQueue.push(PriorityQueueData<string>(1, "string6"));
	stringQueue.push(PriorityQueueData<string>(4, "string7"));
	stringQueue.push(PriorityQueueData<string>(6, "string8"));
	stringQueue.push(PriorityQueueData<string>(5, "string9"));
	stringQueue.push(PriorityQueueData<string>(3, "string10"));

	cout << "Priority Queue (string) from greater to lesser: " << endl;
	while (!stringQueue.isEmpty())
	{
		cout << "Priority [" << stringQueue.front().GetPriority() << "]  Data: " << stringQueue.front().GetData() << endl;
		stringQueue.pop();
	}
	cout << endl;



	// Create a PriorityQueue containing floats with the size of 10, priorities are ordered from lesser to greater.
	PriorityQueue < PriorityQueueData<float>, less_cmp<PriorityQueueData<float>>> floatQueue(ListSize);

	floatQueue.push(PriorityQueueData<float>(6, 123.4f));
	floatQueue.push(PriorityQueueData<float>(4, 1.5f));
	floatQueue.push(PriorityQueueData<float>(2, 63.25f));
	floatQueue.push(PriorityQueueData<float>(1, 43.6f));
	floatQueue.push(PriorityQueueData<float>(4, 446.22f));
	floatQueue.push(PriorityQueueData<float>(1, 5.12f));
	floatQueue.push(PriorityQueueData<float>(2, 74.65f));
	floatQueue.push(PriorityQueueData<float>(8, 23.0f));
	floatQueue.push(PriorityQueueData<float>(7, 49.7f));
	floatQueue.push(PriorityQueueData<float>(3, 2.75f));

	cout << "Priority Queue (floats) from lesser to greater: " << endl;
	while (!floatQueue.isEmpty())
	{
		cout << "Priority [" << floatQueue.front().GetPriority() << "]  Data: " << floatQueue.front().GetData() << endl;
		floatQueue.pop();
	}
	return 0;
}