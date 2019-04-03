#include <iostream>
#include "dataStructure.h"
using namespace std;


int main()
{
	LList<int> L1;
	L1.insert(100);
	int o = 10;
	while(o--)
	L1.append(12);
	L1.print();
	return 0;
 } 
