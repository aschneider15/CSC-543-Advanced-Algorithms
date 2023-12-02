#include "BinaryTree.hpp"

BinaryTree::BinaryTree() {
    this->root = nullptr;
}

BinaryTree::BinaryTree(const BinaryTree & otherTree) {
    if(otherTree.root == nullptr) {
        root = nullptr;
    } else {
        copyTree(this->root, otherTree.root);
    }
}

BinaryTree::~BinaryTree() {
    destroy(this->root);
}

bool BinaryTree::isEmpty() const {
    return (this->root == nullptr);
}

void BinaryTree::copyTree(Node *& copiedTreeRoot, Node * otherTreeRoot) {
    if(otherTreeRoot == nullptr) {
        copiedTreeRoot = nullptr;
    } else {
        copiedTreeRoot = new Node;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
        copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
    }
}

/* destruction implementations */
void BinaryTree::destroyTree() {
    destroy(this->root);
}

void BinaryTree::destroy(Node *& p) {
    if(p!= nullptr) {
        destroy(p->llink);
        destroy(p->rlink);
        delete p;
        p = nullptr;
    }
}

/* height implementations */

int BinaryTree::treeHeight() const {
    return height(root);
}

int BinaryTree::height(Node * p) const {
    if(p == nullptr) {
        return 0;
    } else {
        return 1 + max(height(p->llink), height(p->rlink));
    }
}

int BinaryTree::max(int x, int y) const {
    if (x >= y) {
        return x;
    } else {
        return y;
    }
}

/* node count  implementations */
int BinaryTree::treeNodeCount() const {
    return nodeCount(this->root);
}

int BinaryTree::nodeCount(Node * p) const {
    if(p == nullptr) {
        return 0;
    } else {
        return 1 + nodeCount(p->llink) + nodeCount(p->rlink);
    }
}

/* traversal implementations */
void BinaryTree::inorderTraversal() const {
    this->inorder(this->root);
}

void BinaryTree::inorder(Node * p) const {
    if(p != nullptr) {
        inorder(p->llink);
        std::cout << p->info << " ";
        inorder(p->rlink);
    }
}

void BinaryTree::preorderTraversal() const {
    this->preorder(this->root);
}

void BinaryTree::preorder(Node * p) const {
    if(p != nullptr) {
        std::cout << p->info << " ";
        preorder(p->llink);
        preorder(p->rlink);
    }
}

void BinaryTree::postorderTraversal() const {
    this->postorder(this->root);
}

void BinaryTree::postorder(Node * p) const {
    if(p != nullptr) {
        postorder(p->llink);
        postorder(p->rlink);
        std::cout << p->info << " ";
    }
}

// overloading the assignment operator
const BinaryTree& BinaryTree::operator=(const BinaryTree & otherTree) {
    // safeguards against self-copy
    if(this != &otherTree) {
        if(this->root != nullptr) {
            destroy(this->root);
        }

        if(otherTree.root == nullptr) {
            this->root = nullptr;
        } else {
            copyTree(this->root, otherTree.root);
        }
    }
    return * this;
}
