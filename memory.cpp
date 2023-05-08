#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
#include"memory.h"


Memory::Memory(){
    nodes = vector<Node>(30);
    // iota(freeList.begin(), freeList.end(), 0);
    roots.push_back(0);
    roots.push_back(1);
    roots.push_back(2);
    occupiedNodes.push_back(0);
    occupiedNodes.push_back(1);
    occupiedNodes.push_back(2);
}

void Memory::connectNodes(int noConnected){
    for (int i = 0; i < noConnected; i++){
        int newSonIndex;
        int nodeIndex = occupiedNodes.at(i % (occupiedNodes.size()-1));
        do{
            newSonIndex = rand() % (nodes.size() - 1);
            // newSonIndex = freeList.back();
            //freeList.pop_back();
        }while(newSonIndex == nodeIndex);
        nodes.at(nodeIndex).addSon(newSonIndex);
        occupiedNodes.push_back(newSonIndex);

        cout << newSonIndex << " added as a child to " << occupiedNodes.at(i % (occupiedNodes.size()-1)) << endl;
    }
}

void Memory::disconnectNodes(int noDisconnected){
    if(noDisconnected > occupiedNodes.size()){
        noDisconnected = occupiedNodes.size();
    }
    for(int i=0; i < noDisconnected; i++){
        int randomIndex = rand() % (occupiedNodes.size()-1);
        nodes.at(occupiedNodes.at(randomIndex)).deleteRandomSon(occupiedNodes.at(randomIndex));
    }
}
