#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "node.hpp"
#include "data_reader.h"
#include <map>

class Graph
{
private:
    std::map<std::pair<double, double>, Node * > Nodes;
public:
    Graph();
    int AddNode(Node * );
    Node * GetNode(double, double);
    int ConstructGraph(DataReader *);
    int GetSize() const;
    ~Graph();
};

#endif
