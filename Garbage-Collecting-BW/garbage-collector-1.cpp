#include "garbage-collector-1.h"

CollectorV1::CollectorV1(Memory& m1): memory(m1){
};

void CollectorV1::markNodesWhite(){
    int sizeOfAllNodes = memory.nodes.size();
    for(int i = 0; i < sizeOfAllNodes; i++){
        memory.nodes.at(i).isWhite = true;      // Whiten all nodes
    }
}

void CollectorV1::markRootsBlack(){
    for(int i = 0; i < memory.roots.size(); i++){
        int currentRootIndex = memory.roots.at(i);      // Get the index of the root
        memory.nodes.at(currentRootIndex).isWhite = false;
    }
}

void CollectorV1::markNodesBlack(){
    for(int i = 0; i < memory.nodes.size(); i++){
        Node curretNode = memory.nodes.at(i);
        if(curretNode.isWhite == false){
            for(int j = 0; j < curretNode.children.size(); j++){
                int currentChildNodeIndex = curretNode.children.at(j);      // We are getting the indexes of the node's children
                memory.nodes.at(currentChildNodeIndex).isWhite = false;     // Find them in the main vector and blacken
            }
        }
    }
}

void CollectorV1::countBlackNodes(){
    for(int i = 0; i < memory.nodes.size(); i++){
        if(memory.nodes.at(i).isWhite == false)
            blackCount++;
    }
}

void CollectorV1::markingPhase(){
    oldBlackCount = 0;
    blackCount = 0;
    markRootsBlack();

    do{
        oldBlackCount = blackCount;
        blackCount = 0;
        markNodesBlack();
        countBlackNodes();
        cout << "old black count is " << oldBlackCount << " and normal black count is " << blackCount << endl;
    }while(blackCount > oldBlackCount);
    cout << endl;
}

void CollectorV1::collectingPahse(){
    cout << "collected nodes are: ";
    for (int i = 0; i < memory.nodes.size(); i++){
        if(memory.nodes.at(i).isWhite == true){
            cout << i << ", ";
            memory.freeList.push_back(i); // In pseudocode it is not clarified where to append freed nodes
                                          // So I just append all the free nodes to an array
        }
        else{
            memory.nodes.at(i).isWhite = true;
        }
    }
    cout << endl << endl;
}

void CollectorV1::collectGarbageNodes(){
    markingPhase();
    collectingPahse();
}

