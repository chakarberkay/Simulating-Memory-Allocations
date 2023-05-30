#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
#include"memory.h"


Memory::Memory(){
    nodes = vector<Node>(30);

    nodes.at(0).color = black;
    nodes.at(1).color = black;
    nodes.at(2).color = black;
    
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
        int nodeIndex = occupiedNodes.at(rand() % (occupiedNodes.size()-1));
        do{
            newSonIndex = rand() % (nodes.size() - 1);
        }while(newSonIndex == nodeIndex);
        nodes.at(nodeIndex).addSon(newSonIndex);
        if (std::find(occupiedNodes.begin(), occupiedNodes.end(), newSonIndex) == occupiedNodes.end()) {
            occupiedNodes.push_back(newSonIndex);
            cout <<  newSonIndex << " wasn't occupied. added to the list!" << endl;
        }
        nodes.at(newSonIndex).color = black; // blacken the used nodes

        cout << newSonIndex << " added as a child to " << nodeIndex << endl;
    }
    cout << endl;
}

void Memory::disconnectNodes(int noDisconnected){
    if(noDisconnected > occupiedNodes.size()){
        noDisconnected = occupiedNodes.size();
    }
    for(int i=0; i < noDisconnected; i++){
        int randomIndex = rand() % (occupiedNodes.size()-1);
        int deletedNodeIndex = nodes.at(occupiedNodes.at(randomIndex)).deleteRandomSon(occupiedNodes.at(randomIndex));
        if(deletedNodeIndex != -1){
            nodes.at(deletedNodeIndex).color = gray;   // Make old disconnected node gray as it is suspected
                                                        // For a garbage node now
            cout << deletedNodeIndex << " colored as gray!" << endl << endl;
        }
        else{
            cout << "Couldn't delete try again " << endl << endl;
            i--;
        }
            
    }
    cout << endl;
}