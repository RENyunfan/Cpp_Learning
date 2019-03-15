# 数据结构

```cpp
int int& int* int** 的用法区别

int 是c++关键字，表示整数

int& 是变量的引用，引用是C++的特性，也叫变量的别名，会带着改变原变量的一切
```

# 0 报错

![1552014694272](C:\Users\1234567\AppData\Roaming\Typora\typora-user-images\1552014694272.png)

```cpp
//该错误出现在继承栈ADT的时候，纯虚函数的类型不同，误加入了const 导致类型发生错误
	virtual E pop() const = 0;

		E pop(){
			return listArray[top--];
		}
```

![1552015043511](C:\Users\1234567\AppData\Roaming\Typora\typora-user-images\1552015043511.png)

```cpp
//该错误发生在定义栈的ADT中声明clear函数没有加=0声明为纯虚函数
		virtual void clear() = 0;
//该报错的主要原因是定义了clear函数而没有声明，因此还有一种解决方法是
		virtual void clear(){
		} ;
//注意2.2中纯虚函数和虚函数的区别。纯虚函数可以只声明没有定义，而在继承的子类中进行声明。但是虚函数必须声明，虽然它可以在子类中进行重载。
```



# 1 类的继承和派生

## 1.1 派生类的参数列表

```cpp
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
```



# 2 多态性与虚函数

## 2.1 虚函数的作用

​	同一个类中不能定义两个名字相同、参数个数和类型都相同的函数。但是再类的继承层次结构中，在不同层次中可以出现名字相同，而且参数个数和类型都行同的函数。这是合法的，因为他们不在同一个类中，编译系统按照同名覆盖的原则决定调用的对象

```4cpp
在调用中
cy1.area();
调用的是派生类中的成员函数
要是向调用基类中的成员函数，则需要使用作用域限制符号
cy1.Circle::area()

```

​	我们有这样的设想，能否用同一个调用形式，能调用派生类和基类的同名函数，在程序中不是通过对象名去调用不同派生层次的同名函数，而是**通过指针**分别调用这些同名函数。例如用语句pt->display()，只需要使用不同的pt，就可以调用不同层次的函数。这就是一个简单的多态概念。事先确定好，即在编译前确定的多态性叫做**静态多态性**，而程序运行过程中决定的多态性叫做**动态多态性**

​	C++中的虚函数就是用来解决动态多态问题的。

​	所谓虚函数，就是说基类声明函数是虚拟的，并不是实际存在的，然后在派生类中定义才正式定义为函数。在程序运行器件，用指针指向某一派生类对象，这样就能调用指针指向派生类中的函数，而不会调用其它派生类中的函数。

​	虚函数的作用时允许派生类中重新定义与基类相同的函数，并且可以通过基类指针或引用来访问基类和派生类中的同名函数。

```cpp
#include "iostream"
#include <string>
using namespace std;

class Student
{
	public:
		Student(int,string,float);
    	//void display();
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
```

在这个例子中display函数如果没有虚化,那么由于指针p是Student类型的，在第二次输出的时候也不会输出wage，也就是改变了函数指针后，虽然p指向新的stu2对象，但是调用的是基类中的display方法。

而我们加入virtual后，函数被虚化，这时候的display是重建的，再次使用执政访问就可以调用新的派生类中的方法了。

## 2.2 纯虚函数和虚函数的区别

* 虚函数和纯虚函数可以定义在同一个类(class)中，含有纯虚函数的类被称为抽象类(abstract class)，而只含有虚函数的类(class)不能被称为抽象类(abstract class)。

* 虚函数可以被直接使用，也可以被子类(sub class)重载以后以多态的形式调用，而纯虚函数必须在子类(sub class)中实现该函数才可以使用，因为纯虚函数在基类(base class)只有声明而没有定义。

* 虚函数和纯虚函数通常存在于抽象基类(abstract base class -ABC)之中，被继承的子类重载，目的是提供一个统一的接口。

