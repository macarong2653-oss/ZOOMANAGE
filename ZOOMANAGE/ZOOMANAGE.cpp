
#include <iostream>
#include"manage.h"
int main()
{
	
    manage ht;
	ht.LoadDataFromFile("D:\input.txt");
	ht.runManager();
	ht.ExportToFile("D:\output.txt");
	return 0;
	//long
}


