/* Linklist.cpp 
 *
 * Author: xblin
 */

#include <iostream>

using namespace std;

typedef int ElemType;

struct LNode{
	ElemType data;	
	LNode *next;
};

class Linklist{

public:
	Linklist();
	~Linklist();
	void create_linklist(ElemType n, const int size);
	void print(const int size);
	//void insert(const int local, const int num);
	void back_sort(const int size); //逆序排序

private:
	LNode *L;	
};

Linklist::Linklist(){
	L = new(LNode);
	L->data = 0;
	L->next = nullptr;
} 

Linklist::~Linklist(){
	delete L;
}

void Linklist::create_linklist(ElemType n, const int size){
	LNode *tmp = L; 
	for(int i=0; i<size; i++){
		LNode *p = new(LNode);
		p->data = i;
		tmp->next = p;
		tmp = p;
	}
//	tmp->next = nullptr; //尾结点指向nullptr
}

void Linklist::print(const int size){
	LNode *tmp = L;
	for(int i=0; i<size; i++){
		tmp = tmp->next;
		cout << tmp->data << endl;
	}
}

void Linklist::back_sort(const int size){
	LNode *new_L = nullptr;
	LNode *tmp = nullptr;
	L = L->next; //初始化指向头结点的next

	//for(int i=0; i<size-1; i++){
	while(L != nullptr){
		tmp = L->next;
		L->next = new_L;
		new_L = L;
		L = tmp;
	}
	LNode *head = new(LNode);
	head->data = 0;
	head->next = new_L;
	L = head;

}

/*
void Linklist::insert(const int local, const int num){
	
	LNode *tmp = L;
	LNode *p = new(LNode);		
	p->data = num;
	
	for(int i=0; i<local-1; i++){
		tmp = tmp->next;
	}

}
*/

int main(int argc, char *argv[]){
	
	Linklist L;
	L.create_linklist(8, 8);
	L.back_sort(8);
	L.print(8);
//	L.print(8);
	return 0;
}
