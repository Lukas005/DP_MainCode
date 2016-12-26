#include "data_reader.h"
#include <cmath>
#include <iostream>
using namespace std;

DataReader::DataReader(string inputFile)
{
    pDS = (GDALDataset*) GDALOpenEx( inputFile.c_str(), GDAL_OF_VECTOR, NULL, NULL, NULL );
    if( pDS == NULL )
    {
        cerr << "GDALOpenEx: Failed to open" << endl;
    }
    pLayer = NULL;
}

int DataReader::InitLayer(int index)
{
    pLayer = pDS->GetLayer(index);
    if(pLayer == NULL)
    {
        cerr << "DataReader.InitLayer: Layer does not exist, choose different index " << index << "." << endl;
        return 1;
    }

    pLayer->ResetReading();
    return 0;
}

NodePair DataReader::GetNodesFromCurrentLine() const
{
    NodePair pair;

    if(!pLayer)
    {
        cerr << "DataReader.PopulateNodeFromLine: Layer not initiated.";
        return pair;
    }

    OGRFeature * pFeature;

    pFeature = pLayer->GetNextFeature();
    if(pFeature == NULL)
    {
        cerr << "DataReader.PopulateNodeFromLine: No more features found.";
        return pair;
    }

    OGRGeometry * pG;
    pG = pFeature->GetGeometryRef();

    if( pG != NULL
            && wkbFlatten(pG->getGeometryType()) == wkbLineString )
    {
        OGRLineString *pLine = (OGRLineString *) pG;
        cout << "bla" << endl;
        pair.n1 = new Node(0, pLine->getY(0), pLine->getX(0));
        pair.n2 = new Node(1, pLine->getY(1), pLine->getX(1));

        double dist = DistanceBetweenTwoPoints(pair.n1, pair.n2);

        pair.n1->AddNeighbour(pair.n2, dist);
        pair.n2->AddNeighbour(pair.n1, dist);

        // printf( "1: %f,%f 2: %f, %f\n", poPoint->getX(0), poPoint->getY(0), poPoint->getX(2), poPoint->getY(1));
    }
    else
    {
        cerr << "DataReader.PopulateNodeFromLine: No line geometry.";
    }

    return pair;
}


double DataReader::DistanceBetweenTwoPoints(Node * n1, Node * n2)
{
    double pi = atan(1) * 4;
    double lat1 = n1->GetLat() * pi / 180.0
        , lon1 = n1->GetLon() * pi / 180.0;
    double lat2 = n2->GetLat() * pi / 180.0
        , lon2 = n2->GetLon() * pi / 180.0;

    double deltaLambda = cos(abs( lon1 - lon2));
    double sin1 = sin(lat1) * sin(lat2);
    double cos1 = cos(lat1) * cos(lat2) * deltaLambda;

    double o = acos(sin1 + cos1);

    return o * 6371;    // Earth radius
}


DataReader::~DataReader()
{
    GDALClose(pDS);
}
