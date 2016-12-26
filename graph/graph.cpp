#include "graph.h"

using namespace std;

Graph::Graph()
{

}

int Graph::AddNode(Node * n)
{
    Nodes[n->GetCoords()] = n;
}

Node * Graph::GetNode(double lat, double lon)
{
    return Nodes[make_pair(lat, lon)];
}

int Graph::GetSize() const
{
    return Nodes.size();
}

Graph::~Graph()
{

}
