#include <iostream>
#include <vector>
using namespace std;
#include"node.h"

class Memory{
    public:
        vector<Node> nodes;
        vector<int> roots;
        vector<int> occupiedNodes;
        vector<int> freeList;
        Memory();
        void connectNodes(int noConnected);
        void disconnectNodes(int noDisconnected);
        int globalState;
};