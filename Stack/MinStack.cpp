/* MinStack.cpp 
 *
 * Leetcode-155
 * 返回栈内最小元素,且O(1)
 *
 * Author: xblin
 */

#include <iostream>
#include <stack>

using namespace std;


class MinStack{

public:
	MinStack(){}
	void push(const int data);
	void pop();
	int getMin();

private:
	std::stack<int> _data; //stl标准库中的栈
	std::stack<int> _min;  //stl标准库中的栈

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


