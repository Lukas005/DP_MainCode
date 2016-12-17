#include <cstdlib>
#include <iostream>
#include "gdal.h"

using namespace std;

int main(int argc, char const *argv[]) {
    GDALAllRegister();
    const string input = "/home/lukas/Dropbox/Diplomka/Data/prague_czech-republic_osm_roads_gen0.shp"
    const string ouput = "/home/lukas/Dropbox/Diplomka/Output/out.shp"
    cout << "Hello world" << endl;
    return 0;
}
