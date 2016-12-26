#include <cstdlib>
#include <iostream>
#include "gdal.h"
#include "data_reader.h"
#include "node.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    GDALAllRegister();
    const string input = "/home/lukas/Dropbox/Diplomka/Data/prague_czech-republic_osm_roads_gen0.shp";
    const string ouput = "/home/lukas/Dropbox/Diplomka/Output/out.shp";

    DataReader d (input);
    Node *n1, *n2;
    NodePair p;

    d.InitLayer(0);

    cout << "Size: " << d.GetLayerSize() << endl;

//    for (int i = 0; i < 10; i++)
    {
        p = d.GetNodesFromCurrentLine();
        n1 = p.n1;
        n2 = p.n2;

        cout << n1->GetID() << " " << n1->GetLat()  << " "  << n1->GetLon()  << " " << endl ;
        cout << n2->GetID() << " " << n2->GetLat()  << " "  << n2->GetLon()  << " " << endl ;
        cout << DataReader::DistanceBetweenTwoPoints(n1, n2) << endl;
    }
    cout << "Hello world" << endl;
    return 0;
}
