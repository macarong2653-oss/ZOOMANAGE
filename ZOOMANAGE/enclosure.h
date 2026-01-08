#pragma once
#include "animal.h"
#include<iostream>

#include<vector>
class caretaker;
class enclosure
{
	string enclosureid;
	vector<animal*>a;
	string name;
	vector <caretaker*> ct;
public:
	enclosure();
	enclosure(const string& id, const string& name);
	void nhap();
	void them(animal* x);
	friend ostream& operator<<(ostream& os, const enclosure& e);
	void addcaretaker(caretaker* c);
	vector<animal*>& getAnimals() { return a; }
	string getName() { return name; }
	string getEnclosureID() const { return enclosureid; }
	void RemoveAnimal(const string& animalID);
	void DisplayOccupants();
	size_t hienthisoluong() { return a.size(); }
	vector <caretaker*> getCaretakers() { return ct; }
};
