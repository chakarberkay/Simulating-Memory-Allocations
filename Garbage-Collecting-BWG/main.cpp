#include <iostream>
#include <vector>
using namespace std;
#include "garbage-collector-1.h"
 
// Main() function: where the execution of program begins
int main()
{
    Memory m1;
    CollectorV1 collector1(m1);

    m1.connectNodes(10);
    m1.disconnectNodes(3);

    collector1.makeGrayWhite();
    collector1.propagateWhite();

    collector1.collectGarbageNodes();

    for(int i = 0; i < m1.nodes.size(); i++){
        cout << i << "s color is " << m1.nodes.at(i).color << endl;
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