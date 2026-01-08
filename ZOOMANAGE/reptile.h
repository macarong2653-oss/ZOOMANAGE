#pragma once
#include"animal.h"
#include"string.h"
class reptile:public animal
{
	bool isPoisonous; // Có độc
	int sheddingFrequency; // Tần suất lột da (ngày)
	double requiredTemperature; // Nhiệt độ môi trường cần thiết (°C)
	
public:
	string taoma();
	void nhap();
	void hienthi();
	string hienthitype();
	void nhapFromStream(stringstream& ss);
	bool getIsPoisonous() { return isPoisonous; }
};

