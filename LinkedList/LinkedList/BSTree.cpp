/* filename: BSTree.cpp
 *
 * Author:   xblin
 */

#include "BSTree.h"

/* �������ݹ����key, ����BSNode */
BSTree SearchBST(BSTree Tree, int e){
	if (Tree == NULL || Tree->data.key == e)
		return Tree;

	if (e < Tree->data.key)
		return SearchBST(Tree->left, e);
	
	else
		return SearchBST(Tree->right, e);
}

/* �������������������� */
void InorderBST(BSTree Tree){
	if (Tree != NULL){
		InorderBST(Tree->left);
		cout << Tree->data.key << endl;
		InorderBST(Tree->right);
	}
}

/* �������������� */
Status InsertBST(BSTree &Tree, ElemType Key){
	BSTree pNode = Tree;
	BSTree tmpNode = NULL;  //���Insert�ĸ���� 

	BSTree sNode = (BSTree)malloc(sizeof(BSNode));
	//BSTree sNode = NULL;   //malloc��NULL������
	sNode->data.key = Key;
	sNode->left = NULL;    //���ʼ��NULL
	sNode->right = NULL;
	sNode->parent = NULL;

	if (Tree == NULL){
		Tree = sNode;
		return OK;
	} 

	while (pNode != NULL){   
		tmpNode = pNode;   //��¼pNode=NULL �ĸ����
		if (Key < pNode->data.key)
			pNode = pNode->left;    
			
		else
			pNode = pNode->right;
	}
	
	sNode->parent = tmpNode;
	if (sNode->data.key < tmpNode->data.key)
		tmpNode->left = sNode;
	else
		tmpNode->right = sNode;

	return OK;
}

/* ����������ɾ�� ������� */
Status DeleteBST(BSTree &Tree, ElemType key){

	//BSTree sNode = (BSTree)malloc(sizeof(BSNode));
	//sNode->data.key = key;
 	BSTree sNode = SearchBST(Tree, key); //���ҽ��
	
	if (sNode->left == NULL){
		if (sNode->parent == NULL)
			Tree = sNode->right;
		else if (sNode == sNode->parent->left){

			cout << "dfa" << endl;
			sNode->parent->left = sNode->right;
		}
		else
			sNode->parent->right = sNode->right;
		
		if (sNode->right != NULL)  //��ֹ�ڴ�й©
			sNode->right->parent = sNode->parent; 
	} 
	if (sNode->right == NULL){
		if (sNode->parent == NULL)
			Tree = sNode->left;
		else if (sNode == sNode->parent->left)
			sNode->parent->left = sNode->left;
		else
			sNode->parent->right = sNode->left;

		if (sNode->left != NULL)   //��ֹ�ڴ�й©
			sNode->left->parent = sNode->parent;
	} 

	else{   //���Һ��Ӷ���Ϊ��

		BSTree pNode = sNode->right;

		while (pNode->left != NULL){
			pNode = pNode->left;   //��sNode�ĺ��Ԫ��
		}
		if (pNode->right == NULL){
			pNode->parent->left = NULL; //�ȶ�������
			pNode->parent = sNode->parent;
			pNode->right = sNode->right;
		}
		else {
			if (pNode->parent != sNode){
				pNode->right->parent = pNode->parent;
				pNode->parent->left = pNode->right;
			}
			
			if (sNode == sNode->parent->left)
				sNode->parent->left = pNode;
			else
				sNode->parent->right = pNode;
			pNode->left = sNode->left;
			pNode->right = sNode->right;
		}
		
	}
	free(sNode);  //�ͷ��ڴ�

	return OK;
}
/*
int main(int argv, char **argc){
	BSTree Tree = NULL;
	InsertBST(Tree, 6);
	InsertBST(Tree, 2);
	InsertBST(Tree, 1);
	InsertBST(Tree, 5);
	InsertBST(Tree, 3);
	InsertBST(Tree, 4);
	InorderBST(Tree);
	cout << "endl" << endl;
	DeleteBST(Tree, 2);  //������
	InorderBST(Tree);
//	BSTree aa = SearchBST(Tree, 6);
}
*/