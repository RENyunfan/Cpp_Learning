#include <iostream>
#include "kstack.h"
using namespace std;

int main(){
	
	AStack<int> stk1;
	stk1.push(10);
	int l = stk1.length();
	int ele = stk1.topValue(); 
	cout<<l<<" "<<ele<<endl;
	
	return 0;
}
