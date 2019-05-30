/* sumTwo.cpp
 *
 * Author: xblin
 */

#include <iostream>

using namespace std;

struct LNode{
	int data;
	LNode *next;
	LNode(int _data) : data(_data),next(nullptr) {}
};


class Solution{

public:
	LNode *numsSum(LNode *l1, LNode *l2){
		int sum;
		int flag = 0;
		LNode *resNode = nullptr;
		while(l1!=nullptr && l2!=nullptr){
			while(l1!=nullptr || l2!=nullptr){
				sum = l1->data + l2->data;
				if(sum > 9){
					flag = 1;	
				}
				else
					flag = 0;
				LNode tmpNode(res%10);
			}
			if(l1==nullptr){
			
			}
		
		}
	}
}

int main(int argc, char *argv[]){
	
	LNode a0(2);
	LNode a1(4);
	LNode a2(3);

	a0.next = a1;
	a1.next = a2;

	LNode b0(5);
	LNode b1(6);
	LNode b2(4);

	b0->next = b1;
	b1->next = b2;

	LNode *l1 = &a0;
	LNode *l2 = &b0;

	Solution solve;
	LNode *res = solve.numsSum(l1, l2);

	while(res!=nullptr){
		cout << res->data << endl;
		res = res->next;
	}

	return 0;
}

