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

