/* CQueue.cpp
 *
 * 栈实现队列
 *
 * Author: xblin
 */

#include <iostream>
#include <stack>

using namespace std;

template<typename T> 
class CQueue{

public:
	void push(T elem);
	T pop();

private:
	stack<T> s1;
	stack<T> s2;
};

template<typename T> void CQueue<T>::push(T elem){
	s1.push(elem);
}

template<typename T> T CQueue<T>::pop(){
	if(s2.size() == 0){
		while(s1.size() > 0){
			T data = s1.top();
			s1.pop();
			s2.push(data);
		}
	}
	if(s2.size() == 0){
		cout << "stack is empty!";
		return -1;
	}
	int elem = s2.top();
	s2.pop();
	return elem;
}

int main(int argc, char *argv[]){

	CQueue<int> cqueue;
	cqueue.push(9);
	cqueue.push(8);
	cqueue.push(7);
	cqueue.push(6);

	for(int i=0; i<6; i++) {
		int elem = cqueue.pop();
		cout << elem << endl;
	}

	
	return 0;
}


