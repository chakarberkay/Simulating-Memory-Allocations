#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
#include"memory.h"


Memory::Memory(){
    nodes = vector<Node>(30);

    // Define root nodes
    roots.push_back(0);
    roots.push_back(1);
    roots.push_back(2);

    // Add root nodes to occupied nodes
    occupiedNodes.push_back(0);
    occupiedNodes.push_back(1);
    occupiedNodes.push_back(2);
}

void Memory::connectNodes(int noConnected){
    for (int i = 0; i < noConnected; i++){
        int newChildIndex;
        int nodeIndex = occupiedNodes.at(rand() % (occupiedNodes.size()-1));       // Get parent node's index
        do{
            newChildIndex = rand() % (nodes.size() - 1);                      // Get child node's index
        }while(newChildIndex == nodeIndex);                                   // Parent node and child node should not be same
        
        if (std::find(occupiedNodes.begin(), occupiedNodes.end(), newChildIndex) == occupiedNodes.end()) {
            occupiedNodes.push_back(newChildIndex);
            cout <<  newChildIndex << " wasn't occupied. added to the list!" << endl;
        }
        nodes.at(nodeIndex).addSon(newChildIndex);

        cout << newChildIndex << " added as a child to " << nodeIndex << endl;
    }
    cout << endl;
}

void Memory::disconnectNodes(int noDisconnected){
    if(noDisconnected > occupiedNodes.size()){                              // If number of nodes to disconnect is bigger than occupied nodes
        noDisconnected = occupiedNodes.size();     
    }

    for(int i=0; i < noDisconnected; i++){
        int randomIndex = rand() % (occupiedNodes.size()-1);                // Get from which node it will be disconnected
        nodes.at(occupiedNodes.at(randomIndex)).deleteRandomSon(occupiedNodes.at(randomIndex));
    }
    cout << endl;
}
