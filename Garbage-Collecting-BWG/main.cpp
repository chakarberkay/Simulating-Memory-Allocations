#include <iostream>
#include <vector>
using namespace std;
#include "garbage-collector-1.h"
 
// Main() function: where the execution of program begins
int main()
{
    Memory test;
    CollectorV1 collector1(test);

    test.connectNodes(10);
    test.disconnectNodes(3);

    collector1.makeGrayWhite();
    collector1.propagateWhite();

    collector1.collectGarbageNodes();
    cout << "nasi";
    for(int i = 0; i < test.nodes.size(); i++){
        cout << i << "s color is " << test.nodes.at(i).color << endl;
    }

    for(int i = 0; i < test.freeList.size(); i++){
        cout << test.freeList.at(i) << endl;

    }
    cout << "FINISHED";

    for(int i = 0; i < test.nodes.size(); i++){
         cout << i << "s children are: " << endl;
         for(int j = 0; j < test.nodes.at(i).children.size(); j++){
             cout << test.nodes.at(i).children.at(j) << endl;
         }
         cout << "End of this node!!" << endl << endl;
    }

    return 0;
}