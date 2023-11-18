#include "Node.hpp"

void Node::createEdge(Node * n, unsigned short dist) {
    Edge make;
    make.neighbor = n;
    make.dist = dist;
    this->edges.push_back(make);
};