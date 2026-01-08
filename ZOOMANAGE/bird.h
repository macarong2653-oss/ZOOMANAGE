#pragma once
#include"animal.h"
class bird:public animal
{
	bool canFly;
	float wingSpan;
	string featherColor;
public:
	string taoma();
	void nhap();
	void hienthi();
	string hienthitype();
	void nhapFromStream(stringstream& ss);
	bool getCanFly() { return canFly; }
	float getWingSpan() { return wingSpan; }
};

