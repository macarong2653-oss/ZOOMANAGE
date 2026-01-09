#pragma once
#include"animal.h"
#include"string"
using namespace std;
class mammal:public animal
{
	int gestationPeriod; 
	string furColor; 

public:
	string taoma();
	void nhap();
	void hienthi();
	string hienthitype();
	void nhaptuFile(stringstream& ss);
	string MauLongThu() { return furColor; }
};
