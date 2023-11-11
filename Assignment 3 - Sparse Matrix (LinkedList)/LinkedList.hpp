#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

class LinkedList {
    private:
        struct Node{
            int row;
            int column;
            int value;
            Node * next;
        };
        Node * head;
        int height;
        int width;
    protected:
    public:
        // constructor and destructor
        LinkedList(int height, int width);
        ~LinkedList();

        // getters
        Node * getHead() { return this->head; };
        int getRow(Node * n) { return n->row; };
        int getColumn(Node * n) { return n->column; };
        int getValue(Node * n) { return n->value; };

        // helper functions
        void appendNode(int row, int column, int value);
            // delete from Node reference
        void deleteNode(Node * n);
            // delete from rcv reference
        void deleteNode(int row, int column, int value);
        void printNodes();
        void printMatrix();
        
};

#endif