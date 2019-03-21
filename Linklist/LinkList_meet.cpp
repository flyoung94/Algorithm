/* Leetcode 160
 *
 * 求两个链表的交点
 */

#include <iostream>
#include <set>

using namespace std;


struct LNode{
	int data;
	LNode *next;
	LNode(int x) : data(x), next(nullptr) {}
};


class Solution{

public:
	LNode *getIntersectionNode(LNode *A, LNode *B){ //暴力求解
		
		LNode *a = A;
		LNode *b = B;
	
		while(a != nullptr){
			
			while(b != nullptr){
				if(b == a)
					return b;
				b = b->next;
			}
			
			b = B;
			a = a->next;
		}

		return nullptr;
	}

	LNode *getIntersectionNode1(LNode *A, LNode *B){  //using set
		
		std::set<LNode *> node_set;
		while(A != nullptr){
			node_set.insert(A);
			A = A->next;
		}
		while(B != nullptr){
			if (node_set.find(B) != node_set.end()){
				return B;
			}
			B = B->next;
		}
		return nullptr;
	}

	LNode *getIntersectionNode2(LNode *A, LNode *B){ //长度之差
		int lenth_A = 0;
		int lenth_B = 0;

		LNode *a = A;
		LNode *b = B;

		while( a != nullptr){
			lenth_A++;
			a = a->next;
		}
		while( b != nullptr){
			lenth_B++;
			b = b->next;
		}
		cout << lenth_A << "&" << lenth_B << endl;
	
		if(lenth_A > lenth_B) {
			for(int i=0; i < (lenth_A - lenth_B); i++)
				A = A->next;
		}
		else{
			for(int i=0; i< (lenth_B - lenth_A); i++){
				B = B->next;
			}

		}

		while(A != nullptr){
			if( A == B) 
				return A;
			A = A->next;
			B = B->next;
		}

	return nullptr;
	}
	
};


int main(int argc, char *argv[]){

	LNode a1(1);
	LNode a2(2);
	LNode b1(3);
	LNode b2(4);
	LNode b3(5);
	LNode c1(6);
	LNode c2(7);
	LNode c3(8);

	a1.next = &a2;
	a2.next = &c1;
	c1.next = &c2;
	c2.next = &c3;
	b1.next = &b2;
	b2.next = &b3;
	b3.next = &c1;

	c3.next = nullptr;

	Solution solve;

	LNode *result = solve.getIntersectionNode1(&a1, &b1);
	cout << result->data << endl;
	
	return 0;
}
