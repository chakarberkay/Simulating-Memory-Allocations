#include <iostream>
#include <vector>
using namespace std;
#include"node.h"

void Node::addSon(int index){
    if (count(children.begin(), children.end(), index)) {
        std::cout << "Element found not adding it!" << endl;
    }
    children.push_back(index);
}

int Node::deleteRandomSon(int currentNodesIndex){
    int deletedIndex;
    if(children.size() == 0)
        return -1;
    if(children.size() == 1){
        deletedIndex = 0;
    }
    else{
        deletedIndex = rand() % (children.size()-1);
    }
    cout << "Deleting the node " << children.at(deletedIndex) << " from the " << currentNodesIndex << endl;

    int returnIndex = children.at(deletedIndex);
    children.erase(children.begin() + deletedIndex);
    //cout << "success" << endl;
    return returnIndex;
}