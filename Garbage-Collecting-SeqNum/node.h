#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
    int currState;
    vector<int> children; //Will contain the indexes of its sons
    void makeNodeWhite();
    void addSon(int index);
    int deleteRandomSon(int currentNodesIndex);
};