#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "node.hpp"
#include <map>

class Graph
{
private:
    std::map<std::pair<double, double>, Node * > Nodes;
public:
    Graph();
    int AddNode(Node * );
    Node * GetNode(double, double);
    int GetSize() const;
    ~Graph();
};

#endif
