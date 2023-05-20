#include <iostream>
#include <vector>
using namespace std;
#include"node.h"


Node::Node(){
    color = white; // initial color is black;
}


void Node::makeNodeWhite(){
    color = white;
}

void Node::addSon(int index){
    if (count(children.begin(), children.end(), index)) {
        std::cout << "Element found not adding it!" << endl;
        // do some for me;
    }
    children.push_back(index);
    //occupiedNodes.push_back(index);
}

int Node::deleteRandomSon(int currentNodesIndex){
    int deletedIndex;
    if(children.size() == 0)    return -1;
    if(children.size() == 1)    deletedIndex = 0;
    else{
        deletedIndex = rand() % (children.size()-1);
    }

    cout << "Deleting the node " << children.at(deletedIndex) << " from the " << currentNodesIndex << endl;

    // for(int i = 0; i < occupiedNodes.size(); i++){
    //     if(children.at(deletedIndex) == occupiedNodes.at(i))
    //         occupiedNodes.erase(occupiedNodes.begin() + i);
    // }

    int returnIndex = children.at(deletedIndex);
    children.erase(children.begin() + deletedIndex);
    //cout << "success " << returnIndex << endl;
    return returnIndex;
}