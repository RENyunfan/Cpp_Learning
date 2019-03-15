#include <iostream>
using namespace std;
//���Ա���� 
template <typename E> 
class List 
{
	private :
		void operator = (const List&){}
		List(const List&){}
	public:
		List(){};
		virtual ~List(){}
		
		virtual void clear() = 0; //���麯������� = 0
		
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
/*
//����ڵ����� 
template <typename E>
class Link{
public:
	E element;
	
	Link *next;
	//�������أ�һ����û��Ԫ�ز����ģ�һ�����к��������� 
	Link (const E& eleval, Link* nextval = NULL){
		element = eleval;
		next = nextval;
	}
	
	Link (Link* nextval = NULL){
		next = nextval;
	}
}; 
*/

//���ؿռ��
template<typename E>
class Link{
	private:
		static Link<E>* freelist;		//Reference for freelist head
	public:
		E element;
		Link* next;
		
		//Constructor
		Link(const E& elemval,Link* nextval =NULL){
			element = elemval;
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

//���������� 
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
	void print(){
		while((curr -> next )!=NULL)
	{
		cout<< curr->next->element <<" ";
		curr = curr -> next;
	} 
	} 
	
	void clear(){
		removeall();
		init();
		
	}
	
	void insert(const E& it){
		//�ص㣺�����½ڵ��ʱ���½ڵ�ָ��ָ��ǰ�ڵ����һ������new�������ص��½ڵ�ָ�븳ֵ����ǰ�ڵ㡣
		curr->next = new Link<E>(it, curr->next);  
		if(tail == curr ) tail = curr->next;
		cnt ++;
	}
	
	//append ��ĩβ����Ԫ�أ���insert��֮ͬ��������һ��ָ��λ�ò�ͬ�� 
	void append (const E& it){
		tail = tail->next = new Link<E> (it,NULL);
		cnt ++;
	} 
	
	E remove()
	{
		//Assert(curr->next != NULL, "No elements" );
		//��itȡ����ǰԪ�ص���ֵ���½�һ��Itemp�����ӵ�ǰԪ�ص���һ��Ԫ�� 
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
		//���������ȱ�㣬ǰ��ֻ�ܱ������� 
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


//˳����� 
template <typename E>
class AList : public List<E>
{
	private:
		int maxSize;
		int listSize;
		int curr;			//��ǰԪ��λ��
		E*  listArray;		//ȫ��Ԫ��ָ��
		
	public:
		AList(int size  = 10)
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
	
