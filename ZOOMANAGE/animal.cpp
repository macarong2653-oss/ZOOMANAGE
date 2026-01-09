#include "animal.h"
#include<iostream>

using namespace std;
 int animal:: nextid=1;
void animal::nhap()
{
	cout << "- Nhap ten: ";
	cin.ignore();
	getline(cin, name);
	cout << "- Nhap can nang: ";
	cin >> weight;
	cout << "- Nhap tuoi: ";
	cin >> age;
	cin.ignore();
	cout << "- Nhap gioi tinh (Male/Female): "; 
	getline(cin, gender);
	cout << "- Nhap tinh trang suc khoe: ";
	getline(cin, healthStatus);
}
void animal::hienthi()
{
	cout << "--- Thong tin dong vat ---" << endl;
	cout << "- ID                 : " << id << endl;
	cout << "- Ten                : " << name << endl;
	
	cout << "- Gioi tinh          : " << gender << endl;
	cout << "- Tuoi               : " << age << endl;
	cout << "- Can nang           : " << weight << " (kg)" << endl;
	cout << "- ID Chuong          : " << enclosureID << endl;
	cout << "- Trang thai suc khoe: " << trangthaisuckhoe << endl;
	
}
string animal::hienthiid()
{
	return id;
}

string animal::hienthiten() {
	return name;
}
float animal::hienthican(){
	return weight;
}
int animal::hienthituoi(){
	return age;
}
string animal::hienthitrangthaisuckhoe() { return healthStatus; }
