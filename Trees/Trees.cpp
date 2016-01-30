// Trees.cpp

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

#include "Structure.h"

void Search(Structure *tree);
void displayMenu(Structure *tree);
void Update(Structure *tree);

//This method checks for non-numeric characters
bool checkMenuInput(string input)
{
	char c;
	for (int i = 0; i < input.length(); i++)
	{
		c = input.at(i);
		if (!(c >= '0' && c <= '9'))
		{
			cout << "Non-numeric characters detected." << endl;
			return false;
		}
	}
	return true;
}

void initTree(Structure *tree) {
	Node* a1 = new Node;
	Node* b1 = new Node;
	Node* c1 = new Node;
	Node* d1 = new Node;
	Node* e1 = new Node;
	Node* f1 = new Node;
	Node* g1 = new Node;

	tree->setRoot(a1);
	Person a;
	a.setName("Aloy");
	a.setAddr("Boon Keng Street");
	a.setOcc("Student");
	a.setDOB("10201992");
	
	Person b;
	b.setName("Ben");
	b.setAddr("26 Teng Seng Road");
	b.setOcc("Private Banker");
	b.setDOB("20021995");

	Person c;
	c.setName("Charles");
	c.setAddr("9 Clementi Point District");
	c.setOcc("Construction Worker");
	c.setDOB("30011998");

	Person d;
	d.setName("Danny");
	d.setAddr("8 Da Re Da Re Avenue");
	d.setOcc("Daisy Collector");
	d.setDOB("25061996");

	Person e;
	e.setName("Eli");
	e.setAddr("10 Exclamation Mark");
	e.setOcc("Elementary School Teacher");
	e.setDOB("20041998");
	
	Person f;
	f.setName("Fin");
	f.setAddr("99 Finland");
	f.setOcc("Funny Guy");
	f.setDOB("27032000");

	Person g;
	g.setName("Gab");
	g.setAddr("20 Geylang Street");
	g.setOcc("Student");
	g.setDOB("06201990");

	a1->left = b1;
	b1->left = d1;
	b1->right = e1;
	a1->right = c1;
	c1->left = f1;
	c1->right = g1;

	a1->person = a;
	b1->person = b;
	c1->person = c;
	d1->person = d;
	e1->person = e;
	f1->person = f;
	g1->person = g;

}

void displayMenu(Structure *tree) {
	string option;
	int op = 0;
	do {
		cout << "Welcome to Genealogy Tree Version 0.1";
		cout << "\n===========================================================";
		cout << "\n[1] Insert";
		cout << "\n[2] Remove";
		cout << "\n[3] Search";
		cout << "\n[4] Display";
		cout << "\n[5] Check for updates";
		cout << "\n[6] Show Root (Troubleshoot)";
		cout << "\n[7] No. of Family number";
		cout << "\n[8] Update a family member";
		cout << "\n[9] Initialise tree";
		cout << "\n[0] Exit";
		cout << "\n===========================================================";
		cout << "\nYour option: ";

		getline(cin, option);

		if (checkMenuInput(option)) { //if it IS a number
			op = atoi(option.c_str());
			Node* root = NULL;

			switch (op) {
			case 1: tree->insert();
				cout << endl;
				break;
			case 2: tree->remove();
				cout << endl;
				break;
			case 3: Search(tree);
				cout << endl;
				break;
			case 4:
				root = tree->getRoot();
				tree->display(root);
				cout << endl;
				break;
			case 5: cout << "Updates coming this Thursday, key version: 3528dh29egak48202[16hex]" << endl;
				cout << endl;
				break;
			case 6: cout << "Root: " << tree->getRoot()->person.getName() << " (" << tree->getRoot() << ")" << endl;
				cout << endl;
				break;
			case 7: cout << "The family has " << tree->size(root) << " members." << endl;
				cout << endl;
				break;
			case 8: Update(tree);
				cout << endl;
				break;
			case 9: initTree(tree);
				cout << "Tree initialised with preset people" << endl;
				cout << endl;
				break;
			case 0: cout << "Exit" << endl;
				break;
			default: break;
			}
		}
	} while (op != 0);
}

//This method uses the Search function in Tree written in Structure.cpp
void Search(Structure *tree) {
	string input = "";
	cout << "Please enter name for search: "; 
	getline(cin, input);
	bool personFound =  tree->search(input);
	
	if (personFound) {
		cout << "This person exists!" << endl;
		Node* result = tree->getPerson(tree->getRoot(), input);
		cout << "\nName: " << result->person.getName();
		cout << "\nDate of Birth: " << result->person.getDOB();
		cout << "\nAddress: " << result->person.getAddr();
		cout << "\nOccupation: " << result->person.getOcc();
		cout << endl;
	}
	else
		cout << "This person does not exist!" << endl;
}

void Update(Structure *tree) {
	string input;
	bool validation;
	cout << "Please enter the name: ";
	getline(cin, input);
	validation = tree->search(input);

	while (!validation) {
		cout << "This person does not exist!\nPlease re-enter name: ";
		getline(cin, input);
		validation = tree->search(input);
	}

	tree->update(tree->getPerson(tree->getRoot(), input));
}

int main()
{
	Structure* tree = new Structure;
	displayMenu(tree);
	return 0;
}


