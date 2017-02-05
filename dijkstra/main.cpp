#include <cstdio>
#include <iostream>
#include "dijkstra.h"

using namespace std;

Graph * Test1()
{
    Graph * g = new Graph();
    // line 1
    Node * n0 = new Node(1, 1);
    Node * n1 = new Node(4, 1);
    n0->AddNeighbour(n1, 0);
    n1->AddNeighbour(n0, 0);

    g->AddNodePair(n0, n1);

    delete n0;
    delete n1;

    // line 2
    n1 = new Node(4, 1);
    Node * n2 = new Node(2, 2);
    n1->AddNeighbour(n2, 1);
    n2->AddNeighbour(n1, 1);

    g->AddNodePair(n1, n2);

    delete n1;
    delete n2;
    // line 3
    n2 = new Node(2, 2);
    Node * n3 = new Node(1, 4);
    n3->AddNeighbour(n2, 2);
    n2->AddNeighbour(n3, 2);

    g->AddNodePair(n2, n3);

    delete n2;
    delete n3;

    // line 4
    n3 = new Node(1, 4);
    Node * n4 = new Node(4, 3);
    n3->AddNeighbour(n4, 3);
    n4->AddNeighbour(n3, 3);

    g->AddNodePair(n4, n3);

    delete n4;
    delete n3;

    // line 5
    n1 = new Node(4, 1);
    n4 = new Node(4, 3);
    n1->AddNeighbour(n4, 4);
    n4->AddNeighbour(n1, 4);

    g->AddNodePair(n4, n1);

    delete n4;
    delete n1;

    // line 6
    Node * n5 = new Node(5, 4);
    n4 = new Node(4, 3);
    n5->AddNeighbour(n4, 5);
    n4->AddNeighbour(n5, 5);

    g->AddNodePair(n4, n5);

    delete n4;
    delete n5;

    return g;
}



int main(int argc, char ** argv)
{
    Graph * g;
    g = Test1();
    g->PrintGraph();

    map<pair<double, double>, double * > m;
    m = CDijkstra::dijkstra(g, make_pair(2,2), 1, 0);


    cout << m[make_pair(1,1)][0] << endl;
    cout << m[make_pair(4,1)][0] << endl;
    cout << m[make_pair(2,2)][0] << endl;
    cout << m[make_pair(1,4)][0] << endl;
    cout << m[make_pair(4,3)][0] << endl;
    cout << m[make_pair(5,4)][0] << endl;

    Graph::RemoveDistanceArray(&m);
    delete g;

    return 0;
}
