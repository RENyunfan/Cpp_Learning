

# C++ 复习（二） 类和对象

## 1 对象成员的引用

### 1.1  通过对象名和成员运算符访问成员

```cpp
class Student
{
    public:
    	char name[10];
		void display();
    private:
    	char sex[5];
    	int age;
};

void Student::display()
{
    cout<<"sex:"<<sex<<endl;
    cout<<"age:"<<age<<endl;
}

Student Kevin;
Kevin.name = "Kevin";
Kevin.display();

//通过对象名和成员运算符 "." 来访问成员,功能实现类似于结构体。
```

### 1.2 通过指向对象的指针访问成员

```cpp
class Student
{
    public:
    	char name[10];
		void display();
    private:
    	char sex[5];
    	int age;
};

void Student::display()
{
    cout<<"sex:"<<sex<<endl;
    cout<<"age:"<<age<<endl;
}

Student Kevin,*pk;
pk = &Kevin;
cout<< pk->age << endl;
```

### 1.3 使用引用访问成员

```cpp
class Student
{
    public:
    	char name[10];
		void display();
    private:
    	char sex[5];
    	int age;
};

void Student::display()
{
    cout<<"sex:"<<sex<<endl;
    cout<<"age:"<<age<<endl;
}

Student Kevin;
Student &k = Kevin;
cout<<k.name<<endl;
```

## 2 怎样使用类和对象

### 2.1 带参数的构造函数

​	有时候用户希望对不同的对象赋予不同的值，这时候就要使用带参数的构造函数，如一下例子

```cpp
// cpp.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;

class Student
{
public:
	Student(string,string,int);
	void ShowName();
	void ShowInfo();
private:
	string name;
	string sex;
	int age;
};

Student::Student(string a,string b,int c)
{
	name = a;
	sex = b;
	age = c;
}

void Student::ShowName()
{
	cout << "name:" << name << endl;
}

void Student::ShowInfo()
{
	cout << "age:" << age << endl;
	cout << "sex:" << sex << endl;
}


int main()
{
	Student stu1("Kevin","male",19),*ps;
	ps = &stu1;
	stu1.ShowName();
	stu1.ShowInfo();
    return 0;
}

```

### 2.2 参数初始化表

```cpp
//构造函数可以改成以下形式 感觉没啥用 先不学了
Student::Student(int h,int w,int len) : height(h),width(w),length(len)){ }
```

 ### 2.3 构造函数重载

```cpp
// cpp.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;

class Student
{
public:
	Student();
	Student(string,string,int);
	void ShowName();
	void ShowInfo();
private:
	string name;
	string sex;
	int age;
};
Student::Student()
{
	name = "James";
	sex = "make";
	age = 32;
}

Student::Student(string a,string b,int c)
{
	name = a;
	sex = b;
	age = c;
}

void Student::ShowName()
{
	cout << "name:" << name << endl;
}

void Student::ShowInfo()
{
	cout << "age:" << age << endl;
	cout << "sex:" << sex << endl;
}


int main()
{
	Student stu1("Kevin","male",19),*ps;
	ps = &stu1;
	stu1.ShowName();
	stu1.ShowInfo();
	Student stu2;
	stu2.ShowName();
	stu2.ShowInfo();
    return 0;
}

/*****************输出结果*****************************
name:Kevin
age:19
sex:male
name:James
age:32
sex:make
请按任意键继续. . .
*******************************************************/
```

### 2.4 使用默认参数构造函数

```cpp
// cpp.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;

class Student
{
public:
	//Student();
	Student(string,string,int);
	void ShowName();
	void ShowInfo();
private:
	string name;
	string sex;
	int age;
};
/*
Student::Student()
{
	name = "James";
	sex = "make";
	age = 32;
}
*/
Student::Student(string a = "James",string b = "male",int c = 32)
{
	name = a;
	sex = b;
	age = c;
}

void Student::ShowName()
{
	cout << "name:" << name << endl;
}

void Student::ShowInfo()
{
	cout << "age:" << age << endl;
	cout << "sex:" << sex << endl;
}


int main()
{
	Student stu1("Kevin","male",19),*ps;
	ps = &stu1;
	stu1.ShowName();
	stu1.ShowInfo();
	Student stu2;
	stu2.ShowName();
	stu2.ShowInfo();
    return 0;
}


```

### 2.5 利用析构函数清理

```cpp
// cpp.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;

class Student
{
public:
	//Student();
	Student(string,string,int);
	~Student();
	void ShowName();
	void ShowInfo();
private:
	string name;
	string sex;
	int age;
};

Student::~Student()
{
	cout << "Object has been destruct" << endl;
}

Student::Student(string a = "James",string b = "male",int c = 32)
{
	name = a;
	sex = b;
	age = c;
}

void Student::ShowName()
{
	cout << "name:" << name << endl;
}

void Student::ShowInfo()
{
	cout << "age:" << age << endl;
	cout << "sex:" << sex << endl;
}


int main()
{
	Student stu1("Kevin","male",19),*ps;
	ps = &stu1;
	stu1.ShowName();
	stu1.ShowInfo();
	Student stu2;
	stu2.ShowName();
	stu2.ShowInfo();
    return 0;
}


```

注意,对象的构造和析构一般是服从栈原则的,另外,如果定义了静态局部对象,那么就只会执行构造函数而不会执行析构函数

### 2.6 对象指针

```cpp
#include "iostream"
using namespace std;

class Time
{
	public:
		Time(int,int,int);
		int hour;
		int min;
		int sec;
		void get_time();
	private:
		int s; 
};


Time::Time(int a,int b,int c)
{
	hour = a;
	min = b;
	sec = c;
}

void Time::get_time()
{
	cout << hour << ":" << min << ":" << sec << endl;
}

int main()
{
	Time time(1, 2, 3);
	int *p = &time.hour;
	
	cout<<*p<<endl;
	time.get_time();
	return 0;
}
```

### 2.6 指向当前对象的this指针

this指针再类里是隐式调用的,如果需要使用可以用this,作为c++中的关键字。

### 2.7 对象的动态建立和释放

```cpp
//C语言中可以用new命令来创建一个空间,用delete来销毁一个空间.
new Box;
//执行以上指令时系统开辟了一段内存空间,并在此内存空间中存放了以一个Box对象,用new命令动态分配一个内存后会返回一个指针
Box *p;
p = new Box;
cout<< p->height<<endl;//可以通过这种方式来访问.

//此外c++还支持在执行new时对新建对象进行初始化
Box *p = new Box(1,1,1);

//在不需要对象的时候,只需要销毁指针级可
delete p;
```

### 2.8 友元

​	如果在本类以外的地方定义了一个函数,这个函数可以是不属于任何类的,在类中用friend对其进行声明,此函数就可以访问私有成员.

​	