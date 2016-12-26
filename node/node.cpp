#include "node.hpp"
#include <iostream>

using namespace std;

Node::Node(unsigned int nid, double nx, double ny)
{
    id = iid++;
    lat = nx;
    lon = ny;
    maxAdjNodes = 4;
    adjNodesCount = 0;
    adjNodes = new Node*[maxAdjNodes];
}

Node * Node::GetNode(int index) const
{
    if (index >= adjNodesCount)
    {
        cerr << "GetNode: Index " << index << " is out of range." << endl;
        return NULL;
    }

    return adjNodes[index];
}

int Node::AddNeighbour(Node * pNode)
{
    if (pNode == NULL)
    {
        cerr << "Node::AddNeighbour: Argument null";
        return 1;
    }

    adjNodes[adjNodesCount++] = pNode;

    if(adjNodesCount == maxAdjNodes)
    {
        maxAdjNodes *= 2;
        Node ** resizeAdjNodes = new Node*[maxAdjNodes];
        for (int i = 0; i < adjNodesCount; i++) {
            resizeAdjNodes[i] = adjNodes[i];
        }

        delete [] adjNodes;
        adjNodes = resizeAdjNodes;
    }

    return 0;
}

unsigned Node::GetID() const
{
    return id;
}

double Node::GetLat() const
{
    return lat;
}

double Node::GetLon() const
{
    return lon;
}

Node::~Node()
{
    delete [] adjNodes;
}
