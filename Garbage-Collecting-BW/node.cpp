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
    }
    children.push_back(index);
    //occupiedNodes.push_back(index);
}

void Node::deleteRandomSon(int currentNodesIndex){
    int deletedIndex;
    if(children.size() == 0)
        return;
    if(children.size() == 1){
        deletedIndex = 0;
    }
    else{
        deletedIndex = rand() % (children.size()-1);
    }
    cout << "Deleting the node " << children.at(deletedIndex) << " from the " << currentNodesIndex << endl;

    // for(int i = 0; i < occupiedNodes.size(); i++){
    //     if(children.at(deletedIndex) == occupiedNodes.at(i))
    //         occupiedNodes.erase(occupiedNodes.begin() + i);
    // }

    children.erase(children.begin() + deletedIndex);
    cout << "success" << endl;
}