* 虚函数的定义形式：virtual {method body}

  纯虚函数的定义形式：virtual { } = 0;

  在虚函数和纯虚函数的定义中不能有static标识符，原因很简单，被static修饰的函数在编译时候要求前期bind,然而虚函数却是动态绑定(run-time bind)，而且被两者修饰的函数生命周期(life recycle)也不一样。

* 虚函数必须实现，如果不实现，编译器将报错，错误提示为：

  error LNK****: unresolved external symbol "public: virtual void __thiscall
  ClassName::virtualFunctionName(void)"

* 如果一个类中含有纯虚函数，那么任何试图对该类进行实例化的语句都将导致错误的产生，因为抽象基类(ABC)是不能被直接调用的。必须被子类继承重载以后，根据要求调用其子类的方法。

* 多态性指相同对象收到不同消息或不同对象收到相同消息时产生不同的实现动作。C++支持两种多态性：编译时多态性，运行时多态性。
  a.编译时多态性：通过重载函数实现
  b 运行时多态性：通过虚函数实现。

# 3 模板类和类模板

### 1 基础的类模板

类模板，可以定义相同的操作，拥有不同数据类型的成员属性。

通常使用`template`来声明。告诉编译器，碰到`T`不要报错，表示一种泛型.

如下，声明一个普通的类模板

```cpp
template <typename T>
class Complex{
    
public:
    //构造函数
    Complex(T a, T b)
    {
        this->a = a;
        this->b = b;
    }
    
    //运算符重载
    Complex<T> operator+(Complex &c)
    {
        Complex<T> tmp(this->a+c.a, this->b+c.b);
        return tmp;
    }
        
private:
    T a;
    T b;
}

int main()
{
    //对象的定义，必须声明模板类型，因为要分配内容
    Complex<int> a(10,20);  
    Complex<int> b(20,30);
    Complex<int> c = a + b;
    
    return 0;
}


```



### 2 模板类的继承

在模板类的继承中，需要注意以下两点：

- 如果父类自定义了构造函数，记得子类要使用构造函数列表来初始化
- 继承的时候，如果子类不是模板类，则必须指明当前的父类的类型，因为要分配内存空间
- 继承的时候，如果子类是模板类，要么指定父类的类型，要么用子类的泛型来指定父类

```cpp

template <typename T>
class Parent{
public:
    Parent(T p)
    {
        this->p = p;
    }
    
private:
    T p;
};

//如果子类不是模板类，需要指明父类的具体类型
class ChildOne:public Parent<int>{
    
public:
    ChildOne(int a,int b):Parent(b)
    {
        this->cone = a;
    }
    
private:
    int cone;
};


//如果子类是模板类，可以用子类的泛型来表示父类
template <typename T>
class ChildTwo:public Parent<T>{
    
public:
    ChildTwo(T a, T b):Parent<T>(b)
    {
        this->ctwo = a;
    }
    
private:
    T ctwo;
};
```



# 4 线性表

基类声明

```cpp
// 线性表
template <typename E>
class List 
{
	private :
		void operator = (const List&){}
		List(const List&){}
	public:
		List(){};
		virtual ~List(){}
		
		virtual void clear() = 0; //纯虚函数后面跟 = 0
		
		virtual void insert(const E& item) = 0;
		
		virtual void append(const E& item) = 0;
		
		virtual E remove() = 0;
		
		virtual void moveToStart() = 0; 
		
		virtual void moveToEnd() = 0;
		
		virtual void prev() = 0;

		virtual void next() = 0;
		
		virtual int length () const = 0;
		
		virtual int currPos() const = 0;
		
		virtual void moveToPos(int pos) = 0;
		
		virtual const E& getValue() const = 0;
};
```
继承线性表

