#pragma once
#include"string"

#include<vector>
class enclosure;
using namespace std;
class caretaker
{
	string name;
	string id;
	vector<enclosure*>ec;
public:
	caretaker();
	caretaker(const string& id, const string& name);
	void nhap();
	void hienthi();
	void addenclosure(enclosure* e);
	string getId() const { return id; }
	string getName() const { return name; }
	
};

