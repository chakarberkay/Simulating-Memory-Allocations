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

void CollectorV1::markChildrenBlack(int index){
    memory.nodes.at(index).isWhite = false;
    for(int i = 0; i < memory.nodes.at(index).children.size(); i++){
        // call markchildrenBlack for each children of the current node
        int childIndex = memory.nodes.at(index).children.at(i);
        if(memory.nodes.at(childIndex).isWhite)
            markChildrenBlack(memory.nodes.at(index).children.at(i));
    }
    return;
}

void CollectorV1::markingPhase(){
    cout << "Marking phase starting " << endl << endl;
    oldBlackCount = 0;
    blackCount = 0;
    markRootsBlack();
    cout << "roots marked " << endl << endl;
    for(int i = 0; i < memory.roots.size(); i++){
        markChildrenBlack(memory.roots.at(i));
    }
    cout << "marking finished " << endl << endl;

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
    memory.freeList.clear();
    for(int i = 0; i < memory.nodes.size(); i++){
            cout << i << "s isWhite is " << memory.nodes.at(i).isWhite << endl;
        }
    collectingPahse();
}

