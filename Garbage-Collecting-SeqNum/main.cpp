#include <iostream>
#include <vector>
using namespace std;
#include "garbage-collector-1.h"
 
// Main() function: where the execution of program begins
int main()
{
    Memory test;
    CollectorV1 collector1(test);
    for(int i = 0; i < 3; i++){
        test.connectNodes(10);
        test.disconnectNodes(2);

        collector1.collectGarbageNodes();

        for(int i = 0; i < test.occupiedNodes.size(); i++){
            int currIndex = test.occupiedNodes.at(i);
            if (count(test.freeList.begin(), test.freeList.end(), currIndex))
            {
                cout << currIndex << " is still in the occupied nodes eventhough it is free. removoing it from there" << endl;
                test.occupiedNodes.erase(test.occupiedNodes.begin() + i);
                i--;
            }
        }
        cout << endl;

        for(int i = 0; i < test.nodes.size(); i++){
            cout << i << "s current state is " << test.nodes.at(i).currState << endl;
        }

        cout << "Free list is: " << endl;
        for(int i = 0; i < test.freeList.size(); i++){
            cout << test.freeList.at(i) << ", ";

        }
        cout << endl << endl;

        for(int i = 0; i < test.nodes.size(); i++){
            cout << i << "s children are: " << endl;
            for(int j = 0; j < test.nodes.at(i).children.size(); j++){
                cout << test.nodes.at(i).children.at(j) << endl;
            }
            cout << "End of this node!!" << endl << endl;
        }
    }
    return 0;
}