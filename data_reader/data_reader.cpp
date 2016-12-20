#include "data_reader.h"
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

int DataReader::PopulateNodeFromLine(Node * n1, Node * n2) const
{
    if(!pLayer)
    {
        cerr << "DataReader.PopulateNodeFromLine: Layer not initiated.";
        return 1;
    }

    OGRFeature * pFeature;

    pFeature = pLayer->GetNextFeature();
    if(pFeature == NULL)
    {
        cerr << "DataReader.PopulateNodeFromLine: No more features found.";
        return 1;
    }

    OGRGeometry * pG;
    pG = pFeature->GetGeometryRef();

    if( pG != NULL
            && wkbFlatten(pG->getGeometryType()) == wkbLineString )
    {
        OGRLineString *pLine = (OGRLineString *) pG;
        cout << "bla" << endl;
        n1 = new Node(0, pLine->getX(0), pLine->getY(0));
        n2 = new Node(1, pLine->getX(1), pLine->getY(1));

        n1->GetNodeInfo();
        n2->GetNodeInfo();
        // printf( "1: %f,%f 2: %f, %f\n", poPoint->getX(0), poPoint->getY(0), poPoint->getX(2), poPoint->getY(1));
    }
    else
    {
        cerr << "DataReader.PopulateNodeFromLine: No line geometry.";
        return 1;
    }

    return 0;
}

DataReader::~DataReader()
{
    GDALClose(pDS);
}
