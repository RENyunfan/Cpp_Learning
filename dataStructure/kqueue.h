#include<iostream>
using namespace std;

template <typename E>
class Queue<E>{
	private:
		
	public:
		Queue(){};
		~Queue(){};
		
		virtual void clear() = 0;
		
		virtual void enqueue()(const E& it) = 0;
		
		virtual void E dequeue() = 0;
		
		virtual const E& frontValue() const = 0;
		
		virtual int length() const = 0 ; 
}; 

template <typename E>
class 
