#include <iostream>
#include "SearchTree.hpp"

using namespace std;

int main() {
    SearchTree treeRoot, treeRoot1;
    int num;
    cout << "Enter numbers. Use -999 to terminate." << endl;
    do{
        cin >> num;
        treeRoot.insert(num);
    } while(num != -999);

    cout << endl;
    
    treeRoot.inorderTraversal();
    
    cout << endl << "Tree Height: " << treeRoot.treeHeight() << endl << endl;

    cout << endl << "Tree nodes in preorder: ";
    treeRoot.preorderTraversal();

    cout << endl << "Tree nodes in postorder: ";
    treeRoot.postorderTraversal();

    treeRoot1 = treeRoot;
    cout << endl << "Second Tree nodes in inorder: ";
    treeRoot1.inorderTraversal();

    cout << endl << "Enter a value to delete from the tree: " << endl;
    int deletedItem;
    cin >> deletedItem;
    treeRoot1.deleteNode(deletedItem);

    cout << endl << "Tree nodes after delete operation in inorder: ";
    treeRoot1.inorderTraversal();

    return 0;
};