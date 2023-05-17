#include "garbage-collector-1.h"

CollectorV1::CollectorV1(Memory& m1): memory(m1){
    memory = m1;
};

void CollectorV1::propagateWhite(){
    bool changedColor = false;
    do{
        changedColor = false;
        for(int i = 0; i < memory.occupiedNodes.size(); i++){
            int currentNode = memory.occupiedNodes.at(i);
            if(memory.nodes.at(currentNode).color > black){
                vector<int> children = memory.nodes.at(currentNode).children;
                for(int j = 0; j < children.size(); j++){
                    int childNode = children.at(j);
                    if(memory.nodes.at(childNode).color == black){
                        memory.nodes.at(childNode).color = white;
                        changedColor = true;
                    }
                }
            }
        }
    }while(changedColor == true);
    
}

void CollectorV1::makeGrayWhite(){
    cout << memory.occupiedNodes.size() << endl;
    vector<int> occupiedNodes = memory.occupiedNodes;
    for(int i = 0; i < occupiedNodes.size(); i++){
        cout << " test " << occupiedNodes.at(i) << endl;
        int currentIndex = occupiedNodes.at(i);
        if(memory.nodes.at(currentIndex).color == gray){
            cout << "degismek uzere " << endl;
            memory.nodes.at(currentIndex).color = white;
        }
        cout << "asd " << i << endl;
    }
    cout <<"nasiasdal";
}

void CollectorV1::countBlackNodes(){
    for(int i = 0; i < memory.nodes.size(); i++){
        if(memory.nodes.at(i).color <= gray)
            blackCount++;
    }
}

void CollectorV1::markNodesBlack(){
    for(int i = 0; i < memory.occupiedNodes.size(); i++){
        Node curretNode = memory.nodes.at(memory.occupiedNodes.at(i));
        if(curretNode.color <= gray){
            for(int j = 0; j < curretNode.children.size(); j++){
                int currentChildNodeIndex = curretNode.children.at(j);      // We are getting the indexes of the node's children
                if (memory.nodes.at(currentChildNodeIndex).color == white)     // Find them in the main vector and blacken
                    memory.nodes.at(currentChildNodeIndex).color = black;
            }
        }
    }
}

void CollectorV1::newMarkingPhase(){
    oldBlackCount = 0;
    blackCount = 0;
    do{
        cout << "old black count is " << oldBlackCount << " and normal black count is " << blackCount << endl;
        oldBlackCount = blackCount;
        blackCount = 0;
        markNodesBlack();
        countBlackNodes();
    }while(blackCount > oldBlackCount);
}

void CollectorV1::collectingPahse(){
    for (int i = 0; i < memory.nodes.size(); i++){
        if(memory.nodes.at(i).color == white){
            cout << i << " is garbage and getting collected!";
            memory.freeList.push_back(i); // In pseudocode it is not clarified where to append freed nodes
                                          // So I just append all the free nodes to an array
        }
    }
}

void CollectorV1::collectGarbageNodes(){
    newMarkingPhase();
    collectingPahse();
}
