/* Reverse.cpp
 *
 * Author: linxubin
 */

#include <iostream>

using namespace std;

struct LNode{  //数据结构单链表
	int data;
	LNode *next;
	LNode(int _data) : data(_data), next(nullptr) {}
};

class Reverse{

public:
	LNode *reverse(LNode *head){  //需要返回一个头结点
		LNode *tmpNode = nullptr;
		LNode *nextNode = nullptr;
		while(head != nullptr){
			nextNode = head->next;
			head->next = tmpNode;
			tmpNode = head;
			head = nextNode;
		}
		return tmpNode;
	}

};


int main(int argc, char *argv[]){  //测试case
	
	LNode node1(1);
	LNode node2(2);
	LNode node3(3);
	LNode node4(4);

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	//node4.next = nullptr;
	LNode *head = &node1;
	Reverse rev;

	head = rev.reverse(head);

	while(head != nullptr){
		cout << head->data << endl;
		head = head->next;
	}

	return 0;
}


