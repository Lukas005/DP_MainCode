#ifndef _NODE_HPP_
#define  _NODE_HPP_

#include <utility>

class Node{
private:
    double lat;
    double lon;
    Node ** adjNodes;
    double * edgeW;
    int adjNodesCount;
    int maxAdjNodes;
    bool marked;
public:
    Node( double, double);
    std::pair<double, double> GetCoords() const;
    double GetLat() const;
    double GetLon() const;
    int GetEdges() const;
    std::pair<Node *, double> GetNode(int ) const;
    void Mark(int * const );
    int AddNeighbour(Node * , double );
    ~Node();
};

#endif
