#include <iostream>
#include "ktree.h" 
using namespace std;


int main()
{
	BSTNode<int,int> a;
	a.setElement(1);
	bool s = a.isLeaf();
	cout<<s<<endl;
	
	return 0;	
}
