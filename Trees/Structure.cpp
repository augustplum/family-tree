#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

#include "Structure.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

Structure::Structure() {}
Node* Structure::getRoot() {
	return root;
}

void Structure::setRoot(Node* t) {
	root = t;
}

//This method gets the Node of string name and returns it
//input: rootNode, name of person to search 
//output: Node containing the person 
Node* Structure::getPerson(Node* t, string name) {
	if (t != NULL) {
		if (t->person.getName() == name)
			return t;
		else {
			Node *foundNode = getPerson(t->left, name);
			if (foundNode == NULL) {
				foundNode = getPerson(t->right, name);
			}
			return foundNode;
		}
	}
	else {
		return NULL;
	}
}

bool Structure::search(string name) {
	Node *fakeRoot = getRoot();
	Node *result;
	result = getPerson(fakeRoot, name);
	if (result == NULL) { //the person does not exist
		string name;
		return false; //the person does not exist
	}
	else {
		string name;
		return true;
	}
}

//This method inserts a member into the tree hiho
bool Structure::insert() {
	string input, parent;
	Person p;
	Node *parent_ref = getRoot();
	Node *root = getRoot();
	bool if_Person_Exists = true;
	
	cout << "Please enter name: ";
	getline(cin, input);
	p.setName(input);
	
	cout << "Please enter date of birth (DD/MM/YYYY): ";
	getline(cin, input);
	p.setDOB(input);

	cout << "Please enter occupation: ";
	getline(cin, input);
	p.setOcc(input);

	cout << "Please enter address: "; 
	getline(cin, input);
	p.setAddr(input);
	
	if (root == NULL) {
		root = new Node;
		root->person = p;
		setRoot(root);
		cout << "A new root has been defined!" << endl;
		return true; // esc
	}
	else {
		if_Person_Exists = search(input);
		while (if_Person_Exists) { // found
			cout << "Name already exist!\nPlease enter another name: ";
			getline(cin, input);
			if_Person_Exists = search(input);
		}
		p.setName(input);
	}

	// not found, start adding to tree
	cout << "Please enter reference name: ";
	getline(cin, parent);

	if_Person_Exists = search(parent); //e.g. true ->the reference exists
	//if_Person_Exists = !if_Person_Exists; //if_Person_Exists == false

	while (!if_Person_Exists) {
		cout << "Reference missing!\nPlease re-enter reference name: ";
		getline(cin, parent);
		if_Person_Exists = search(parent);
	}

	Node* ref_person = getPerson(parent_ref, parent);

	int option;
	do {
		cout << "(1) Child or (2) Sibling? : ";
		getline(cin, input);
		option = atoi(input.c_str());
	} while (option != 1 && option != 2);

	if (option == 1)
		insertChild(ref_person, p);
	if (option == 2)
		insertSibling(ref_person, p);

	return true;
}

bool Structure::insertChild(Node *t, ItemType person) {
	//1. Already has child
	Node *newChild = new Node;
	newChild->person = person;
	if (t->left == NULL) { //theres children
						   //insertSibling(t->left, person);
						   //insertChild(t->left, person);
		t->left = newChild;
		cout << "A new child " << newChild->person.getName() << " has been added to " << t->person.getName() << "!" << endl;
		return true; //a new child has been added to the new one!
	}
	//2. No child
	else {
		insertSibling(t->left, person);
		//t->left = newChild;
		cout << "This couple just had their first child " << newChild->person.getName() /*<< " has been added to " << t->person.getName()*/ << "!" << endl;
		return true; // this couple had their first child!
	}
	return false;
}

//This method inserts siblings
//input: reference Node (a node that has relationship to person) and person
//output: person would be added to reference Node as sibling
bool Structure::insertSibling(Node *t, ItemType person) {
	Node *newSibling = new Node, *prevSibling;
	newSibling->person = person;

	//1. Has sibling
	if (t->right != NULL) {
		prevSibling = t->right;
		t->right = newSibling;
		newSibling->right = prevSibling;
		cout << "A new sibling " << newSibling->person.getName() << " has been added to " << t->person.getName() << "!" << endl;
		return true;
	}

	//2. No sibling
	else {
		t->right = newSibling;
		cout << t->person.getName() << " has gotten his/her first sibling!" << endl;
		return true;
	}
	return false;
}

//This method displays the tree structure
//input: rootNode
void Structure::display(Node* fakeRoot) {
	if (fakeRoot != NULL) {
		display(fakeRoot->left);
		cout << fakeRoot->person.getName() << endl;
		display(fakeRoot->right);
	}
}

//This method removes Nodes without children
void Structure::remove() {
	Node* root = getRoot();
	if (root == NULL) {
		cout << "This tree is empty, there is nothing to remove! Try adding something in." << endl;
		return;
	}
	string input = "";
	cout << "Enter person's name: ";
	getline(cin, input);

	bool if_person_exists = search(input);

	while (!if_person_exists) {
		cout << "This person does not exist!\nPlease re-enter name: ";
		getline(cin, input);
		if_person_exists = search(input);
	}
	Node *person = root;
	Node *wannaRemove;
	wannaRemove = getPerson(person, input);

	if (wannaRemove == getRoot()) {
		setRoot(NULL);
		cout << "The tree is now empty!" << endl;
		return;
	}

	Node * personBefore = root;
	Node* pre = traverse(root, personBefore, input); //findBefore(personBefore, person);

													 //if right side is occupied
	if (wannaRemove->right != NULL) {
		pre->right = wannaRemove->right;
		delete wannaRemove;
	}

	//if only left is occupied
	else if (wannaRemove->left != NULL) {
		pre->left = wannaRemove->right;
		delete wannaRemove;
	}

	//it is a leaf node
	else if (wannaRemove->right == NULL && wannaRemove->left == NULL) {

		if (pre->right == wannaRemove)
			pre->right = NULL;
		else
			pre->left = NULL;

		delete wannaRemove;
	}
}

//input: Node (t)-> initially as fakeRoot to initiate traversal
//input: Node (g)-> reference Node for comparison to fakeRoot
//output: Node (t)-> becomes the Node before Node (g)
//output: Node (g)-> remains unchanged 
//void Structure::findBefore(Node *&t, Node* &g) {
// if (t != NULL) {
//
//  findBefore(t->left, g);
//  if (g == t->left || g == t->right)
//   return;
//  findBefore(t->right, g);
// }
//}

Node* Structure::traverse(Node* root, Node* output, string target) {
	if (root == NULL) return NULL;
	if (root->person.getName() == target) return output;

	Node* result = traverse(root->left, root, target);
	if (result) return result;

	result = traverse(root->right, output, target);
	if (result) return result;

	return NULL;
}


//This function returns the number of nodes in the tree strcuture
int Structure::size(Node *t)
{
	if (t == NULL) { //This node doesn't exist. Therefore there are no nodes in this 'subtree'
		return 0;
	}
	else { //Add the size of the left and right trees, then add 1 (which is the current node)
		return size(t->left) + size(t->right) + 1;
	}
}

//This method takes the node to change and asks for inputs
void Structure::update(Node* t) {
	string input;
	cout << "Please enter name: ";
	getline(cin, input);
	t->person.setName(input);

	cout << "Please enter date of birth (DD/MM/YYYY): ";
	getline(cin, input);
	t->person.setDOB(input);

	cout << "Please enter occupation: ";
	getline(cin, input);
	t->person.setOcc(input);

	cout << "Please enter address: ";
	getline(cin, input);
	t->person.setAddr(input);

	cout << t->person.getName() << " is now updated!" << endl;
}