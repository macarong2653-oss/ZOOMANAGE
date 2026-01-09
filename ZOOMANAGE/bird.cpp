#include "bird.h"
#include<iostream>
#include"string"
#include <fstream>
#include <sstream>
using namespace std;
void bird::nhapFromStream(stringstream& ss)
{
    ss >> name >> weight >> age >> gender >> enclosureID >> healthStatus
        >> canFly >> wingSpan >> featherColor;
    bird::taoma();
}
string bird::taoma()
{
    string s = "b";

    if (nextid < 10)
        s += "00" + to_string(nextid);
    else if (nextid < 100)
        s += "0" + to_string(nextid);
    else
        s += to_string(nextid);

    nextid++;
    id=s;
    return s;
}
void bird::nhap()
{ 
    bird::taoma();
    animal::nhap();
    cout << "- Nhap sai canh (m): ";
    cin >> wingSpan;
    cout << "- Co the bay (1/0): ";
    cin >> canFly;
    cin.ignore();
    cout << "- Nhap mau long: ";
    getline(cin, featherColor);
}
void bird::hienthi()
{
    animal::hienthi();
    cout << "- Sai canh     : " << wingSpan << " (m)" << endl;
    cout << "- Co the bay   : " << (canFly ? "Co" : "Khong") << endl;
    cout << "- Mau long     : " << featherColor << endl;
}
string bird::hienthitype()
{
    return "bird";
}