#ifndef __H_DIJSKTRA__
#define __H_DIJSKTRA__
#include "graph.h"

class CDijkstra{
public:
    static std::map<std::pair<double, double>, double * > dijkstra(Graph *, std::pair<double, double>, int, int);
};

#endif
