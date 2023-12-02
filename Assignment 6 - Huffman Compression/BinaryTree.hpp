#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>

class BinaryTree {
    protected:
        struct Node{
            int info;
            Node * llink;
            Node * rlink;
        };
        Node * root;
    private: 
        // creates copy of tree of the other tree
        void copyTree(Node *& copiedTreeRoot, Node * otherTreeRoot);
        // destroys the tree which p points to
        void destroy(Node *& p);
        // inorder traversal pointing to p
        void inorder(Node * p) const;
        // preorder traversal 
        void preorder(Node * p) const;
        // postorder traversal
        void postorder(Node * p) const;
        // find height starting from p
        int height(Node * p) const;
        // returns greatest
        int max(int x, int y) const;
        // returns number of nodes in tree from p
        int nodeCount(Node * p) const;
        
    public:
        /* constructors and destructors */
        // default constructor
        BinaryTree();
        // copy constructor
        BinaryTree(const BinaryTree & otherTree);
        // destructor
        ~BinaryTree();
        // deallocates portion of the tree ("pruning")
        void destroyTree();

        /* getters and setters */
        bool isEmpty() const;
        int treeHeight() const;
        int treeNodeCount() const;

        /* helper functions */
        void inorderTraversal() const;
        void preorderTraversal() const;
        void postorderTraversal() const;
        
        /* misc */
        // Overload assignment (=) operator
        const BinaryTree & operator=(const BinaryTree &);
};

#endif
