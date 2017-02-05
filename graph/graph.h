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
    int AddNodePair(Node *, Node * );
    Node * GetNode(double, double);
    Node * GetNode(std::pair<double, double>);
    int ConstructGraph(DataReader *);
    int GetSize() const;
    Node * FindClosest(std::pair<double, double>);
    Node * FindClosest2(std::pair<double, double>);
    void PrintGraph();
    std::map<std::pair<double, double>, double * > CreateDistanceArray(int);
    static void RemoveDistanceArray(std::map<std::pair<double, double>, double * > *);
    int ReachableNodesCount();
    ~Graph();
};

#endif
