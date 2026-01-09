#include "reptile.h"
#include<iostream>
#include"string"
using namespace std;
#include <fstream>
#include <sstream>
string reptile::taoma()
{
    string s = "r";

    if (nextid < 10)
        s += "00" + to_string(nextid);
    else if (nextid < 100)
        s += "0" + to_string(nextid);
    else
        s += to_string(nextid);

    nextid++;
    id = s;
    return s;
}
void reptile::nhap()
{
    reptile::taoma();
    animal::nhap();
    cout << "- Co doc (1/0): ";
    cin >> isPoisonous;
    cout << "- Tan suat lot da (ngay): ";
    cin >> sheddingFrequency;
    cout << "- Nhiet do moi truong yeu cau (°C): ";
    cin >> requiredTemperature;
    cin.ignore();
}
void reptile::hienthi()
{
    animal::hienthi();
    cout << "- Co doc          : " << (isPoisonous ? "Co" : "Khong") << endl;
    cout << "- Tan suat lot da : " << sheddingFrequency << " (ngay)" << endl;
    cout << "- Nhiet do yeu cau: " << requiredTemperature << " (°C)" << endl;
}
string reptile::hienthitype()
{
    return "reptile";
}
void reptile::nhaptuFile(stringstream& ss)
{
    ss  >> name >> weight >> age >> gender >> enclosureID >> trangthaisuckhoe
        >> isPoisonous >> sheddingFrequency >> requiredTemperature;
    reptile::taoma();
}