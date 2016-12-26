#include "node.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    Node n(1, 2, 3), n2(4, 5, 6);

    cout << n.GetID() << " " << n.GetLat() << " " << n.GetLon() << endl;
    n.AddNeighbour(&n2, 4);

    cout << n.GetNode(0)->GetID() << endl;
    cout << (n.GetNode(1) == NULL);

    return 0;
}
