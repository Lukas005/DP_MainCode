#include "node.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    Node n(1, 2, 3), n2(4, 5, 6);

    cout << n.GetID() << " " << n.GetCoords().first << " " << n.GetCoords().second << endl;
    n.AddNeighbour(&n2, 4);

    cout << n.GetNode(0).first->GetCoords().second << endl;
    cout << (n.GetNode(1).first == NULL);

    return 0;
}
