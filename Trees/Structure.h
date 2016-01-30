// Structure.h
#pragma once
#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <iostream>
#include <string>

#include "Person.h"

typedef Person ItemType;

struct Node
{
	ItemType	person;			// data item
	Node		*left = NULL;	// pointer pointing to left subtree
	Node		*right = NULL;	// pointer pointing to right subtree
};

class Structure {
private:
	Node* root = NULL;
public:
	Structure();
	Node*getRoot();
	Node*getPerson(Node* t, string);
	Node*traverse(Node*, Node*, string);
	void setRoot(Node*);
	bool insert();
	bool insertChild(Node*, ItemType);
	bool insertSibling(Node*, ItemType);
	void remove();
	bool search(string);
	void display(Node*);
	int size(Node*);
	void update(Node*);
};
#endif