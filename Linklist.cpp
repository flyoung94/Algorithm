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
	LNode *tmp = L; for(int i=0; i<size; i++){
		LNode *p = new(LNode);
		p->data = n;
		tmp->next = p;
		tmp = p;
	}
}

void Linklist::print(const int size){
	LNode *tmp = L;
	for(int i=0; i<size; i++){
		tmp = tmp->next;
		cout << tmp->data << endl;
	}
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
	L.print(8);
//	L.print(8);
	return 0;
}
