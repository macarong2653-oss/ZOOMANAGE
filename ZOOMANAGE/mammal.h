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
	void nhapFromStream(stringstream& ss);
	string getFurColor() { return furColor; }
};
