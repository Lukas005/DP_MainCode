#include "graph.h"
#include <iostream>

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

int Graph::ConstructGraph(DataReader * dr)
{
    int layerCount = dr->GetLayerSize();
    NodePair p;
    for (int i = 0; i < layerCount; i++) {
        p = dr->GetNodesFromCurrentLine();
        this->AddNode(p.n1);
        this->AddNode(p.n2);
    }

    cout << "Graph created! Feature count " << layerCount
        << " and nodes " << this->GetSize() << endl;

    return 0;
}

int Graph::GetSize() const
{
    return Nodes.size();
}

Graph::~Graph()
{
    Nodes.erase(Nodes.begin(), Nodes.end());
}
