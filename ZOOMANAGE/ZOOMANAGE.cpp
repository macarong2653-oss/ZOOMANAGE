#include <iostream>
#include"manage.h"
int main()
{
	
    manage ht;
	ht.TaiDuLieuTuFile("D:\\input.txt");
	ht.MENUQuanLy();
	ht.XuatRaFile("D:\\output.txt");
	return 0;
	
}


