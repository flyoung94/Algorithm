/* filename: BSTree.h
*
* Author:   xblin
*/

#ifndef __LINKLIST_H
#define __LINKLIST_H

#include <iostream>

/* ���������ݽṹ */
using namespace std;

#define ERROR 1
#define OK 0

typedef int ElemType;
typedef char Status;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;


void CreateList_L(LinkList &L, int n);
void CreateList_Forward(LinkList &L, int n);
Status GenElem_L(LinkList L, int i, ElemType &e);
Status ListInsert_L(LinkList &L, int i, ElemType e);    //����L����ַ
Status ListDelete_L(LinkList &L, int i);
#endif // !__LINKLIST_H


