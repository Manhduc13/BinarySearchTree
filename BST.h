#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;

class BST {
private:
    class binNode {
    public:
        int value;
        binNode* lchild;
        binNode* rchild;
        binNode():rchild(0), lchild(0) {}
        binNode(int item) : value(item), rchild(0), lchild(0) {}
    };
    binNode* myRoot;
    //helper functions
    void helpDestroy(binNode*);
    binNode* helpCopy(binNode*);
    void helpDisplay(ostream&, int, binNode*);
    int helpcount(binNode*);
    void helpInorder(binNode*);
    void helpPostorder(binNode*);
    void helpPreorder(binNode*);
    void helpMirror(binNode*);
    int helpLevel(binNode*,int,int);
    int helpHeight(binNode*);
    int helpLeaf(binNode*);
    bool helpBST(binNode*,int,int);
public:
    BST():myRoot(0) {}
    ~BST();
    BST(BST&);
    //data structure methods
    void insert(int);
    void erase(int);
    bool search(int);
    int count();
    void displayInorder();
    void displayPostorder();
    void displayPreorder();
    void createMirror();
    int level(int);
    int height();
    int leafCount();
    bool isBST();
    BST operator=(const BST&);
    friend ostream& operator<<(ostream&, BST&);
};
#endif