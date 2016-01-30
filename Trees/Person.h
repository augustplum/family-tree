// Person.h
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using std::string;

class Person {
private:
	string name;
	string date_birth; // date of birth
	string date_death; // date of death
	string address;
	string spouse;
	string occupation;
public:
	Person() { date_birth = " "; date_death = " ", spouse = " ", name = " "; }
	void setAddr(string addr) { address = addr; }
	void setOcc(string occ) { occupation = occ; }
	void setName(string n) { name = n; }
	void setDOB(string dob) { date_birth = dob; }
	void setDOD(string dod) { date_death = dod; }
	void setSpouse(string s) { spouse = s; }

	string getName() { return name; }
	string getDOB() { return date_birth; }
	string getDOD() { return date_death; }
	string getAddr() { return address; }
	string getOcc() { return occupation; }
	string getSpouse() { return spouse; }
};
#endif