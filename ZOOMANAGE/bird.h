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
	void nhaptuFile(stringstream& ss);
	bool KhaNangBay() { return canFly; }
	float DoDaiSaiCanh() { return wingSpan; }
	string MauLongChim() { return featherColor; }
};

