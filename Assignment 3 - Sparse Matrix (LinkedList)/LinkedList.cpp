#include "LinkedList.hpp"

// constructor and destructor
LinkedList::LinkedList(int height, int width) {
    this->head = nullptr;
    this->height = height;
    this->width = width;
};

LinkedList::~LinkedList() {
    // abort if list is already empty
    if(!this->head) {
        return;
    }
    // if head is the only element in the list, then delete it and abort
    if(!this->head->next) {
        delete this->head;
        return;
    }
    // otherwise, go through and delete every node from first to last
    Node *curNode = this->head;
    Node *nextNode = this->head->next;
    while(nextNode) {
        delete curNode;
        curNode = nextNode;
        nextNode = nextNode->next;
    }
    delete curNode;
};

// helper functions
void LinkedList::appendNode(int row, int column, int value) {
    Node *n, *curNode;
    n = new Node;
    n->row = row; 
    n->column = column; 
    n->value = value;
    n->next = nullptr;

    // if list is empty, make this the first node
    if(!this->head) {
        this->head = n;
    } else {
        curNode = this->head;
        // find last node in the list
        while(curNode->next) {
            curNode = curNode->next;
        }
        // insert new node at end
        curNode->next = n;
    }
};

void LinkedList::deleteNode(Node * n) {
    Node *curNode, *prevNode;
    // abort if the list is empty
    if(!this->head) {
        return;
    }
    // determine if the first node is the one we're looking for
    if(this->head == n) {
        curNode = this->head->next;
        delete head;
        head = curNode;
    } else {
        curNode = this->head;
        // traverse until desired node is found
        while(curNode != nullptr && curNode != n) {
            prevNode = curNode;
            curNode = curNode->next;
        }
        // link previous node to node after curNode, then delete curNode
        prevNode->next = curNode->next;
        delete curNode;
    }
};

void LinkedList::deleteNode(int row, int column, int value) {
    Node *curNode, *prevNode;
    // abort if the list is empty
    if(!this->head) {
        return;
    }
    // determine if the first node is the one we're looking for
    if(this->head->row == row && this->head->column == column && this->head->value == value) {
        curNode = this->head->next;
        delete head;
        head = curNode;
    } else {
        curNode = this->head;
        // traverse until desired node is found
        while(curNode != nullptr &&
        curNode->row != row &&
        curNode->column != column &&
        curNode->value != value) {
            prevNode = curNode;
            curNode = curNode->next;
        }
        // link previous node to node after curNode, then delete curNode
        prevNode->next = curNode->next;
        delete curNode;
    }
};

void LinkedList::printNodes() {
    Node *curNode = this->head;
    // until we find a node pointer to null
    while(curNode) {
        std::cout << "[" << curNode->row << ", " << curNode->column << ", " << curNode->value << "]" << std::endl;
        curNode = curNode->next;
    }
};

void LinkedList::printMatrix() {
    int mat[this->height][this->width];

    /*
        Create a matrix of size (height x width) full of zeroes.
        Go through the row, column and value arrays, altering
        each coordinate in the first two arrays with the value
        of the third array.
    */
   
    // fill the matrix with all zeroes
    for(int i = 0; i < this->height; i++) {
        for(int j = 0; j < this->width; j++) {
            mat[i][j] = 0;
        }
    }

    // replace values from comprising arrays
    Node *curNode = this->head;
    while(curNode) {
        mat[curNode->row][curNode->column] = curNode->value;
        curNode = curNode->next;
    }

    // display resulting matrix
    for(int i = 0; i < this->height; i++) {
        for(int j = 0; j < this->width; j++) {
            std::cout << mat[i][j] << " ";
        }
        // seperate row with new line
        printf("\n");
    }
};
