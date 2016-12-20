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

    d.InitLayer(0);
    d.PopulateNodeFromLine(n1, n2);


    cout << n1->GetID() << n1->GetX() << n1->GetY() << endl ;
    cout << "Hello world" << endl;
    return 0;
}
