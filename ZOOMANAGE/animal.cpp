#include "animal.h"
#include<iostream>

using namespace std;
 int animal:: nextid=1;
void animal::nhap()
{
	cout << "nhap ten";
	cin.ignore();
	getline(cin, name);
	cout << "nhap can nang";
	cin >> weight;
	cout << "nhap tuoi";
	cin >> age;
	cin.ignore();
	cout << "nhap gioi tinh (Male/Female): "; 
	getline(cin, gender);
	cout << "nhap tinh trang suc khoe";
	getline(cin, healthStatus);
}
void animal::hienthi()
{
	cout << "--- Thong tin dong vat ---" << endl;
	cout << "ID: " << id << endl;
	cout << "Ten: " << name << endl;
	
	cout << "Gioi tinh: " << gender << endl;
	cout << "Tuoi: " << age << endl;
	cout << "Can nang: " << weight << " kg" << endl;
	cout << "ID Chuong: " << enclosureID << endl;
	cout << "Trang thai suc khoe: " << healthStatus << endl;
	
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
string animal::hienthiHealthStatus() { return healthStatus; }
