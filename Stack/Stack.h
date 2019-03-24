/* Stack.cpp
 *
 * Author: xblin
 */

#ifndef __Stack_H
#define __Stack_H

#include <iostream>

using namespace std;

/*** 栈的数据结构 ***/
template<typename T>
struct stack{
	T *base;
	T *top;
};


template<typename T>
class Stack{

public:
	Stack(const int size) :_size(size), _s(new stack<T>) {
		_s->base = new T[size];
		_s->top = _s->base;
	}
	~Stack() { delete[] _s->base; delete _s; }
	void push(const T);
	void pop();
	T top();
	bool empty();

private:
	stack<T> *_s;
	int _size;
};

template<typename T>
void Stack<T>::push(const T data){
	
	if((_s->top - _s->base) >= _size){
		cout << "Stack Overflow" << endl;
		return;
	}

	*(_s->top++) = data;
}

template<typename T>
void Stack<T>::pop(){

	if(_s->top == _s->base){
		cout << "Stack is empty!" << endl;
		return;
	}
	_s->top--;
}

template<typename T>
T Stack<T>::top(){
	
	if(_s->top == _s->base){
		cout << "Stack is empty!" << endl;
		return 0;
	}
	return *(_s->top - 1);
}

template<typename T>
bool Stack<T>::empty(){
	
	if(_s->top == _s->base)
		return 1;
	else
		return 0;
}


/*
int main(int argc, char *argv[]){

	Stack<int> s(9);
	cout << s.empty() << endl;
	s.push(2);
	cout<<s.top()<<endl;
	s.push(4);
	cout<<s.top()<<endl;
	s.push(6);
	cout<<s.top()<<endl;
	s.push(8);
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	cout << s.empty() << endl;
	
	return 0;
}
*/

#endif
