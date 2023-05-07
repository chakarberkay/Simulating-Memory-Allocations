#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum Hue {White, Black};

class Node {
public:
    Hue color;
    vector<int> children; //Will contain the indexes of its sons
    Node(){
        color = White;
    }
    void makeNodeWhite();
    void addSon(int index);
    void deleteRandomSon(int currentNodesIndex);
};