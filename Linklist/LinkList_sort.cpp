/* LinkList_sort.cpp
 *
 * Author: xblin
 */

#include <iostream>

using namespace std;

struct LNode{

	int data;
	LNode *next;
	LNode(int _data) : data(_data), next(nullptr) {}
};

/*
class LinkList{


};
*/

LNode *ListSort(LNode *L1, LNode *L2){

	LNode *head = new LNode(0);
	LNode *tmp = head; //to save the head Node

	if(L1 == nullptr && L2 == nullptr){  //L1 & L2 empty
		return head;
	}

	while(L1!=nullptr && L2!=nullptr) {  //only one empty
	
		if((L1->data < L2->data) && L1){ 
			tmp->next = L1;
			tmp = L1;
			L1 = L1->next;
		}
		if((L1->data > L2->data) && L2){ 
			tmp->next = L2;
			tmp = L2;
			L2 = L2->next;
		}	
	}
	return head->next; //head->next Lnode 
}

int main(int argc, char *argv[]){

	LNode node11(1);
	LNode node12(4);
	LNode node13(7);
	LNode node14(8);
	LNode node21(2);
	LNode node22(3);
	LNode node23(5);
	LNode node24(6);
	
	node11.next = &node12;
	node12.next = &node13;
	node13.next = &node14;
	node21.next = &node22;
	node22.next = &node23;
	node23.next = &node24;
	
	LNode *L1 = &node11; 
	LNode *L2 = &node21;
//	LNode *L1 = nullptr; //case empty
//	LNode *L2 = nullptr; //case empty

	LNode *p = ListSort(L1, L2);
	while(p != nullptr){
		cout << p->data << endl;
		p = p->next;
	}
	return 0;
}
