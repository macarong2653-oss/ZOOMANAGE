#include "caretaker.h"
#include<iostream>
#include<vector>
#include"enclosure.h"
using namespace std;
class enclosure;
void caretaker::nhap()
{
	cout << "nhap ten nhan vien :";
	getline(cin,name);
	cin.ignore();
	cout << "nhap id nhan vien "; getline(cin,id);
}
void caretaker::hienthi()
{
	cout << "ten nhan vien:" << name << endl;
	cout << "id:" << id<<endl;
	cout << "danh sach chuong quan ly ";
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
