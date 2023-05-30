#include <iostream>
#include <vector>
using namespace std;
#include "garbage-collector-1.h"
 
int main()
{
    Memory m1;
    CollectorV1 collector1(m1);

    m1.connectNodes(10);
    m1.disconnectNodes(3);

    collector1.collectGarbageNodes();

    for(int i = 0; i < m1.occupiedNodes.size(); i++){
        int currIndex = m1.occupiedNodes.at(i);
        if (count(m1.freeList.begin(), m1.freeList.end(), currIndex))
        {
            cout << currIndex << " is still in the occupied nodes eventhough it is free. removoing it from there" << endl;
            m1.occupiedNodes.erase(m1.occupiedNodes.begin() + i);
            i--;
        }
    }
    cout << endl;

    for(int i = 0; i < m1.nodes.size(); i++){
        cout << i << "s isWhite is " << m1.nodes.at(i).isWhite << endl;
    }

    cout << endl << "Free list is: " << endl;
    for(int i = 0; i < m1.freeList.size(); i++){
        cout << m1.freeList.at(i) << ", ";
    }
    cout << endl << endl;

    for(int i = 0; i < m1.nodes.size(); i++){
         cout << i << "s children are: " << endl;
         for(int j = 0; j < m1.nodes.at(i).children.size(); j++){
             cout << m1.nodes.at(i).children.at(j) << endl;
         }
         cout << "End of this node!!" << endl << endl;
    }

    return 0;
}