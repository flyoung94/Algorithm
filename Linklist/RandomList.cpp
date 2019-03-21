/* Leetcode-138
 *
 * 深度拷贝链表
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct LNode{

	int data;
	LNode *next;
	LNode *random;
	LNode(int x) : data(x), next(nullptr), random(nullptr) {}
};


class Solution{

public:
	LNode *randomList(LNode *L){
	
		LNode *ptr = L;

		vector<LNode *> new_node;  //vector存放新结点地址
		map<LNode *, int> old_addr; //map存旧结点random对应的地址序列映射关系

		int i = 0;

		while(ptr != nullptr){
			new_node.push_back(new LNode(ptr->data));
			old_addr[ptr] = i++;
			ptr = ptr->next;
		}

		ptr = L;
		i = 0;

		while(ptr != nullptr){
			new_node[i]->next = new_node[i+1];
			if(ptr->random != nullptr){
				int id = old_addr[ptr->random];
				new_node[i]->random = new_node[id];
			}
			i++;
			ptr = ptr->next;
		}

		return new_node[0];
	}
};


int main(int argc, char *argv[]){

	LNode a(1);
	LNode b(2);
	LNode c(3);
	LNode d(4);
	LNode e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	a.random = &c;
	b.random = &d;
	c.random = &c;
	e.random = &d;

	Solution solve;

	LNode *rnode = solve.randomList(&a);

	while(rnode != nullptr){
	
		cout << "data:" << rnode->data << endl;

		if(rnode->random != nullptr){
			cout << "random:" << rnode->random->data << endl;
		}
		else
			cout << "random: nullptr" << endl;
		rnode = rnode->next;
	}

	return 0;
}
