#include "iostream"
#include "dataStructure.h" 
using namespace std;



int main()
{
	
	AList<int> L1(10);
	int c = L1.length();
	cout<<c<<" ";
	L1.insert(12);
	c = L1.length();
	cout<<c<<" ";
	return 0;
}
