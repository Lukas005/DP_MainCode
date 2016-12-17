#ifndef _NODE_HPP_
#define  _NODE_HPP_

class Node{
private:
    unsigned int id;
    double x;
    double y;
    Node ** adjNodes;
    int adjNodesCount;
    int maxAdjNodes;
public:
    Node(unsigned int , double, double);
    unsigned int GetID() const;
    double GetX() const;
    double GetY() const;
    Node * GetNode(int ) const;
    int AddNeighbour(Node * );
    ~Node();
};

#endif
