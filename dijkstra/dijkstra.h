#ifndef __H_DIJSKTRA__
#define __H_DIJSKTRA__
#include "graph.h"

class CDijkstra{

private:
    static void dijkstra(Graph *, std::pair<double, double>, std::map<std::pair<double , double>, double * > &, int);
    static void SeqentialDijkstra(Graph *, std::pair<double, double>, std::map<std::pair<double , double>, double * > &, int);
    static double StandartDeviation(double * , int , int);
    static double SumFunc(double *, int );

public:
    static int MeetingSchedulerSeq(Graph *, std::pair<double, double> *, int);
};

#endif
