#include "caretaker.h"
#include<iostream>
#include<vector>
#include"enclosure.h"
using namespace std;
class enclosure;
void caretaker::nhap()
{
	cout << "- Nhap ten nhan vien: ";
	getline(cin,name);
	//cin.ignore();
	cout << "- Nhap ID nhan vien: "; cin >> id;
}
void caretaker::hienthi()
{
	cout << "- Ten nhan vien: " << name << endl;
	cout << "- ID           : " << id<<endl;
	cout << "- Danh sach chuong quan ly:  ";
	for (auto* e : ec)
	{
		cout<<e->IDchuong();
	}

}
void caretaker::ThemVaoChuong(enclosure* e )
{
		
		for (auto en : ec)
			if (en == e) return;
		ec.push_back(e);
	
}
caretaker::caretaker(){}
caretaker::caretaker(const string& id, const string& name)
{
	this->id = id;
	this->name = name;
}
// Hi