```cpp


template <typename E>
class AList : public List<E>
{
	private:
		int maxSize;
		int listSize;
		int curr;			//当前元素位置
		E*  listArray;		//全部元素指针
		
	public:
		AList(int size )
		{
			maxSize = size;
			listSize = curr = 0;
			listArray = new E[maxSize];
		 } 
		 
		 ~AList() {
		 	delete [] listArray;
		 }
		 
		 void clear()
		 {
		 	delete [] listArray;
		 	listSize = curr = 0;
		 	listArray = new E[maxSize];
		 }
		 
		 void insert(const E& it)
		 {
		 //	Assert(listSize < maxSize , "List capacity exceeded");
		 	
		 	for(int i = listSize; i>curr;i--)
		 	{
		 		listArray[i] = listArray[i-1];
			 }
			listArray[curr] = it;
			listSize++;
		 }
		 
		 void append(const E& it)
		 {
		 //	Assert(listSize < maxSize , "List capacity exceeded");
			listArray[listSize++] = it;		 	
		 }
		 
		 E remove()
		 {
		 	//Assert((curr>0) && (curr < listSize) , "No element");
			E it  = listArray[curr];
			for	(int i = curr; i<listSize-1 ; i++ )
			{
				listArray [i] = listArray[i+1];
			}
			listSize--;
			return it;
		 }
		 
		 void moveToStart(){	curr = 0;
		 }
		 
		 void moveToEnd(){	curr = listSize;
		 }
		 
		 void prev(){	if(curr!=0) curr--;
		 }
		 
		 void next(){	if(curr<listSize)curr++;
		 }
		 
		 int currPos() const{ return curr;}
		 int length() const{return listSize;}
		 void moveToPos(int pos)
		 {
		//	Assert((pos>=0)&&(pos<=listSize), "Out of range");
		 }
		 
		 const E& getValue() const{
		 //	Assert((curr>=0) && (curr<=listSize) , "No current element")
		 	return listArray[curr];
		 }
		 
};
		
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
```

**算法分析**

​	在线性表中**在表尾**插入和删除时很容易的。添减函数append的时间为O（1） 。 但是想要在开头插入一个元素所需要的时间就是O（n），其中n表示已有的元素个数。

​	大多数类AList的成员函数都是简单的访问表中元素，或者移动栅栏的问题，这样的操作只需要O（1）的时间，除了insert和remove以外，其他需要常数时间的操作是构造函数中、析构函数和clear函数。这三个函数使用了系统分配空间的new，delete，系统分配和释放空间的代价是非常大的。



# 5 链表

