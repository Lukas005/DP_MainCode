#ifndef _NODE_HPP_
#define  _NODE_HPP_

class Node{
private:
    unsigned int id;
    double lat;
    double lon;
    Node ** adjNodes;
    int adjNodesCount;
    int maxAdjNodes;
public:
    Node(unsigned int , double, double);
    unsigned int GetID() const;
    double GetLat() const;
    double GetLon() const;
    Node * GetNode(int ) const;
    int AddNeighbour(Node * );
    ~Node();
};

static unsigned int iid = 0;
#endif
