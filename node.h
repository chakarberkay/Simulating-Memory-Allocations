#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
    bool isWhite;
    vector<int> children; //Will contain the indexes of its sons
    Node(){
        isWhite = true;
    }
    void makeNodeWhite();
    void addSon(int index);
    void deleteRandomSon(int currentNodesIndex);
};