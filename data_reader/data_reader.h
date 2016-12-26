#ifndef _DATA_READER_H_
#define _DATA_READER_H_

#include "ogrsf_frmts.h"
#include "node.hpp"
#include <cstring>

struct NodePair
{
    Node * n1;
    Node * n2;
};

class DataReader{
private:
    GDALDataset * pDS;
    OGRLayer * pLayer;
    int featureCount;

public:
    DataReader(std::string );
    int InitLayer(int);
    NodePair GetNodesFromCurrentLine() const;
    int GetLayerSize() const;
    double static DistanceBetweenTwoPoints(Node * , Node *);
    ~DataReader();
};

#endif
