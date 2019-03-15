#include "iostream"
#include <string>
using namespace std;

class Student
{
	public:
		Student(int,string,float);
		virtual void display();
	protected:
		int num;
		string name;
		float score;
};

Student::Student(int a, string b , float c)
{
	num  	= a;
	name 	= b;
	score 	= c;
}

void Student::display()
{
	cout << "num = "<<num<<endl;
	cout << "name = "<<name<<endl;
	cout << "score = "<<score<<endl;
}

class Graduate:public Student
{
	public:
		Graduate(int,string,float,float);
		void display();
	protected:
		float  wage;
 }; 
 
 Graduate::	Graduate(int n,string nam,float s,float w):Student(n,nam,s)
 {
 	num = n;
 	name = nam;
 	score = s;
 	wage = w;
 }
 
 void Graduate::display()
 {
 		cout << "num = "<<num<<endl;
	cout << "name = "<<name<<endl;
	cout << "score = "<<score<<endl;
	cout << "wage = "<<wage<<endl;
 }
 
 int main()
 {
 	Student stu1(00001,"Kevin",97.56);
 	Graduate stu2(00002,"Lan",66.26,5000);
 	Student *p = &stu1;
 	p->display();
 	p = &stu2;
 	p->display();
 	return 0;
 }
