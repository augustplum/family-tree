#pragma once
// queue.h

#ifndef QUEUE_H
#define QUEUE_H
#include <string>
#include <iostream>

using namespace std;

typedef char ItemType;

class Queue {
private:
	struct Node {
		ItemType item;
		Node	 *next;
	};
	Node *frontNode;
	Node *backNode;
public:
	Queue();
	~Queue();
	// add a new item to the back of the queue
	// pre : size < MAX_SIZE
	// post: item is added to the back of the queue
	bool enqueue(ItemType&);
	// removes item from top of the stack(pop)
	// pre : stack is not empty
	// post: item top of stack was removed
	bool dequeue();
	bool dequeue(ItemType&);
	void getFront(ItemType&);
	void displayItems();
	bool isEmpty();
};
#endif