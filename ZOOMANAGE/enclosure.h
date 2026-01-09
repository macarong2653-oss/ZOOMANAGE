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
	void themnhanvien(caretaker* c);
	vector<animal*>& LayDongVat() { return a; }
	string TenChuong() { return name; }
	string IDchuong() const { return enclosureid; }
	void XoaDongVat(const string& animalID);
	//void NhanVienPhuTrach();
	size_t hienthisoluong() { return a.size(); }
	vector <caretaker*> NhanVienPhuTrach() { return ct; }
	
};
