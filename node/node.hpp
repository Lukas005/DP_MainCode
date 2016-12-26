#ifndef _NODE_HPP_
#define  _NODE_HPP_

#include <utility>

class Node{
private:
    unsigned int id;
    double lat;
    double lon;
    Node ** adjNodes;
    double * edgeW;
    int adjNodesCount;
    int maxAdjNodes;
public:
    Node(unsigned int , double, double);
    unsigned int GetID() const;
    std::pair<double, double> GetCoords() const;
    double GetLat() const;
    double GetLon() const;
    Node * GetNode(int ) const;
    int AddNeighbour(Node * , double );
    ~Node();
};

static unsigned int iid = 0;
#endif
