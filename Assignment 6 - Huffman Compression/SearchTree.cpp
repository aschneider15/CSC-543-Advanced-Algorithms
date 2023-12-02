#include "SearchTree.hpp"

bool SearchTree::search(const int & searchItem) const {
    Node * cur;
    bool found = false;
    if(this->root == nullptr) {
        std::cerr << "ERR: Cannot search an empty tree." << std::endl;
    } else {
        cur = this->root;
        while(cur != nullptr && !found) {
            if(cur->info = searchItem) {
                found = true;
            } else if(cur->info > searchItem) {
                cur = cur->llink;
            } else {
                cur = cur->rlink;
            }
        }
    }
    return found;
}

void SearchTree::insert(const int & insertItem) {
    Node * cur;
    Node * prev;
    Node * newNode = new Node;
    newNode->info = insertItem;
    newNode->llink = nullptr;
    newNode->rlink = nullptr;
    if(this->root == nullptr) {
        this->root = newNode;
    } else {
        cur = this->root;
        prev = nullptr;
        while(cur != nullptr) {
            prev = cur;
            if(cur->info == insertItem) {
                std::cerr << "ERR: The inserted item is already in the list, and duplicates aren't allowed: ";
                std::cerr << insertItem << std::endl;
                return;
            } else if(cur->info > insertItem) {
                cur = cur->llink;
            } else {
                cur = cur->rlink;
            }
        }
    }
    if(prev->info > insertItem) {
        prev->llink = newNode;
    } else {
        prev->rlink = newNode;
    }
}

void SearchTree::deleteNode(const int & deleteItem) {
    Node * cur;
    Node * prev;
    bool found = false;

    if(this->root == nullptr) {
        std::cerr << "ERR: Cannot delete from an empty tree." << std::endl;
    } else {
        cur = this->root;
        prev = this->root;

        while(cur != nullptr && !found) {
            if(cur->info == deleteItem) {
                found = true;
            } else {
                prev = cur;
                if(cur->info > deleteItem) {
                    cur = cur->llink;
                } else {
                    cur = cur->rlink;
                }
            }
        }
        if(cur == nullptr) {
            std::cerr << "ERR: The item requested is not in the tree: ";
            std::cerr << deleteItem << std::endl;
        } else if(found) {
            if(cur = this->root) {
                deleteFromTree(this->root);
            } else if(prev->info > deleteItem) {
                deleteFromTree(prev->llink);
            } else {
                deleteFromTree(prev->rlink);
            }
        }
    }
}

void SearchTree::deleteFromTree(Node *& p) {
    Node * cur;
    Node * prev;
    Node * temp;

    if(p == nullptr) {
        std::cerr << "ERR: The node requested for deletion is NULL" << std::endl;
    } else if(p->llink == nullptr && p->rlink == nullptr) {
        temp = p;
        p = nullptr;
        delete temp;
    } else if(p->llink == nullptr) {
        temp = p;
        p = temp->rlink;
        delete temp;
    } else if(p->rlink == nullptr) {
        temp = p;
        p = temp->llink;
        delete temp;
    } else {
        cur = p-> llink;
        prev = nullptr;
        while(cur->rlink != nullptr) {
            prev = cur;
            cur = cur->rlink;
        }
        p->info = cur->info;
        if(prev == nullptr) {
            p->llink = cur->llink;
        } else {
            prev->rlink = cur->llink;
        }
        delete cur;
    }
}