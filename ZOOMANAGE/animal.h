#pragma once
#include <string>
using namespace std;
class animal
{
protected:
	string id;
	string name;
	float weight;
	int age;
	string gender;
	static int nextid;
	string enclosureID;
	string healthStatus;
public:
	
	virtual void nhap()=0;
	virtual void hienthi()=0;
	virtual string hienthitype() = 0;
	string hienthiid();
	string hienthiten();
	float hienthican();
	int hienthituoi();
	string hienthiHealthStatus();
	string hienthienclosureid() { return enclosureID; }
	virtual void nhapFromStream(stringstream& ss) = 0;
};

