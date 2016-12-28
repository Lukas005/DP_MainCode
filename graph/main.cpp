#include "graph.h"
#include "gdal.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    GDALAllRegister();
    const string input = "/home/lukas/Dropbox/Diplomka/Data/prague_czech-republic_osm_roads_gen0.shp";
    const string ouput = "/home/lukas/Dropbox/Diplomka/Output/out.shp";

    DataReader d (input);
    d.InitLayer(0);

    Graph g;
    g.ConstructGraph(&d);

    cout << sizeof(g) << endl;
/*
    Node n1(1, 220.2, 33.3), n2(4, 5.023, 6);
    g.AddNode(&n1);
    g.AddNode(&n2);
    cout << "Hello Graph" << endl;
    cout << g.GetSize() << endl;
    cout << (g.GetNode(1,1) == NULL) << endl;
    cout << (g.GetNode(220.2,33.3) == NULL) << endl;
    cout << (g.GetNode(5.02300,6.0)->GetCoords().first) << endl;
    cout << g.GetSize() << endl;
*/
    return 0;
}
