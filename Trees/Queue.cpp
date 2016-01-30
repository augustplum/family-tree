// queue.cpp

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

#include "queue.h"

Queue::Queue() {

}

Queue::~Queue() {
	while (frontNode != NULL) {
		dequeue();
		if (frontNode == backNode) {
			frontNode = NULL;
			backNode = NULL;
		}
	}
	cout << "Queue has been deconstructed" << endl;
}

bool Queue::enqueue(ItemType& newItem) {
	Node *cur = new Node; // new node to store newItem
	cur->item = newItem; // store newItem
	cur->next = NULL;

	// consider case of empty queue
	if (this->isEmpty()) {
		frontNode = cur;
	}
	else {
		backNode->next = cur; // make back node's next pointer to pt to new node
	}
	backNode = cur; // make back node point to the new node
	return true;
}

bool Queue::dequeue() {
	Node *temp = new Node;
	if (frontNode == backNode) { // only one Node in Queue
		frontNode = NULL;
		backNode = NULL;
	}
	else {
		temp = frontNode;
		frontNode = frontNode->next;
	}
	temp->next = NULL; // good practice
	delete temp; // (?) no need to delete temp->item?
	return true;
}

bool Queue::dequeue(ItemType& item) {
	Node *temp = new Node;
	if (frontNode == backNode) { // only one Node in Queue
		frontNode = NULL;
		backNode = NULL;
	}
	else {
		temp = frontNode;
		frontNode = frontNode->next;
	}
	temp->next = NULL; // good practice

	item = temp->item;
	delete temp;
	return true;
}

void Queue::getFront(ItemType& item) {
	if (!this->isEmpty()) {
		item = frontNode->item;
	}
}

void Queue::displayItems() {
	Node *cur = new Node;
	cur = frontNode;
	cout << "Items in Q: ";
	while (cur != NULL) {
		cout << cur->item << " ";
		cur = cur->next;
	}
	cout << endl;
};

bool Queue::isEmpty() {
	return frontNode == NULL; // backNode also can
};