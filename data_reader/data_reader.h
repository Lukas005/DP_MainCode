#ifndef _DATA_READER_H_
#define _DATA_READER_H_

#include "ogrsf_frmts.h"
#include "node.hpp"
#include <cstring>

class DataReader{
private:
    GDALDataset * pDS;
    OGRLayer * pLayer;

public:
    DataReader(std::string );
    int InitLayer(int);
    int PopulateNodeFromLine(Node*, Node*) const;
    int GetDataSize() const;
    ~DataReader();
};

#endif
