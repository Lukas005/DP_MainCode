#include "node.hpp"
#include <iostream>

using namespace std;

Node::Node(double nx, double ny)
{
    lat = nx;
    lon = ny;
    maxAdjNodes = 4;
    adjNodesCount = 0;
    adjNodes = new Node*[maxAdjNodes];
    edgeW = new double[maxAdjNodes];
    marked = false;
}

void Node::Mark(int * const counter)
{
    if(marked)
    {
        return;
    }
    else
    {
        marked =  true;
        cout << "Marked: " << lat << "-" << lon << endl;
        (*counter)++;
        for (int i = 0; i < adjNodesCount; i++) {
            adjNodes[i]->Mark(counter);
        }
    }
}

pair<Node *, double> Node::GetNode(int index) const
{
    if (index >= adjNodesCount)
    {
        cerr << "GetNode: Index " << index << " is out of range." << endl;
        Node * err;
        return make_pair(err, -1);
    }

    return make_pair(adjNodes[index], edgeW[index]);
}

int Node::GetEdgesCount() const
{
    return adjNodesCount;
}

Node ** Node::GetEdges()
{
    return adjNodes;
}

int Node::AddNeighbour(Node * pNode, double distance)
{
    if (pNode == NULL)
    {
        cerr << "Node::AddNeighbour: Argument null";
        return 1;
    }

    adjNodes[adjNodesCount] = pNode;
    edgeW[adjNodesCount] = distance;

    adjNodesCount++;

    if(adjNodesCount == maxAdjNodes)
    {
        maxAdjNodes *= 2;
        Node ** resizeAdjNodes = new Node*[maxAdjNodes];
        double * resEdgeW = new double[maxAdjNodes];
        for (int i = 0; i < adjNodesCount; i++) {
            resizeAdjNodes[i] = adjNodes[i];
            resEdgeW[i] = edgeW[i];
        }

        delete [] edgeW;
        delete [] adjNodes;
        adjNodes = resizeAdjNodes;
        edgeW = resEdgeW;
    }

    return 0;
}

pair<double, double> Node::GetCoords() const
{
    return make_pair(lat, lon);
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
    delete [] edgeW;
}
