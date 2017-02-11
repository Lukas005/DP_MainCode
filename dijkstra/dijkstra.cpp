#include <iostream>
#include "dijkstra.h"
#include <bits/stdc++.h>
#include <cfloat>

#define INF 999999


using namespace std;

enum ERes { StandDev = 0, Sum = 1};

typedef pair<double , double> PD ;
typedef multimap<double, pair<double , double> > MM;

void CDijkstra::dijkstra(Graph * g, pair<double, double> isource, map<PD, double * > & dist, int core_index)
{
    map<PD, double * >::iterator ires;
    Node * source = g->FindClosest2(isource);

    if( core_index < 0 )
    {
        cerr << "Invalid function call \"Dijkstra\": index core is not negative";
        return;
    }

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
}

void CDijkstra::dijkstra2(Graph * g , std::pair<double, double> source, std::map<std::pair<double , double>, double * > & dist, int input_index)
{
    set< pair< double, PD > > setds;
    //    vector<double> dist(g->GetSize(), 9999999)
    setds.insert(make_pair( 0, source ));
    dist[source][input_index] = 0;

    while (!setds.empty()) {
        pair< double, PD> tmp = *(setds.begin());
        setds.erase(setds.begin());

        PD u = tmp.second;
        Node * n = g->GetNode(u);
        for (int i = 0; i < n->GetEdgesCount(); i++) {
            pair<Node*, double> node_edge = n->GetNode(i);
            double dist_temp  = dist[u][input_index] + node_edge.second;
            if (dist[node_edge.first->GetCoords()][input_index] > dist_temp)
            {
                if(dist[node_edge.first->GetCoords()][input_index] != DBL_MAX)
                {
                    setds.erase(setds.find(make_pair(dist[node_edge.first->GetCoords()][input_index], node_edge.first->GetCoords())));
                }

                dist[node_edge.first->GetCoords()][input_index] = dist_temp;
                setds.insert(make_pair(dist[node_edge.first->GetCoords()][input_index], node_edge.first->GetCoords()));
            }
        }

    }
}

int CDijkstra::MeetingSchedulerSeq(Graph * g, pair<double, double> * input, int inputCount)
{
    map<pair<double, double>, double * > da, result;
    map<pair<double, double>, double * >::iterator iterDa;
    da = g->CreateDistanceArray(inputCount);

    // [0] -> standart deviation, [1] -> sum
    result = g->CreateDistanceArray(2);

    for (int i = 0; i < inputCount; i++) {
        dijkstra2(g, input[i], da, i );
    }

    for (iterDa = da.begin(); iterDa != da.end(); iterDa++)
    {
        double s = SumFunc(iterDa->second, inputCount);
        result[iterDa->first][Sum] = s;
        result[iterDa->first][StandDev] = StandartDeviation(iterDa->second, inputCount, s);
    }


/*
    for (iterDa = da.begin(); iterDa != da.end(); iterDa++) {
        cout << "Node: " << iterDa->first.first << "-" << iterDa->first.second << " ";
        for (int i = 0; i < inputCount; i++) {
            cout << da[iterDa->first][i] << " ";
        }
        cout << "sd: " << result[iterDa->first][StandDev]<< " sum: "<< result[iterDa->first][Sum] << endl;
    }
    */
    iterDa = result.begin();

    double bestSD = (iterDa->second)[StandDev], bestSum = (iterDa->second)[Sum];
    pair<double, double> bestNode = (iterDa->first);
    cout << "Old node: " << bestNode.first << "-" << bestNode.second << ":" << bestSD << " -> " << bestSum << endl;
    if (result.begin() == result.end())
        cout << "wut:" << endl ;
    for (iterDa = result.begin() ; iterDa != result.end(); iterDa++)
    {
        if(bestSum > (iterDa->second)[Sum])
        {
            bestSD = (iterDa->second)[StandDev];
            bestSum = (iterDa->second)[Sum];
            bestNode = (iterDa->first);

            cout << "new best: " << bestSum << endl;
        }
        else if (bestSum == (iterDa->second)[Sum] && bestSD > (iterDa->second)[StandDev])
        {
            bestSD = (iterDa->second)[StandDev];
            bestSum = (iterDa->second)[Sum];
            bestNode = (iterDa->first);
                cout << "new best: " << bestSum << endl;
        }
    }
    cout << "Res: " << result.size() << endl;
    cout << "Best node: " << bestNode.first << "-" << bestNode.second << ":" << bestSD << " -> " << bestSum << endl;
    Graph::RemoveDistanceArray(&da);

    return 0;
}

double CDijkstra::StandartDeviation(double * a, int size, int sum)
{
    double mean, sd = 0.0;

    mean = sum/size;

    for (int i = 0; i < size; i++) {
        sd += pow(a[i] - mean, 2);
    }

    return sqrt(sd/(size-1));
}


double CDijkstra::SumFunc(double * a , int size)
{
    double sum = 0.0;

    for (int i = 0; i < size; i++) {
        sum += a[i];
    }

    return sum;
}
