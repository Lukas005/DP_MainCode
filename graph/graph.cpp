#include "graph.h"
#include <iostream>

using namespace std;

Graph::Graph()
{

}

void Graph::PrintGraph()
{
    map<pair<double, double>, Node *>::iterator i;

    for(i= Nodes.begin(); i!= Nodes.end(); i++)
    {
        Node * n = i->second;
        cout << "Node: " << n->GetLat() << " " << n->GetLon() << endl;
        for (int j = 0; j < n->GetEdgesCount(); j++)
        {
            pair<Node*, double> pnd = n->GetNode(j);
            cout << pnd.first->GetLat() << " " <<pnd.first->GetLon() <<": " << pnd.second << endl;
        }
        cout << "----" << endl;
    }

}

int Graph::ReachableNodesCount()
{
    int counter = 0;
    ((Nodes.begin()))->second->Mark(&counter);
    return counter;
}

int Graph::AddNodePair(Node * n1, Node * n2)
{
    // INIT PHASE - make sure all nodes exists
    pair<double, double> coordinates;
    Node * a, *b;

    coordinates = n1->GetCoords();
    if(Nodes[n1->GetCoords()] == NULL)
    {
        Nodes[coordinates] = new Node(coordinates.first, coordinates.second);

    }
    a = Nodes[coordinates];

    coordinates = n2->GetCoords();
    if(Nodes[n2->GetCoords()] == NULL)
    {
        Nodes[coordinates] = new Node(coordinates.first, coordinates.second);
    }
    b = Nodes[coordinates];
    // add edge from n1 to n2
    if(n1->GetEdgesCount() != 1 || n2->GetEdgesCount() != 1)
    {
        cerr<< "Nodes included are not having just one neighbour." << endl;
    }

    a->AddNeighbour(b, n1->GetNode(0).second);

    // add edge from n2 to n1
    b->AddNeighbour(a, n2->GetNode(0).second);

}

Node * Graph::GetNode(double lat, double lon)
{
    return Nodes[make_pair(lat, lon)];
}

Node * Graph::GetNode(pair<double, double> p)
{
    return Nodes[p];
}

int Graph::ConstructGraph(DataReader * dr)
{
    int layerCount = dr->GetLayerSize();
    NodePair p;
    for (int i = 0; i < layerCount; i++) {
        p = dr->GetNodesFromCurrentLine();
        this->AddNodePair(p.n1, p.n2);
        //  enable
        delete p.n1;
        delete p.n2;
    }

    cout << "Graph created! Feature count " << layerCount
        << " and nodes " << this->GetSize() << endl;

    return 0;
}

int Graph::GetSize() const
{
    return Nodes.size();
}

/*
Node * Graph::FindClosest(std::pair<double, double> in)
{
    std::map<std::pair<double, double>, Node * >::iterator closest;
    closest = Nodes.lower_bound(in);
    if (closest == Nodes.end())
        closest--;
    return closest->second;
}
*/
map<pair<double, double>, double* > Graph::CreateDistanceArray(int s)
{
    map<pair<double, double>, Node *>::iterator i;
    map<pair<double, double>, double *> distanceArray;

    for(i= Nodes.begin(); i!= Nodes.end(); i++)
    {
        distanceArray[i->first] = new double[s];
    }

    return distanceArray;
}


void Graph::RemoveDistanceArray(map<pair<double, double>, double * > *da)
{
    map<pair<double, double>, double * >::iterator i;

    for (i = da->begin(); i!=da->end(); i++)
    {
        delete [] i->second;
    }

}


Node * Graph::FindClosest2(std::pair<double, double> in)
{
    std::map<std::pair<double, double>, Node * >::iterator i, res;

    Node * a = new Node(in.first, in.second);

    double min_distance = 9999999;
    double subres;
    for( i = Nodes.begin(); i!= Nodes.end(); i++)
    {
        subres =  DataReader::DistanceBetweenTwoPoints(a, i->second);
        if(subres < min_distance)
        {
            res = i;
            min_distance = subres;
        }
    }

    delete a;
    return res->second;
}

Graph::~Graph()
{
    Nodes.erase(Nodes.begin(), Nodes.end());
}
