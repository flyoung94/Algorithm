/* MinStack_self.cpp 
 *
 * Leetcode-155
 * 返回栈内最小元素,且O(1)
 *
 * Author: xblin
 */

#include <iostream>
#include "Stack.h"

using namespace std;


class MinStack{

public:
	MinStack() : _data(10), _min(10) { }
	void push(const int data);
	void pop();
	int getMin();

private:
	Stack<int> _data; //自定义的栈
	Stack<int> _min;  //自定义的栈

};

void MinStack::push(const int data){

	_data.push(data);

	if(_min.empty())
		_min.push(data);
	else if(data < _min.top())
		_min.push(data);
	else
		_min.push(_min.top());
}

void MinStack::pop(){
	
	_data.pop();
	_min.pop();
}

int MinStack::getMin(){

	return _min.top();
}

int main(int argc, char *argv[]){

	
	MinStack s;
	s.push(2);
	cout << s.getMin() << endl;
	s.push(1);
	cout << s.getMin() <<endl;
	s.push(3);
	cout << s.getMin() << endl;
	s.push(-1);
	cout << s.getMin() << endl;

	s.pop();
	cout << s.getMin() << endl;
	
	return 0;
}
