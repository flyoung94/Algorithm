/* BSTree.cpp
 *
 * Author: xblin
 */

#include <iostream>

using namespace std;


struct BSNode{
	
	int key;
	BSNode *left;
	BSNode *right;
	BSNode *parent;
};

class BSTree{

public:
	BSTree() : _bstree(nullptr) {}
	~BSTree();
	void bstree_insert(const int key);
	void print();

private:
	BSNode *_bstree;
	void InorderBST(BSNode *bstree);
};


BSTree::~BSTree(){
	delete _bstree;
}

void BSTree::bstree_insert(const int key){ 
	BSNode *bstree = _bstree;
	BSNode *sNode= new(BSNode);
	BSNode *tmpNode;
	sNode->key = key;
	sNode->left = nullptr;
	sNode->right = nullptr;
	sNode->parent = nullptr;

	if(bstree == nullptr){ // if the tree is empty
		_bstree = sNode;  //should be _bstree
	}

	else{
		while(bstree != nullptr){
			tmpNode = bstree;
			if(key < bstree->key){
				bstree = bstree->left;	
			}	
			else
				bstree = bstree->right;
		}
		sNode->parent = tmpNode;
		if(sNode->key < tmpNode->key)
			tmpNode->left = sNode;
		else
			tmpNode->right =sNode;
	}
}


void BSTree::InorderBST(BSNode *bstree){ //中序遍历
	if(bstree != nullptr){
		InorderBST(bstree->left);
		cout << bstree->key << endl;
		InorderBST(bstree->right);
	}	
}

void BSTree::print(){
	InorderBST(_bstree);
}


int main(int argc, char *argv[]){

	BSTree bstree;
	bstree.bstree_insert(6);
	bstree.bstree_insert(5);
	bstree.bstree_insert(4);

	bstree.print();
	return 0;
}




