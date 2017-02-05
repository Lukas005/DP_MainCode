#include <iostream>
#include "dijkstra.h"

#define INF 999999

using namespace std;

typedef pair<double , double> PD ;
typedef multimap<double, pair<double , double> > MM;

map<pair<double, double>, double * > CDijkstra::dijkstra(Graph * g, pair<double, double> isource, int distances_count, int core_index)
{
    map<PD, double * > dist;
    map<PD, double * >::iterator ires;
    Node * source = g->FindClosest2(isource);
    if (distances_count < 1)
    {
        cerr << "Invalid function call \"Dijkstra\": size of dist array is not natural number";
        return dist;
    }
    if( core_index < 0 )
    {
        cerr << "Invalid function call \"Dijkstra\": index core is not negative";
        return dist;
    }

    //TODO move this outside -> init before calling the parallel part
    dist = g->CreateDistanceArray(distances_count);

    /**** initializing distances ****/
    for (ires = dist.begin(); ires != dist.end(); ires++) {
            (ires->second)[core_index] = INF;
    }
    ires--;
    ires->second [0]= 5;
    dist[source->GetCoords()][core_index] = 0;

    MM pq; // priority queue
    MM::iterator ipq;

    pq.insert(MM::value_type(0, source->GetCoords()));

    while(!pq.empty())
    {
        ipq = pq.begin();
        PD u = (*ipq).second;
        double weight_u = (*ipq).first;

        if(weight_u <= dist[u][core_index])
        {
            Node * n = g->GetNode(u);
            for(int i = 0; i < n->GetEdgesCount(); i++ )
            {
                pair<Node*, double> node_edge = n->GetNode(i);
                double nweight = weight_u + node_edge.second;
                if(nweight < dist[(node_edge.first)->GetCoords()][core_index])
                {
                    dist[(node_edge.first)->GetCoords()][core_index] = nweight;
                    pq.insert(MM::value_type(nweight, (node_edge.first)->GetCoords()));
                }
            }
        }
        pq.erase(ipq);
    }
    return dist;
}
