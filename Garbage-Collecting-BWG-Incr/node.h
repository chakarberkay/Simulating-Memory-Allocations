#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum color {black, gray, white};

class Node {
public:
    color color; // 0 = black  1 = gray  2 = white
    vector<int> children; //Will contain the indexes of its sons
    void makeNodeWhite();
    void addSon(int index);
    int deleteRandomSon(int currentNodesIndex);
    Node();
};