#include "enclosure.h"
#include<iostream>
#include"string"
using namespace std;
#include"caretaker.h"
enclosure::enclosure()
{
	
}
enclosure::enclosure(const string& id, const string& name)
{
	this->enclosureid = id;
	this->name = name;
}
void enclosure::nhap()
{
	cout << "- Nhap ID chuong (EnclosureID): ";
	getline(cin, enclosureid);
	cout << "- Nhap Ten chuong: ";
	getline(cin, name);
	
}
void enclosure::them(animal* x)
{
	for (auto b : a)
	{
		if (b == x)
			return;
	}
	a.push_back(x);
}
ostream& operator<<(ostream& os, const enclosure& e)
{
	os << "Enclosure ID: " << e.enclosureid
		<< "\nTen chuong    : " << e.name
		<< "\nSo dong vat   : " << e.a.size()
		<< "\nSo nhan vien  : " << e.ct.size()
		<< "\n---------------------------\n";

	os << "Cac dong vat trong chuong:" << endl;

	if (e.a.empty()) {
		os << "Chuong trong." << endl;
	}
	else {
		int i = 1;
		for (auto b : e.a) {
			os << i++ << ". " << b->hienthiten()
				<< " (ID: " << b->hienthiid()
				<< ", Loai: " << b->hienthitype() << ")" << endl;
		}
		cout << "\n--------------------------\n";
	}

	return os; 
}
void enclosure:: addcaretaker(caretaker* c) {
	for (auto ct_ : ct)
		if (ct_ == c) return;
	ct.push_back(c);
	c->addenclosure(this);
}
void enclosure::RemoveAnimal(const string& animalID)
{
	for (auto it = a.begin(); it != a.end(); ++it)
	{
		if ((*it)->hienthiid() == animalID)
		{
			delete* it;        // Giải phóng bộ nhớ con trỏ animal*
			a.erase(it);       // Xóa khỏi vector
			cout << "Da xoa dong vat co ID: " << animalID << endl;
			return;
		}
	}
	cout << "!!!! Khong tim thay dong vat co ID: " << animalID << endl;
}