```cpp
#include <iostream>
using namespace std;
//线性表基类 
template <typename E>
class List 
{
	private :
		void operator = (const List&){}
		List(const List&){}
	public:
		List(){};
		virtual ~List(){}
		
		virtual void clear() = 0; //纯虚函数后面跟 = 0
		
		virtual void insert(const E& item) = 0;
		
		virtual void append(const E& item) = 0;
		
		virtual E remove() = 0;
		
		virtual void moveToStart() = 0; 
		
		virtual void moveToEnd() = 0;
		
		virtual void prev() = 0;

		virtual void next() = 0;
		
		virtual int length () const = 0;
		
		virtual int currPos() const = 0;
		
		virtual void moveToPos(int pos) = 0;
		
		virtual const E& getValue() const = 0;
};

template <typename E>
class Link{
public:
	E element;
	
	Link *next;
	//函数重载，一个是没有元素参数的，一个是有函数参数的 
	Link (const E& eleval, Link* nextval = NULL){
		element = eleval;
		next = nextval;
	}
	
	Link (Link* nextval = NULL){
		next = nextval;
	}
}; 

template <typename E>
class LList : public List<E> {
private:
	Link<E>* head;
	Link<E>* tail;
	Link<E>* curr;
	int cnt;
	
	void init(){
		curr = tail = head = new Link<E>;
		cnt = 0;
	}
	
	void removeall(){
		while(head != NULL){
			curr  = head ;
			head = head -> next;
			delete curr;
		}
	}
	
public:
	LList(int size = 19){
		init();
	}
	
	~LList(){
		removeall();
	}
	void print();
	
	void clear(){
		removeall();
		init();
		
	}
	
	void insert(const E& it){
		//重点：创建新节点的时候，新节点指针指向当前节点的下一个，而new函数返回的新节点指针赋值给当前节点。
		curr->next = new Link<E>(it, curr->next);  
		if(tail == curr ) tail = curr->next;
		cnt ++;
	}
	
	//append 在末尾插入元素，与insert不同之处在于下一个指针位置不同。 
	void append (const E& it){
		tail = tail->next = new Link<E> (it,NULL);
		cnt ++;
	} 
	
	E remove()
	{
		//Assert(curr->next != NULL, "No elements" );
		//用it取出当前元素的数值，新建一个Itemp来链接当前元素的下一个元素 
		E it  = curr -> next -> element;
		Link<E>* Itemp = curr -> next;
		if (tail == curr->next){
			tail = curr;
		}
		curr -> next = Itemp -> next;
		delete Itemp;
		cnt --;
		return it;
	}
	
	void moveToStart(){
		curr = head;	
	}
	
	void moveToEnd(){
		curr = tail;
	}
	
	void prev(){
		if(curr == head) return ;
		Link<E>* temp = head;
		//单向链表的缺点，前驱只能遍历查找 
		while(temp -> next !=curr)temp = temp->next;
		curr = temp;
	}
	
	void next(){
		if(curr -> next != tail) curr = curr->next;
	} 
	
	int length() const {return cnt;}
	
	int currPos() const{
		Link<E>* temp = head;
		int i;
		for(i = 0 ; curr!=temp;i++)
		{
			temp = temp->next;
		}
	}
	
	void moveToPos(int pos){
		curr = head;
		for(int i=0;i<pos;i++) curr = curr->next;
	}
	
	const E& getValue() const{
		//Assert
		return (curr->next->element
		);
		
	}	
	
};

template<typename E>
void LList<E>::print(){
	while((curr -> next )!=NULL)
	{
		cout<< curr->next->element <<" ";
		curr = curr -> next;
	}
}


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
```

# 6 可利用空间表

​	C++空闲存储空间管理的分配操作**new** 和**delete**相对来说较难使用，在后面我们将提到一种通用存储管理器的工作方式，存储的分配和回收必须精良处理非固定模式的分配和回收需求，这些需求所要求的内存大小太悬殊，从而造成了大量的负担。而可利用空间表相当于其它表来说，更教的高效。

​	在链表创建和删除节点时，Link类应当可以管理自己的可利用空间表（freelist），以取代系统级的存储分配和删除任务。可利用空间表存放当前那些不用的线性表节点，从一个链表中删除的节点就可以放到可利用空间表的首端。当需要把一个新元素添加到链表中的时候，先检查可利用空间表，如果有空节点就直接使用，不够的时候才会采用new创建新的节点。

​	我们采用c++的操作符重载来完成这个工作，好处是对List类不作任何修改就可以享受可利用空间表带来的便利。

​	利用空间表来重载标准存储和分配空间操作符，重新得到的LINK类。

```cpp
//重载空间表
template<typename E>
class Link{
	private:
		static Link<E>* freelist;		//Reference for freelist head
	public:
		E element;
		Link* next;
		
		//Constructor
		Link(const E& elemval,Link* nextval ==NULL){
			element = eleval;
			next = nextval;
		}
		
		Link(Link* nextval = NULL){
			next = nextval;
		}
		
		void * operator  new(size_t){
			if(freelist == NULL) return ::new Link;
			Link<E> temp = freelist;
			freelist = freelist->next;
			return temp;
		}
		
		void operator delete(void* ptr){
			((Link<E>*)ptr) -> next = freelist;
			freelist = (Link<E>&) ptr;
		}
		
}; 
// The freelist head pointer is actually created here
template <typename E>
Link<E>* Link<E>::freelist = NULL;

```

​	注意到我们后面在创建新空间的适合，如果空间表没有，就需要用重载前的new操作来分配动态内存（堆内存），这个时候就需要使用：：new，这表示我们要使用原生的new，而不是Link类重载的new，否则的话会陷入死循环。

