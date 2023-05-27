#include "BST.h"
#include <iostream>
#include <time.h>
using namespace std;

int main() {
    BST BTree, B;
    srand(time(0));
    for (int i = 0; i < 8; i++) BTree.insert(i);
    cout << "BTree:\n" << BTree << endl;
    cout << "Number of node in BTree: " << BTree.count() << endl;
    cout << "Level of 7 in BTree is: " << BTree.level(7) << endl;
    cout << "Number of leaf in BTree: " << BTree.leafCount() << endl;
    cout << "---------------------------------------------\n";

    for (int i = 0; i < 10; i++) B.insert(rand() / 1000);
    cout << "B:\n" << B << endl;
    cout << "Number of node in B: " << B.count() << endl;
    cout << "Number of leaf in B: " << B.leafCount() << endl;
    cout << "Is B is a BST: " << B.isBST() << endl;
    cout << "---------------------------------------------\n";
    cout << "Testing traversals: \n";
    cout << "Inorder:\n";
    BTree.displayInorder();
    cout << endl;
    B.displayInorder();
    cout << endl;

    cout << "Postorder:\n";
    BTree.displayPostorder();
    cout << endl;
    B.displayPostorder();
    cout << endl;

    cout << "Preorder:\n";
    BTree.displayPreorder();
    cout << endl;
    B.displayPreorder();
    cout << endl;
    cout << "---------------------------------------------\n";
    cout << "Create a mirror of B:\n";
    B.createMirror();
    cout << B;


    system("pause");
    return 0;
}