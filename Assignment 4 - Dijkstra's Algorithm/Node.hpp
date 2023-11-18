#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <vector>

class Node{
    private:
        struct Edge
        {
            Node * neighbor;
            // max length of a short is 2 bytes
            // functionally, this will be our "infinity"
            unsigned short dist = 0xffff;
        };
        std::string name;
        std::vector<Edge> edges;
    protected:
    public:
        Node(std::string name) { this->name = name; };
        ~Node();
        
        std::string getName() { return this->name; };
        std::vector<Edge> getEdges() { return this->edges; };
        void createEdge(Node * n, unsigned short dist);
};

#endif