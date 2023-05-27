#include "BST.h"
#include <iostream>
#include <iomanip>
using namespace std;
void BST::helpDestroy(binNode* node) {// delete from bottom to top
	if (node != 0) {
		helpDestroy(node->lchild);
		helpDestroy(node->rchild);
		delete node;
	}
}
BST::binNode* BST::helpCopy(binNode* node) {
	if (node != 0) {
		binNode* temp = new binNode(node->value);
		temp->lchild = helpCopy(node->lchild);
		temp->rchild = helpCopy(node->rchild);
		return temp;
	}
	return 0;
}
void BST::helpDisplay(ostream& out,int indent, binNode* node) {
	if (node != 0) {
		helpDisplay(out, indent + 6, node->lchild);
		out << setw(indent) << node->value << endl;
		helpDisplay(out, indent + 6, node->rchild);
	}
}
int BST::helpcount(binNode* node) {
	if (node != 0)return(1 + helpcount(node->lchild) + helpcount(node->rchild));
	else return 0;
}
void BST::helpInorder(binNode* node) {
	if (node != 0) {
		helpInorder(node->lchild);
		cout << " " << node->value;
		helpInorder(node->rchild);
	}
}
void BST::helpPostorder(binNode* node) {
	if (node != 0) {
		helpInorder(node->lchild);		
		helpInorder(node->rchild);
		cout << " " << node->value;
	}
}
void BST::helpPreorder(binNode* node) {
	if (node != 0) {
		cout << " " << node->value;
		helpInorder(node->lchild);
		helpInorder(node->rchild);	
	}
}
void BST::helpMirror(binNode* node) {
	if (node != 0) {
		binNode* temp;
		helpMirror(node->lchild);
		helpMirror(node->rchild);
		temp = node->lchild;
		node->lchild = node->rchild;
		node->rchild = temp;
	}
}
int BST::helpLevel(binNode* node, int item, int level) {
	if (node == 0) cout << "Item does not exist\n";
	else if (item > node->value) return(helpLevel(node->rchild, item, level + 1));
	else if (item < node->value) return(helpLevel(node->lchild, item, level + 1));
	else return level;
}
int BST::helpHeight(binNode* node) {
	if (node == 0) {
		return -1;
	}
	else {
		return(1 + max(helpHeight(node->lchild), helpHeight(node->rchild)));
	}
}

int BST::helpLeaf(binNode* node){
	if (node == 0) {
		return 0;
	}
	if (node->lchild == 0 && node->rchild == 0) return 1;
	else return(helpLeaf(node->lchild) + helpLeaf(node->rchild));

}
bool BST::helpBST(binNode* node,int min,int max){
	if (node == NULL) {
		return true;
	}
	if (node->value < min || node->value > max) {
		return false;
	}
	int leftHeight = helpHeight(node->lchild);
	int rightHeight = helpHeight(node->rchild);
	if (abs(leftHeight - rightHeight) > 1) {
		return false;
	}
	return helpBST(node->lchild, min, node->value - 1) && helpBST(node->rchild, node->value + 1, max);
}
BST::~BST() { // destructor
	helpDestroy(myRoot);
	myRoot = 0;
}
BST::BST(BST& B) { // copy constructor
	myRoot = helpCopy(B.myRoot);
}
void BST::insert(int item) { // Assuming that all items are unique
	bool found = false;
	binNode* temp = myRoot;
	binNode* parent = myRoot;
	while (temp != 0 && found != true) {
		if (item > temp->value) {
			parent = temp;
			temp = temp->rchild;
		}
		else if (item < temp->value) {
			parent = temp;
			temp = temp->lchild;
		}
		else found = true;
	}
	if (!found) {
		if (myRoot == 0) {
			myRoot = new binNode(item);
		}
		else {
			if (item < parent->value) parent->lchild = new binNode(item);		
			else parent->rchild = new binNode(item);
		}
	}
	else cout << "Item has existed.Nothing to add\n";
		
}
void BST::erase(int item) {
	binNode* parent = 0;
	binNode* n2del = myRoot;
	bool found = false;
	//find the node
	while (found == false && n2del != 0) {
		if (item < n2del->value) { parent = n2del; n2del = n2del->lchild; }
		else if (item > n2del->value) { parent = n2del; n2del = n2del->rchild; }
		else found = true;
	}
	// check if node has both childred
	if (found == false) { cout << "nothing to delete \n"; return; }
	binNode* temp = n2del;
	if (temp->lchild != 0 && temp->rchild != 0) {
		parent = temp; temp = temp->rchild;
		while (temp->lchild != 0) {
			parent = temp; temp = temp->lchild;
		}
		n2del->value = temp->value;
		n2del = temp;
	}
	//now delete 
	if (parent == 0) {//root is deleted
		myRoot = myRoot->lchild != 0 ? myRoot->lchild : myRoot->rchild;
	}
	else {
		if (parent->lchild == n2del) {
			parent->lchild = n2del->lchild != 0 ? n2del->lchild : n2del->rchild;
		}
		else {
			parent->rchild = n2del->lchild != 0 ? n2del->lchild : parent->rchild = n2del->rchild;
		}
	}
	delete n2del;
}
ostream& operator<<(ostream& out, BST& B) {
	 B.helpDisplay(out,0 , B.myRoot);
	 return out;
}
BST BST::operator=(const BST& B) {
	if (this != &B) {
		helpDestroy(myRoot);
		myRoot = 0;
		myRoot = helpCopy(B.myRoot);
	}
	return *this;
}
bool BST::search(int item) {
	bool found = false;
	binNode* temp = myRoot;
	binNode* parent = myRoot;
	while (temp != 0 && found != true) {
		if (item > temp->value) {
			parent = temp;
			temp = temp->rchild;
		}
		else if (item < temp->value) {
			parent = temp;
			temp = temp->lchild;
		}
		else found = true;
	}
	return found;
}
int BST::count() {
	return helpcount(myRoot);
}
void BST::displayInorder() {
	helpInorder(myRoot);
}
void BST::displayPostorder() {
	helpPostorder(myRoot);
}
void BST::displayPreorder() {
	helpPreorder(myRoot);
}
void BST::createMirror() {
	helpMirror(myRoot);
}
int BST::level(int item) {
	return helpLevel(myRoot,item,0);
}
int BST::height() {
	return helpHeight(myRoot);
}
int BST::leafCount() {
	return helpLeaf(myRoot);
}

bool BST::isBST(){
	return helpBST(myRoot,INT_MIN,INT_MAX);
}

