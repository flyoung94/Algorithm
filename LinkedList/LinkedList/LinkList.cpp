/* filename: LinkList.cpp
 *
 * Author:   xblin
 */

#include "LinkList.h"


/********** ������������ ***************/
void CreateList_L(LinkList &L, int n){
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	
	for (int i = n; i > 0; i--){
		LinkList p;
		p = (LinkList)malloc(sizeof(LNode));
		p->data = i;
		p->next = L->next;
		L->next = p;
	}
}

/********** ˳���������� ***************/
void CreateList_Forward(LinkList &L, int n){
	L = (LinkList)malloc(sizeof(LNode));
	LinkList tmp = L;
	
	for (int i = 0; i < n; i++){
		LinkList p;
		p = (LinkList)malloc(sizeof(LNode));
		p->data = i;
		p->next = nullptr;
		tmp->next = p;
		tmp = p;
	}
	
}

/********** ������Ĳ�ѯi ***************/
Status GenElem_L(LinkList L, int i, ElemType &e){
	for (int j = i; j > 0; j--){
		L = L->next;
	}
	if (!L)
		return ERROR;

	e = L->data;
	return OK;
}


/********** ������Ĳ��� ***************/
Status ListInsert_L(LinkList &L, int i, ElemType e){    //����L����ַ

	LinkList p = L;        //ͷ���L�����ƶ�

	for (int j = i - 1; j > 0; j--)  //���ҵ�i-1�����
		p = p->next;
	if (!p)
		return ERROR;

	LinkList s = (LinkList)malloc(sizeof(LNode));  //sΪҪ����Ľ��
	s->data = e;
	s->next = p->next;         //�Ⱥ�˳��ע��
	p->next = s;

	return OK;
}

/********** �������ɾ�� ***************/
Status ListDelete_L(LinkList &L, int i){
	LinkList p = L;

	for (int j = i-1; j > 0; j--)
		p = p->next;
	if (!p)
		return ERROR;

	LinkList q = p->next;  //q�Ǳ�ɾ���Ľ��
	p->next = p->next->next;
	free(q);    //�ͷ�ɾ���Ľ��q

	return OK;
}


int main(int argv, char **argc){

	LinkList L;
	CreateList_Forward(L, 9);

	//ListInsert_L(L, 4, 16);
	ListDelete_L(L, 4);

	for (int i = 0; i < 8; i++){    //���������
		L = L->next;
		cout << L->data << endl;
	}
	
//	int e=0;
//	GenElem_L(L, 6, e);   //��ѯ��6��Ԫ��
//	cout << e << endl;
}


