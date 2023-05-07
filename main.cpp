#include <iostream>
#include <vector>
using namespace std;
#include "memory.h"

 
// Main() function: where the execution of program begins
int main()
{
    Memory test;

    test.connectNodes(10);
    test.disconnectNodes(3);

    for(int i = 0; i < test.nodes.size(); i++){
         cout << i << "s children are: " << endl;
         for(int j = 0; j < test.nodes.at(i).children.size(); j++){
             cout << test.nodes.at(i).children.at(j) << endl;
         }
         cout << "End of this node!!" << endl << endl;
    }

    return 0;
}