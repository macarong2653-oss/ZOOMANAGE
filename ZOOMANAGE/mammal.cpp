#include "mammal.h"
#include<iostream>
#include<string>
#include <fstream>
#include <sstream>
using namespace std;

string mammal::taoma()
{
    string s = "m";

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
void mammal::nhap()
{
    mammal::taoma();
    animal::nhap();
    cout << "- Nhap thoi gian mang thai (ngay): ";
    cin >> gestationPeriod;
    cin.ignore();
    cout << "- Nhap mau long: ";
    getline(cin, furColor);
}
void mammal::hienthi()
{
    animal::hienthi();
    cout << "- Thoi gian mang thai: " << gestationPeriod << " (ngay)" << endl;
    cout << "- Mau long           : " << furColor << endl;
}
string mammal::hienthitype()
{
    return "mammal";
}
void mammal::nhapFromStream(stringstream& ss)
{
    ss  >> name >> weight >> age >> gender >> enclosureID >> trangthaisuckhoe
        >> gestationPeriod >> furColor;
    mammal::taoma();
}