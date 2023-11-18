#include <iostream>
#include <stdlib.h>
#include "Node.hpp"

#define INF 0xffff
using namespace std;

int getIndexOfNode(vector<Node *> v, Node *n);

int main()
{
    // The map is the same one used in the explanation
    // It will look something like this:
    /*
         B--C
    A < || /||
         E--D

     */

    // definition of the map
    Node *a = new Node("a");
    Node *b = new Node("b");
    Node *c = new Node("c");
    Node *d = new Node("d");
    Node *e = new Node("e");

    a->createEdge(b, 10);
    a->createEdge(e, 3);
    b->createEdge(c, 2);
    b->createEdge(e, 1);
    c->createEdge(d, 7);
    d->createEdge(c, 9);
    e->createEdge(b, 4);
    e->createEdge(c, 8);
    e->createEdge(d, 2);

    // Functionally, limit of unsigned short should suffice
    // for the representative size of infinity.
    // The first node is zero because it's the starting node,
    // so we have already "visited it"

    // keep track of all unvisited nodes
    vector<Node *> unvisited;
    unvisited.push_back(b);
    unvisited.push_back(c);
    unvisited.push_back(d);
    unvisited.push_back(e);

    Node * origin = a;
    Node * destination = c;
    vector<Node *> path;

    /* ============================ Dijkstra's Algorithm ============================ */
    // inspect each node, finding the shortest path between
    // nodes leading to the destination node.
    Node *curNode = origin;
    while (!unvisited.empty() && curNode != destination)
    {
        // Initialize shortest and closest to represent infinity or unreachable state
        Node * closest = nullptr;
        unsigned short shortest = INF;
        // update closest node and shortest path
        // whenever the current node gets updated
        cout << "CURRENT NODE: " << curNode->getName() << endl;
        for (int i = 0; i < curNode->getEdges().size(); i++)
        {
            // if the neighbor's distance is shorter than the previous best,
            // and the node in question is still unvisited
            if (getIndexOfNode(unvisited, curNode->getEdges().at(i).neighbor) != -1)
            {
                cout << "\tINSPECTING NODE: " << curNode->getEdges().at(i).neighbor->getName();
                cout << " dist: " << curNode->getEdges().at(i).dist;

                if (curNode->getEdges().at(i).dist < shortest)
                {
                    cout << "\tNEW SHORTEST!!";
                    shortest = curNode->getEdges().at(i).dist;
                    closest = curNode->getEdges().at(i).neighbor;


                }
                cout << endl;
            }
        }
        // update the current node, and remove the previous current node
        // from unvisited, if it hasn't already been removed
        int index = getIndexOfNode(unvisited, curNode);
        if (index != -1)
        {
            unvisited.erase(unvisited.begin() + index);
        }
        path.push_back(curNode);
        curNode = closest;
    }
    if(curNode == destination) {
        path.push_back(destination);
        cout << "SUCCESSFULLY MADE IT TO NODE " << curNode->getName() << "!!" << endl;
        cout << "Shortest (greedy) path: ";
        for(Node * n : path) {
            cout << n->getName() << " ";
        } 
        cout << endl;
    } else {
        cout << "No path to the desired destination." << endl;
    }
}

int getIndexOfNode(vector<Node *> v, Node *n)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v.at(i) == n)
        {
            return i;
        }
    }
    return -1;
}