​	同时我们在创建freelist的时候使用了static语句，作为静态区域，他可以被所有的类实例共享。

# 7 栈

​	栈stack是限定仅在一端进行插入或删除操作的线性表。

**顺序栈**

```cpp
#include<iostream>
#define defaultSize 10
//stack's ADT
template <typename E>
class Stack{
	private:
		
		
	public:
		Stack(){};
		~Stack(){};
		
		virtual void clear()=0 ;
		
		virtual void push(const E& it) = 0;
		
		virtual E pop() = 0;
		
		virtual const E& topValue() = 0;
		
		virtual int length() const = 0;
}; 


template <typename E>
class AStack :public Stack<E>{
	private:
		int maxSize;
		int top;
		E* listArray;
		
	public:
		AStack(int size = defaultSize){
			maxSize = size;
			top = 0;
			listArray = new E[size];
		}
		
		~AStack(){
			top = 0;
			maxSize = 0;
			delete [] listArray;
		}
		
		void clear(){
			top = 0;
		}
		
		void push(const E& it){
			listArray[top++] = it;	
		}
		
		E pop(){
			return listArray[top--];
		}
		
		const E& topValue(){
			return listArray[top-1];
		}
		
		int length()const {
			return top;
		}
};
int main(){
	
	AStack<int> stk1;
	stk1.push(10);
	int l = stk1.length();
	int ele = stk1.topValue(); 
	cout<<l<<" "<<ele<<endl;
	
	return 0;
}

```

**链式栈**

先码着吧。



# 8 队列

先留着吧 ，把树先学了



# 9 二叉树

​	前面我们讲到的线性表都有一个基本的限制：要么检索速度快，不宜与插入和删除；要么易于插入和删除，检索速度满。对于已有的数据，树结构能够进行搞笑的创建和更新，尤其是二叉树，对于搜索应用有很大的帮助。我们之前学习的算法很多都是基于二叉树，例如深度优先搜索，广度优先搜索，他们帮助我们解决问题的时候都有很大的帮助。

## 9.1 定义与基本特性

​	一棵二叉树由节点和有限集合组成，这个集合可以为空，可以只有一个根节点，和两个不相交的子树构成。

​	一连串的节点满足节点$n_i 是 n_{i+1}的父节点$，那么这一连串的节点就是一条路径。如果一条路径从节点R到节点M，那么这个R就是他们的祖先，M是子孙（descendant）。路径的长度是节点数k的k-1

​	节点M的深度就是从根节点到M的路径程度，k-1 。树的高度等于最深的深度加1 。根节点为第0层。

​	没有非空子树的节点称为叶子节点，至少有一个非空子树节点叫做分支节点或者内部节点。

​	**满二叉树**是指每一个分支节点都有两个非空子树，其他的节点都是叶子节点。

​	**完全二叉树**是指从根节点开始每一层都由左到右填充。一颗高度为d的完全二叉树除了d-1层外，其他的每一层都是满的。

​	后续将要提到的**堆数据结构**就是一颗完全二叉树。而**Haffman树**则是一颗满二叉树。

### 9.1.1 满二叉树定理

​	某些二叉树的实现，由叶节点存储数据结构，分支节点存储结构信息。更一般的，二叉树的实现需要一定的空间来存储分支节点。这个空间的大小可能与存储的空间不同。

​	为了分析空间代价，知道一颗具有n各分支几点的二叉树的叶节点在全部节点中可能的最小与最大比例是十分有用的。一课具有n各分支节点的二叉树可能只有一个叶子，这样就类似一个链表。

​	我们自然的可以联想到用满二叉树来限定，因为任何由n各分支节点的满二叉树纵有相同的叶节点。

**定理9.1**：非空满二叉树的叶子节点数等于其分支节点数加一。

**定理9.2**：非空二叉树空子树的数目等于其节点数目加一。

### 9.1.2 二叉树的抽象数据类型



​	