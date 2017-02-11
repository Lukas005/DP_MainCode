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
    n0->AddNeighbour(n1, 123.3265);
    n1->AddNeighbour(n0, 123.3265);

    g->AddNodePair(n0, n1);

    delete n0;
    delete n1;

    // line 2
    n1 = new Node(4, 1);
    Node * n2 = new Node(2, 2);
    n1->AddNeighbour(n2, 273.55);
    n2->AddNeighbour(n1, 273.55);

    g->AddNodePair(n1, n2);

    delete n1;
    delete n2;
    // line 3
    n2 = new Node(2, 2);
    Node * n3 = new Node(1, 4);
    n3->AddNeighbour(n2, 229.55);
    n2->AddNeighbour(n3, 229.55);

    g->AddNodePair(n2, n3);

    delete n2;
    delete n3;

    // line 4
    n3 = new Node(1, 4);
    Node * n4 = new Node(4, 3);
    n3->AddNeighbour(n4, 324.2323);
    n4->AddNeighbour(n3, 324.2323);

    g->AddNodePair(n4, n3);

    delete n4;
    delete n3;

    // line 5
    n1 = new Node(4, 1);
    n4 = new Node(4, 3);
    n1->AddNeighbour(n4, 444.44);
    n4->AddNeighbour(n1, 444.44);

    g->AddNodePair(n4, n1);

    delete n4;
    delete n1;

    // line 6
    Node * n5 = new Node(5, 4);
    n4 = new Node(4, 3);
    n5->AddNeighbour(n4, 532.32654);
    n4->AddNeighbour(n5, 532.32654);

    g->AddNodePair(n4, n5);

    delete n4;
    delete n5;

    return g;
}



int main(int argc, char ** argv)
{
    /*** ADVANCED GRAPH
    GDALAllRegister();
    const string inputf = "/home/lukas/Dropbox/Diplomka/Data/prague_czech-republic_osm_roads.shp";
    const string ouput = "/home/lukas/Dropbox/Diplomka/Output/out.shp";

    DataReader d (inputf);
    d.InitLayer(0);
    cout << "creating graph" << endl;
    Graph g;
    g.ConstructGraph(&d);

    cout << "finding nodes" << endl;
    Node * input1 = g.FindClosest2(make_pair(50.075908, 14.413734));

    Node * input2 = g.FindClosest2(make_pair(50.092441, 14.437480));


    cout << "Input1:" << input1->GetLat() << "-" << input1->GetLon() << endl;

        cout << input1->GetEdgesCount() <<  " <<"<<endl;


    cout << "Input2:" << input2->GetLat() << "-" << input2->GetLon() << endl;

            cout << input2->GetEdgesCount() <<  " <<"<<endl;

    int numberOfInput = 2;

    pair<double, double> * input = new pair<double, double>[numberOfInput];

    input[0] = input1->GetCoords();
    input[1] = input2->GetCoords();
    cout << "MS" << endl;

    CDijkstra::MeetingSchedulerSeq(&g, input, numberOfInput);
    //* */
    /******************** SIMPLE GRAPH *************************/
    Graph * g;
    g = Test1();
    g->PrintGraph();
    int numberOfInput = 3;

    pair<double, double> * input = new pair<double, double>[numberOfInput];

    input[0] = make_pair(1,1);
    input[1] = make_pair(1,4);
    input[2] = make_pair(5,4);

    CDijkstra::MeetingSchedulerSeq(g, input, numberOfInput);


    delete g;
    //  */
    return 0;
}
