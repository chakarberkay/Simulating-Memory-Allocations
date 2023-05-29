#include "garbage-collector-1.h"

CollectorV1::CollectorV1(Memory& m1): memory(m1){
};

void CollectorV1::resetStates(){
    resetInProg = true;
    for(int i = 0; i < memory.nodes.size(); i++){
        memory.nodes.at(i).currState = 0;          // reset all node states to -1
    }
    memory.globalState = 0;                         // reset global state to 0
    resetInProg = false;
}

void CollectorV1::markRoots(){
    for(int i = 0; i < memory.roots.size(); i++){
        int currentRootIndex = memory.roots.at(i);      // Get the index of the root
        memory.nodes.at(currentRootIndex).currState = memory.globalState;
    }
}

void CollectorV1::markNodes(){
    cout << "These node updated to: " << memory.globalState << ": " << endl;
    for(int i = 0; i < memory.nodes.size(); i++){
        Node curretNode = memory.nodes.at(i);
        if(curretNode.currState == memory.globalState){
            for(int j = 0; j < curretNode.children.size(); j++){
                int currentChildNodeIndex = curretNode.children.at(j);                      // We are getting the indexes of the node's children
                memory.nodes.at(currentChildNodeIndex).currState = memory.globalState;     // Find them in the main vector and update currState
                cout << currentChildNodeIndex << ", ";
            }
        }
    }
    cout << endl << endl;
}

void CollectorV1::countUsedNodes(){
    for(int i = 0; i < memory.nodes.size(); i++){
        if(memory.nodes.at(i).currState == memory.globalState)
            usedCount++;
    }
}

void CollectorV1::markingPhase(){
    oldUsedCount = 0;
    usedCount = 0;
    markRoots();

    do{
        oldUsedCount = usedCount;
        usedCount = 0;
        markNodes();
        countUsedNodes();
        cout << "old black count is " << oldUsedCount << " and normal black count is " << usedCount << endl;
    }while(usedCount > oldUsedCount);
}

void CollectorV1::collectingPahse(){
    cout << "collected nodes are: ";
    for (int i = 0; i < memory.nodes.size(); i++){
        if(memory.nodes.at(i).currState != memory.globalState){
            cout << i << ", ";
            memory.freeList.push_back(i); // In pseudocode it is not clarified where to append freed nodes
                                          // So I just append all the free nodes to an array
        }
    }
    cout << endl << endl;
}

void CollectorV1::collectGarbageNodes(){
    if(resetInProg)
        collectGarbageNodes();
    else{
        memory.globalState++;
        memory.freeList.clear();
        markingPhase();
        collectingPahse();
    }
}

