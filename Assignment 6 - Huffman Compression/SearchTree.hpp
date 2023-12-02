# include "BinaryTree.hpp"
class SearchTree : public BinaryTree {
private:
    // delete node to which p points
    void deleteFromTree(Node *& p);
protected:
public:
    // determines if item is in BST
    bool search(const int & searchItem) const;
    // inserts item into BST 
    void insert(const int & insertItem);
    // deletes item from BST
    void deleteNode(const int & deleteItem);
};
