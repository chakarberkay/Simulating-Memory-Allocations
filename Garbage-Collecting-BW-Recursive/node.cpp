#include <iostream>
#include <vector>
using namespace std;
#include"node.h"


void Node::makeNodeWhite(){
    isWhite = 1;
}

void Node::addSon(int index){
    if (count(children.begin(), children.end(), index)) {
        std::cout << "Element found not adding it!" << endl;
        return;
    }
    children.push_back(index);
}

void Node::deleteRandomSon(int currentNodesIndex){
    int deletedIndex;
    if(children.size() == 0)        // If there is no child
        return; 
    if(children.size() == 1){       // If there is only 1 child
        deletedIndex = 0;           // Assign the first one for deletedIndex
    }
    else{                           // Else get it randomly
        deletedIndex = rand() % (children.size()-1);
    }
    cout << "Deleting the node " << children.at(deletedIndex) << " from the " << currentNodesIndex << endl;
    children.erase(children.begin() + deletedIndex);
}